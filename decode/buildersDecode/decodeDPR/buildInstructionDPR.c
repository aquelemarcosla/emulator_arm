#include "buildInstructionDPR.h"
#include <stdint.h>
#include "cpu/cpu.h"
#include "../buildersDecode.h"

/* Arithmetic. */
Instruction buildADD(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 1, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.rm = (uint8_t)GET_BITS(data, 0x1F, 1, 16);

    return instruction;
}
Instruction buildSUB(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.rm = (uint8_t)GET_BITS(data, 0x1F, 1, 16);

    return instruction;
}

/* Logic. */
Instruction buildAND(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.rm = (uint8_t)GET_BITS(data, 0x1F, 1, 16);

    return instruction;
}
Instruction buildORR(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.rm = (uint8_t)GET_BITS(data, 0x1F, 1, 16);

    return instruction;
}
Instruction buildEOR(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.rm = (uint8_t)GET_BITS(data, 0x1F, 1, 16);

    return instruction;
}

/* Shift. */
Instruction buildLSRV(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.rm = (uint8_t)GET_BITS(data, 0x1F, 1, 16);

    return instruction;
}
Instruction buildLSLV(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.rm = (uint8_t)GET_BITS(data, 0x1F, 1, 16);

    return instruction;
}