#include "builderDPI_A.h"

#include "stdint.h"
#include "encode/buildersEncode/buildersEncode.h"

#define MOVE_BITS(data, mask, shift) (((uint32_t)(data) & (mask)) << (shift))

// ADDI Rd, Rn, #imm
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

// SUBI Rd, Rn, #imm
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

// (CMP Rn, #imm) -> SUBS XZR, Rn, #imm
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