#include "buildersEncode.h"

#include <stdint.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cpu/registers_table/registers_table.h"

uint32_t find_immediate(char **saveptr) {
    char *token = strtok_r(NULL, " ,[]\t\r\n", saveptr);
    char *endptr;
    int base = 10;
    char *tokenContinue;
    long value;

    if (token == NULL || token[0] != '#') {
        return 0;
    }

    tokenContinue = token + 1;

    if (tokenContinue[0] == '+' || tokenContinue[0] == '-') {
        tokenContinue++;
    }

    if (tokenContinue[0] == '0' && (tokenContinue[1] == 'x' || tokenContinue[1] == 'X')) {
        base = 16;
    }

    errno = 0;
    value = strtol(token + 1, &endptr, base);

    if (errno == ERANGE || endptr == token + 1 || *endptr != '\0') {
        return 0;
    }

    if (value < -32768L || value > 65535L) {
        return 0;
    }

    return (uint32_t)(value & 0xFFFF);
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
