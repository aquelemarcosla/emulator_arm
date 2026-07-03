#include "builderDPI_Shift.h"
#include "stdint.h"
#include "encode/buildersEncode/buildersEncode.h"

#define MOV_BITS(data, mask, shift) (((uint32_t)(data) & (mask)) << (shift))

// LSL Rd, Rn, #imm
uint32_t builderLSL(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint8_t immr;
    uint8_t imms;
    uint8_t rd;
    uint8_t rn;
    uint8_t shift;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    shift = find_immediate(saveptr);

    immr = (64 - shift) % 64;
    imms = 63 - shift;

    instructionExit |= MOV_BITS(value, 0x3FF, 22);
    instructionExit |= MOV_BITS(immr, 0x3F, 16);
    instructionExit |= MOV_BITS(imms, 0x3F, 10);
    instructionExit |= MOV_BITS(rn,   0x1F,  5);
    instructionExit |= MOV_BITS(rd,   0x1F,  0);

    return instructionExit;
}

// LSR Rd, Rn, #imm
uint32_t builderLSR(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint8_t immr;
    uint8_t imms;
    uint8_t rd;
    uint8_t rn;
    uint8_t shift;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    shift = find_immediate(saveptr);

    immr = shift;
    imms = 63;

    instructionExit |= MOV_BITS(value, 0x3FF, 22);
    instructionExit |= MOV_BITS(immr, 0x3F, 16);
    instructionExit |= MOV_BITS(imms, 0x3F, 10);
    instructionExit |= MOV_BITS(rn,   0x1F,  5);
    instructionExit |= MOV_BITS(rd,   0x1F,  0);

    return instructionExit;
}
