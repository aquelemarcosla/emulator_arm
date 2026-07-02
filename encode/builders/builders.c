#include "builders.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cpu/registers_table/registers_table.h"

uint32_t find_immediate(char **saveptr) {
    char *token = strtok_r(NULL, " ,[]\t\r\n", saveptr);
    char *endptr;
    int base = 10;
    char *tokenContinue;

    if (token == NULL || token[0] != '#') {
        fprintf(stderr, "Error: invalid immediate value\n");
        exit(EXIT_FAILURE);
    }

    // token[0] --> token[1]
    tokenContinue = token + 1;

    // Verify '0x0'(base 16) or '#(int)'(base 10)
    if (tokenContinue[0] && (tokenContinue[1] == 'x' || tokenContinue[1] == 'X')) {
        base = 16;
        tokenContinue += 2;
    }

    if (tokenContinue == NULL) {
        fprintf(stderr, "Error: invalid immediate value\n");
        exit(EXIT_FAILURE);
    }

    // Get value
    long value = strtol(tokenContinue, &endptr, base);

    // Final verify
    if (endptr == tokenContinue || *endptr != '\0' || value < 0 || value > 0xFFFF) {
        fprintf(stderr, "Error: invalid immediate value\n");
        exit(EXIT_FAILURE);
    }

    return (uint32_t)value;
}

uint8_t find_register(char **saveptr) {
    char *token = strtok_r(NULL, " ,[]\t\r\n", saveptr);

    if (token == NULL) {
        fprintf(stderr, "Error: invalid register\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < registers_table_size; i++) {
        if (strcmp(token, registers_table[i].mnemonic) == 0) {
            return registers_table[i].value;
        }
    }

    fprintf(stderr, "Error: invalid register\n");
    exit(EXIT_FAILURE);
}

