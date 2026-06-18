#include "builderB.h"
#include "stdint.h"
#include "string.h"
#include "encode/opcode_table/opcode_table.h"
#include "cpu/labels_table/labels_table.h"
#define MOVE_BITS(data, mask, shift) (((uint32_t)(data) & (mask)) << (shift))

// "B label(imm26)"
uint32_t builderB(uint32_t value, char **saveptr) {
    uint32_t instructionExit = MOVE_BITS(value, 0x3F, 26);

    char *token = strtok_r(NULL, " \t\r\n", saveptr);
    if (token == NULL) return 0;

    instructionExit |= MOVE_BITS(getLabelAddress(token), 0x3FFFFFF, 0);
    return instructionExit;

}

// "BL label(imm26)"
uint32_t builderBL(uint32_t value, char **saveptr) {
    uint32_t instructionExit = MOVE_BITS(value, 0x3F, 26);

    char *token = strtok_r(NULL, " \t\r\n", saveptr);
    if (token == NULL) return 0;

    instructionExit |= MOVE_BITS(getLabelAddress(token), 0x3FFFFFF, 0);
    return instructionExit;
}

// "RET (Returns the return address in x30)"
uint32_t builderRET(uint32_t value, char **saveptr) {
    uint32_t instructionExit = value;

    return instructionExit;
}

// "BEQ label(imm19)"
uint32_t builderBEQ(uint32_t value, char **saveptr) {
    uint32_t instructionExit = MOVE_BITS(value, 0xFF, 24);
    uint64_t imm19;

    char *token = strtok_r(NULL, " ,\t\r\n", saveptr);
    if (token == NULL) return 0;

    imm19 = MOVE_BITS(getLabelAddress(token), 0x7FFFF, 5);
    instructionExit |= imm19;

    return instructionExit;
}

// "BNE label(imm19)"
uint32_t builderBNE(uint32_t value, char **saveptr) {
    uint32_t instructionExit = MOVE_BITS(value, 0xFF, 24);
    uint64_t imm19;
    uint8_t cond;

    char *token = strtok_r(NULL, " ,\t\r\n", saveptr);
    if (token == NULL) return 0;

    imm19 = MOVE_BITS(getLabelAddress(token), 0x7FFFF, 5);
    cond = 1;
    instructionExit |= imm19;
    instructionExit |= MOVE_BITS(cond, 0xF, 0);

    return instructionExit;
}
