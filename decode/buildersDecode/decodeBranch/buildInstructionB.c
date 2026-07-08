#include "buildInstructionB.h"
#include "stdint.h"
#include "cpu/cpu.h"
#include "stdint.h"
#include "../buildersDecode.h"

/* Branches */
Instruction buildBranch(uint32_t data) {
    Instruction instruction = {0};

    /* type: bits [28:25] */
    instruction.type = (uint8_t)GET_BITS(data, 0xF, 1, 25);

    /* imm26: bits [25:0] (signed) -> multiply by 4 (word-aligned) */
    uint32_t imm26 = (uint32_t)GET_BITS(data, 0x3FFFFFF, 1, 0);
    /* sign extend 26-bit to 32/64-bit */
    if (imm26 & (1u << 25)) {
        /* negative */
        int32_t s = (int32_t)(imm26 | (~0u << 26));
        instruction.imm = (int64_t)s * 4;
    } else {
        instruction.imm = (int64_t)((int32_t)imm26) * 4;
    }

    return instruction;
}
Instruction buildBL(uint32_t data) {
    Instruction instruction = {0};
    return instruction;
}

// Conditional branches
Instruction buildBEQ(uint32_t data) {
    Instruction instruction = {0};
    return instruction;
}
Instruction buildBNE(uint32_t data) {
    Instruction instruction = {0};
    return instruction;
}

// Unconditional branch
Instruction buildRET(uint32_t data) {
    Instruction instruction = {0};
    return instruction;
}