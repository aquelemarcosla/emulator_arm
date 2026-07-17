#include "buildInstructionDPI.h"
#include "cpu/cpu.h"
#include "stdint.h"
#include "../buildersDecode.h"

static uint64_t rotateRightN(uint64_t value, uint32_t width, uint32_t amount) {
    amount %= width;
    uint64_t mask = (width == 64) ? ~0ULL : ((1ULL << width) - 1);
    value &= mask;
    if (amount == 0) {
        return value;
    }
    return ((value >> amount) | (value << (width - amount))) & mask;
}

uint64_t decodeLogicalImmediate(uint16_t field) {
    uint32_t n    = (field >> 12) & 0x1;
    uint32_t immr = (field >> 6)  & 0x3F;
    uint32_t imms = field & 0x3F;

    uint32_t concat = (n << 6) | (~imms & 0x3F);
    int len = -1;
    for (int i = 6; i >= 0; i--) {
        if (concat & (1u << i)) { len = i; break; }
    }
    if (len < 0) {
        return 0;
    }

    uint32_t esize  = 1u << len;
    uint32_t levels = esize - 1;

    uint32_t s = imms & levels;
    uint32_t r = immr & levels;

    uint64_t welem = (s + 1 == 64) ? ~0ULL : ((1ULL << (s + 1)) - 1);
    uint64_t element = rotateRightN(welem, esize, r);

    uint64_t result = 0;
    for (uint32_t i = 0; i < 64 / esize; i++) {
        result |= element << (i * esize);
    }

    return result;
}

/* Arithmetic. */
Instruction buildADDI(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = GET_BITS(data, 0x3FF, 1, 22);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.imm = (uint16_t)GET_BITS(data, 0xFFF, 1, 10);

    return instruction;
}
Instruction buildSUBI(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = GET_BITS(data, 0x3FF, 1, 22);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.imm = (uint16_t)GET_BITS(data, 0xFFF, 1, 10);

    return instruction;
}
Instruction buildCMP(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = GET_BITS(data, 0x3FF, 1, 22);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.imm = (uint16_t)GET_BITS(data, 0xFFF, 1, 10);

    return instruction;
}

/* Logic. */
Instruction buildANDI(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = GET_BITS(data, 0x1FF, 1, 23);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);

    uint16_t rawField = (uint16_t)GET_BITS(data, 0x1FFF, 1, 10);
    instruction.imm = decodeLogicalImmediate(rawField);

    return instruction;
}

Instruction buildORRI(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = GET_BITS(data, 0x1FF, 1, 23);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);

    uint16_t rawField = (uint16_t)GET_BITS(data, 0x1FFF, 1, 10);
    instruction.imm = decodeLogicalImmediate(rawField);

    return instruction;
}

Instruction buildEORI(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = GET_BITS(data, 0x1FF, 1, 23);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);

    uint16_t rawField = (uint16_t)GET_BITS(data, 0x1FFF, 1, 10);
    instruction.imm = decodeLogicalImmediate(rawField);

    return instruction;
}

/* Transfer. */
Instruction buildMOVZ(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = GET_BITS(data, 0x7FF, 1, 21);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.imm = (uint16_t)GET_BITS(data, 0xFFFF, 1, 5);

    return instruction;
}
Instruction buildMOVN(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = GET_BITS(data, 0x7FF, 1, 21);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.imm = (uint16_t)GET_BITS(data, 0xFFFF, 1, 5);

    return instruction;
}

/* Shift. */
Instruction buildUBFM(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = GET_BITS(data, 0x3FF, 1, 22);
    instruction.rd = (uint8_t)GET_BITS(data, 0x1F, 0, 0);
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);
    instruction.imm = (uint16_t)GET_BITS(data, 0xFFF, 1, 10);

    return instruction;
}