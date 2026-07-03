#include "builderB.h"
#include "stdint.h"
#include "string.h"
#include "encode/opcode_table/opcode_table.h"
#include "cpu/labels_table/labels_table.h"
#include "cpu/program_table/program_table.h"
#define MOVE_BITS(data, mask, shift) (((uint32_t)(data) & (mask)) << (shift))

// "B label(imm26)"
uint32_t builderB(uint32_t value, char **saveptr) {
    uint64_t currentPC = getLastPC();
    uint64_t targetLabel;
    int64_t targetOffset;
    uint32_t instructionExit = 0;

    // Get the label.
    char *token = strtok_r(NULL, " \t\r\n", saveptr);
    if (token == NULL) return 0;

    // Calculate relative PC.
    targetLabel = getLabelAddress(token);
    targetOffset = (targetLabel - currentPC) / 4;

    instructionExit |= MOVE_BITS(value, 0x3F, 26);
    instructionExit |= MOVE_BITS(targetOffset, 0x3FFFFFF, 0);

    return instructionExit;
}

// "BL label(imm26)"
uint32_t builderBL(uint32_t value, char **saveptr) {
    int64_t currentPC = getLastPC();
    int64_t targetLabel;
    int64_t targetOffset;
    uint32_t instructionExit = 0;

    // Get the label.
    char *token = strtok_r(NULL, " \t\r\n", saveptr);
    if (token == NULL) return 0;

    // Calculate relative PC.
    targetLabel = getLabelAddress(token);
    targetOffset = (targetLabel - currentPC) / 4;

    instructionExit |= MOVE_BITS(value, 0x3F, 26);
    instructionExit |= MOVE_BITS(targetOffset, 0x3FFFFFF, 0);

    return instructionExit;
}

// "RET (Returns the return address in x30)"
uint32_t builderRET(uint32_t value, char **saveptr) {
    uint32_t instructionExit = value;

    return instructionExit;
}

// "BEQ label(imm19)"
uint32_t builderBEQ(uint32_t value, char **saveptr) {
    int64_t currentPC = getLastPC();
    int64_t targetLabel;
    int64_t targetOffset;
    uint32_t instructionExit = 0;

    // Get the label.
    char *token = strtok_r(NULL, " \t\r\n", saveptr);
    if (token == NULL) return 0;

    // Calculate relative PC.
    targetLabel = getLabelAddress(token);
    targetOffset = (targetLabel - currentPC) / 4;

    instructionExit |= MOVE_BITS(value, 0xFF, 24);
    instructionExit |= MOVE_BITS(targetOffset, 0x7FFFF, 5);

    // suffix
    instructionExit |= MOVE_BITS(0x0, 0x1, 4);

    // cond
    instructionExit |= MOVE_BITS(0x0, 0xF, 0);

    return instructionExit;
}

// "BNE label(imm19)"
uint32_t builderBNE(uint32_t value, char **saveptr) {
    int64_t currentPC = getLastPC();
    int64_t targetLabel;
    int64_t targetOffset;
    uint32_t instructionExit = 0;

    // Get the label.
    char *token = strtok_r(NULL, " \t\r\n", saveptr);
    if (token == NULL) return 0;

    // Calculate relative PC.
    targetLabel = getLabelAddress(token);
    targetOffset = (targetLabel - currentPC) / 4;

    instructionExit |= MOVE_BITS(value, 0xFF, 24);
    instructionExit |= MOVE_BITS(targetOffset, 0x7FFFF, 5);

    // suffix
    instructionExit |= MOVE_BITS(0x0, 0x1, 4);

    // cond
    instructionExit |= MOVE_BITS(0x1, 0x1, 0);

    return instructionExit;
}
