#include "builderDPI_A.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "stdint.h"
#include "cpu/registers_table/registers_table.h"

#define MOVE_BITS(data, mask, shift) (((uint32_t)(data) & (mask)) << (shift))

// ADDI Xd, Xn, #imm
uint32_t builderADDI(uint32_t value, char **saveptr) {
    uint8_t rn;
    uint8_t rd;
    uint16_t imm12;
    uint32_t instructionExit = 0;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    imm12 = find_immediate(saveptr);

    instructionExit |= MOVE_BITS(value, 0x3FF, 22);
    instructionExit |= MOVE_BITS(imm12, 0xFFF, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);

    return instructionExit;
}

// SUBI X0, X1, #5
uint32_t builderSUBI(uint32_t value, char **saveptr) {
    uint8_t rn;
    uint8_t rd;
    uint16_t imm12;
    uint32_t instructionExit = 0;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    imm12 = find_immediate(saveptr);

    instructionExit |= MOVE_BITS(value, 0x3FF, 22);
    instructionExit |= MOVE_BITS(imm12, 0xFFF, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);


    return instructionExit;
}

// (CMP X1, #1) -> SUBS ZXR, X1, #1
uint32_t builderCMPI(uint32_t value, char **saveptr) {
    uint8_t rn;
    uint8_t rd = 0x1F;
    uint16_t imm12;
    uint32_t instructionExit = 0;

    rn = find_register(saveptr);
    imm12 = find_immediate(saveptr);

    instructionExit |= MOVE_BITS(value, 0x3FF, 22);
    instructionExit |= MOVE_BITS(imm12, 0xFFF, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= rd;

    return instructionExit;
}

uint8_t find_register(char **saveptr) {
    char *token = strtok_r(NULL, " ,\t\r\n", saveptr);

    if (token == NULL) {
        fprintf(stderr, "Erro: Registrador invalido.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < registers_table_size; i++) {
        if (strcmp(token, registers_table[i].mnemonic) == 0) {
            return registers_table[i].value;
        }
    }
    
    fprintf(stderr, "Erro: Registrador invalido.\n");
    exit(EXIT_FAILURE);
}

uint16_t find_immediate(char **saveptr) {
    char *token = strtok_r(NULL, " ,\t\r\n", saveptr);
    char *endptr;
    int base = 10;
    char *tokenContinue;

    if (token == NULL || token[0] != '#') {
        fprintf(stderr, "Erro: Imediato invalido.\n");
        exit(EXIT_FAILURE);
    }

    tokenContinue = token + 1;

    if (tokenContinue[0] && (tokenContinue[1] == 'x' || tokenContinue[1] == 'X')) {
        base = 16;
        tokenContinue += 2;
    }

    if (tokenContinue == NULL) {
        fprintf(stderr, "Erro: Imediato invalido.\n");
        exit(EXIT_FAILURE);
    }

    long value = strtol(tokenContinue, &endptr, base);
    
    if (endptr == tokenContinue || *endptr != '\0' || value < 0 || value > 0xFFFF) {
        fprintf(stderr, "Erro: Imediato invalido.\n");
        exit(EXIT_FAILURE);
    }
    
    return (uint16_t)value;
}
