#include "buildInstructionDPI.h"
#include "cpu/cpu.h"
#include "stdint.h"
#include "../buildersDecode.h"

/* Arithmetic. */
Instruction buildADDI(uint32_t data) {
    Instruction instruction = {0};

    instruction.type = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.imm = (uint8_t)GET_BITS(data, 0xFFF, 1, 10);

    return instruction;
}
Instruction buildSUBI(uint32_t data) {
    Instruction instruction = {0};

    instruction.type = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.imm = (uint8_t)GET_BITS(data, 0xFFF, 1, 10);

    return instruction;
}
Instruction buildCMP(uint32_t data) {
    Instruction instruction = {0};

    instruction.type = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.imm = (uint8_t)GET_BITS(data, 0xFFF, 1, 10);

    return instruction;
}

/* Logic. */
Instruction buildANDI(uint32_t data) {
    Instruction instruction = {0};

    instruction.type = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.imm = (uint16_t)GET_BITS(data, 0x1FFF, 1, 10);

    return instruction;
}
Instruction buildORRI(uint32_t data) {
    Instruction instruction = {0};

    instruction.type = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.imm = (uint16_t)GET_BITS(data, 0x1FFF, 1, 10);

    return instruction;
}
Instruction buildEORI(uint32_t data) {
    Instruction instruction = {0};

    instruction.type = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.imm = (uint16_t)GET_BITS(data, 0x1FFF, 1, 10);

    return instruction;
}

/* Transfer. */
Instruction buildMOVZ(uint32_t data) {
    Instruction instruction = {0};

    instruction.type = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.imm = (uint16_t)GET_BITS(data, 0xFFFF, 1, 5);

    return instruction;
}
Instruction buildMOVN(uint32_t data) {
    Instruction instruction = {0};

    instruction.type = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.imm = (uint16_t)GET_BITS(data, 0xFFFF, 1, 5);

    return instruction;
}

/* Shift. */
Instruction buildUBFM(uint32_t data) {
    Instruction instruction = {0};

    instruction.type = (uint8_t)GET_BITS(data, 0xF, 1, 25);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.imm = (uint16_t)GET_BITS(data, 0xFFF, 1, 10);

    return instruction;
}