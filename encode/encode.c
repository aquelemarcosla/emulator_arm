#include "stdint.h"
#include "encode.h"
#include "opcode_table/opcode_table.h"

uint32_t encode(const char *instruction) {
    if (instruction == NULL){
        return 0;
    } else if (strlen(instruction) == 0){
        return 0;
    }

    uint32_t instruction_decode = 0;   

    char *saveptr;
    const char *delimitadores = " ,";

    char buffer[65];

    // instruction para buffer.
    // null no final.
    strncpy(buffer, instruction, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    // token para o opcode inicial.
    char *token = strtok_r(buffer, delimitadores, &saveptr);

    // Percorre e executa builder.
    for (int i = 0; i < opcode_table_size; i++) {
        if (strcmp(token, opcode_table[i].mnemonic) == 0) {
            return opcode_table[i].builder(buffer, &saveptr);
        }
    }

    return 0;
}