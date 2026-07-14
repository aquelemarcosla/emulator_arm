#include "builderM.h"
#include "stdint.h"
#include "encode/buildersEncode/buildersEncode.h"
#include <stdio.h>
#include <stdlib.h>

#define MOVE_BITS(data, mask, shift) (((uint32_t)(data) & (mask)) << (shift))

// LDR X0, [X1, #8]
uint32_t builderLDR(uint32_t value, char **saveptr) {
    uint8_t rd;
    uint8_t rn;
    uint32_t imm;
    uint32_t imm12;
    uint32_t instructionExit = 0;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    imm = find_immediate(saveptr);

    imm12 = imm / 8;

    instructionExit |= MOVE_BITS(value, 0x3FF, 22);
    instructionExit |= MOVE_BITS(imm12, 0xFFF, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);

    return instructionExit;
}

// STR X0, [X1, #8]
uint32_t builderSTR(uint32_t value, char **saveptr) {
    uint8_t rt;
    uint8_t rn;
    uint32_t imm;
    uint32_t imm12;
    uint32_t instructionExit = 0;

    rt = find_register(saveptr);
    rn = find_register(saveptr);
    imm = find_immediate(saveptr);

    imm12 = imm / 8;

    instructionExit |= MOVE_BITS(value, 0x3FF, 22);
    instructionExit |= MOVE_BITS(imm12, 0xFFF, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= MOVE_BITS(rt, 0x1F, 0);

    return instructionExit;
}