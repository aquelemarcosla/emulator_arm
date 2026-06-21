#include "stdint.h"
#include "encode.h"
#include "opcode_table/opcode_table.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

uint32_t encode(const char *instructionText) {
    if (instructionText == NULL){
        return 0;
    } else if (strlen(instructionText) == 0){
        return 0;
    }

    uint32_t instruction_decode = 0;   

    char *saveptr;
    const char *delimiters = " ,\t\r\n";

    char buffer[65];

    // Copy instruction into the buffer.
    // Null-terminate the buffer.
    strncpy(buffer, instructionText, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    // Tokenize the initial opcode.
    char *token = strtok_r(buffer, delimiters, &saveptr);

    // Walk through the table and execute the builder.
    for (int i = 0; i < opcode_table_size; i++) {
        if (strcmp(token, opcode_table[i].mnemonic) == 0) {
            return opcode_table[i].builder(opcode_table[i].value, &saveptr);
        }
    }

    fprintf(stderr, "Error: encoding failed\n");
    exit(EXIT_FAILURE);
}
