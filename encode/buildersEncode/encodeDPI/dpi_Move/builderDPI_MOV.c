#include "builderDPI_MOV.h"
#include "stdint.h"
#include "encode/buildersEncode/buildersEncode.h"

#define MOVE_BITS(data, mask, shift) (((uint32_t)data & mask) << (shift))

// MOVZ Rd, #imm
uint32_t builderMOVZ(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint16_t imm;
    uint8_t rd;

    rd = find_register(saveptr);
    imm = find_immediate(saveptr);

    instructionExit |= MOVE_BITS(value, 0xFFF, 21);
    instructionExit |= MOVE_BITS(imm, 0xFFFF, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);

    return instructionExit;
}

// MOVN Rd, #imm
uint32_t builderMOVN(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint16_t imm;
    uint8_t rd;

    rd = find_register(saveptr);
    imm = find_immediate(saveptr);

    instructionExit |= MOVE_BITS(value, 0xFFF, 21);
    instructionExit |= MOVE_BITS(imm, 0xFFFF, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);

    return instructionExit;
}