#include "builderDPR_Shift.h"

#include <string.h>

#include "stdint.h"
#include "encode/buildersEncode/buildersEncode.h"
#define MOVE_BITS(data, mask, shift) (((uint32_t)(data) & (mask)) << (shift))

// LSRV Rd, Rn, Rm
uint32_t builderLSRV(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint8_t rm;
    uint8_t lowOpcode = 0x9;
    uint8_t rn;
    uint8_t rd;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    rm = find_register(saveptr);

    instructionExit |= MOVE_BITS(value, 0x7FF, 21);
    instructionExit |= MOVE_BITS(rm, 0x1F, 16);
    instructionExit |= MOVE_BITS(lowOpcode, 0x3F, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);

    return instructionExit;
}

// LSLV Rd, Rn, Rm
uint32_t builderLSLV(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint8_t rm;
    uint8_t lowOpcode = 0x8;
    uint8_t rn;
    uint8_t rd;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    rm = find_register(saveptr);

    instructionExit |= MOVE_BITS(value, 0x7FF, 21);
    instructionExit |= MOVE_BITS(rm, 0x1F, 16);
    instructionExit |= MOVE_BITS(lowOpcode, 0x3F, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);

    return instructionExit;
}