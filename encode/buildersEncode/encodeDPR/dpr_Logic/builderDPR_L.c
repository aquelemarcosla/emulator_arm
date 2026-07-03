#include "builderDPR_L.h"
#include "stdint.h"
#include "encode/buildersEncode/buildersEncode.h"

#define MOVE_BITS(data, mask, shift) (((uint32_t)(data) & (mask)) << (shift))

// AND Rd, Rn, Rm
uint32_t builderAND(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint8_t imm = 0;
    uint8_t rd;
    uint8_t rn;
    uint8_t rm;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    rm = find_register(saveptr);

    instructionExit |= MOVE_BITS(value, 0x7FF, 21);
    instructionExit |= MOVE_BITS(rm, 0x1F, 16);
    instructionExit |= MOVE_BITS(imm, 0x1F, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);

    return instructionExit;
}

// ORR Rd, Rn, Rm
uint32_t builderORR(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint8_t imm = 0;
    uint8_t rd;
    uint8_t rn;
    uint8_t rm;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    rm = find_register(saveptr);

    instructionExit |= MOVE_BITS(value, 0x7FF, 21);
    instructionExit |= MOVE_BITS(rm, 0x1F, 16);
    instructionExit |= MOVE_BITS(imm, 0x1F, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);

    return instructionExit;
}

// EOR Rd, Rn, Rm
uint32_t builderEOR(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint8_t imm = 0;
    uint8_t rd;
    uint8_t rn;
    uint8_t rm;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    rm = find_register(saveptr);

    instructionExit |= MOVE_BITS(value, 0x7FF, 21);
    instructionExit |= MOVE_BITS(rm, 0x1F, 16);
    instructionExit |= MOVE_BITS(imm, 0x1F, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);

    return instructionExit;
}