#include "builderDPI_L.h"

#include "stdint.h"
#include "encode/builders/builders.h"

#define MOVE_BITS(data, mask, shift) (((uint32_t)(data) & (mask)) << (shift))

// ANDI X0, X1, #100
uint32_t builderANDI(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint16_t imm13;
    uint8_t rn;
    uint8_t rd;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    imm13 = find_immediate(saveptr);

    instructionExit |= MOVE_BITS(value, 0xFFF, 23);
    instructionExit |= MOVE_BITS(imm13, 0x1FFF, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);

    return instructionExit;
}

// ORRI X0, X1, #100
uint32_t builderORRI(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint16_t imm13;
    uint8_t rn;
    uint8_t rd;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    imm13 = find_immediate(saveptr);

    instructionExit |= MOVE_BITS(value, 0xFFF, 23);
    instructionExit |= MOVE_BITS(imm13, 0x1FFF, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);

    return instructionExit;
}

// EORI X0, X1, #100
uint32_t builderEORI(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint16_t imm13;
    uint8_t rn;
    uint8_t rd;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    imm13 = find_immediate(saveptr);

    instructionExit |= MOVE_BITS(value, 0xFFF, 23);
    instructionExit |= MOVE_BITS(imm13, 0x1FFF, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);

    return instructionExit;
}
