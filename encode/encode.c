#include "stdint.h"
#include "encode.h"
#include "opcode_table/opcode_table.h"

uint32_t encode(const char *instruction) {
    if (instruction == NULL){
        return 0;
    }

    uint32_t instruction_decode = 0;   

    char *saveptr;
    const char *delimitadores = " ,";

    char buffer[128];

    // instruction para buffer.
    // Null no final.
    strncpy(buffer, instruction, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    // token para o opcode inicial.
    char *token = strtok_r(buffer, delimitadores, &saveptr);

    // Mnemonico e valor inicial.
    char *mnemonic;
    char *value;

    for (int i = 0; i < opcode_table_size; i++) {
        if (strcmp(token, opcode_table[i].mnemonic) == 0) {
            return mnemonic = opcode_table[i].mnemonic;
        }
    }

    return 0;
}