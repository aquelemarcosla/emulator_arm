#include "builderDPI_Shift.h"
#include "stdint.h"
#include "encode/builders/builders.h"

#define MOV_BITS(data, mask, shift) (((uint32_t)(data) & (mask)) << (shift))


// TODO: Realizar refatoração.
// (LSL / LSR) X0, X1, #100
uint32_t builderUBFM(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint8_t immr;
    uint8_t imms;
    uint8_t rd;
    uint8_t rn;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    immr = find_immediate(saveptr);
    imms = immr;

    instructionExit |= MOV_BITS(value, 0xFFF, 22);
    instructionExit |= MOV_BITS(immr, 0x3F, 16);
    instructionExit |= MOV_BITS(imms, 0x3F, 10);
    instructionExit |= MOV_BITS(rn, 0x1F, 5);
    instructionExit |= MOV_BITS(rd, 0x1F, 0);

    return instructionExit;
}
