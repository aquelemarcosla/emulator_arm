#include "builderB.h"
#include "stdint.h"
#include "string.h"
#include "encode/opcode_table/opcode_table.h"
#include "cpu/labels_table/labels_table.h"
#define MOVE_BITS(data, shift) ((data) << (shift))

uint32_t instructionExit;

// "B label(imm26)"
uint32_t builderB(uint32_t value, char **saveptr) {
    instructionExit = MOVE_BITS(value, 26);

    char *token = strtok_r(NULL, " \t\r\n", saveptr);
    if (token == NULL) return 0;

    instructionExit |= getLabelAddress(token);
    return instructionExit;

}

// "BL label(imm26)"
uint32_t builderBL(uint32_t value, char **saveptr) {
    instructionExit = MOVE_BITS(value, 26);

    char *token = strtok_r(NULL, " \t\r\n", saveptr);
    if (token == NULL) return 0;

    instructionExit |= getLabelAddress(token);
    return instructionExit;
}

// "RET (Retorna endereço de retorno em x30)"
uint32_t builderRET(uint32_t value, char **saveptr) {
    instructionExit = value;

    return instructionExit;
}

// "BEQ label(imm19)"
uint32_t builderBEQ(uint32_t value, char **saveptr) {
    instructionExit = MOVE_BITS(value, 24);
    uint64_t imm19;

    char *token = strtok_r(NULL, " ,\t\r\n", saveptr);
    if (token == NULL) return 0;

    imm19 = MOVE_BITS(getLabelAddress(token), 5);
    instructionExit |= imm19;

    return instructionExit;
}

// "BNE label(imm19)"
uint32_t builderBNE(uint32_t value, char **saveptr) {
    instructionExit = MOVE_BITS(value, 24);
    uint64_t imm19;
    uint8_t cond;

    char *token = strtok_r(NULL, " ,\t\r\n", saveptr);
    if (token == NULL) return 0;

    imm19 = MOVE_BITS(getLabelAddress(token), 5);
    cond = 1;
    instructionExit |= imm19;
    instructionExit |= cond;

    return instructionExit;
}
