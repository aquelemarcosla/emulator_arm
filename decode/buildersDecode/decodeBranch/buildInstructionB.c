#include "buildInstructionB.h"
#include "stdint.h"
#include "cpu/cpu.h"
#include "stdint.h"
#include "../buildersDecode.h"

/* Branches */
Instruction buildBranch(uint32_t data) {
    Instruction instruction = {0};
    uint64_t raw_imm = (GET_BITS(data, 0x3FFFFFF, 1, 0));

    // Verify sinal
    if (raw_imm & (1 << 25)) {
        raw_imm |= 0xFFFFFFFFFC000000;
    }

    instruction.opcode = GET_BITS(data, 0x1F, 1, 26);
    instruction.imm = raw_imm * 4;

    return instruction;
}
Instruction buildBL(uint32_t data) {
    Instruction instruction = {0};
    uint64_t raw_imm = (GET_BITS(data, 0x3FFFFFF, 1, 0));

    // Verify sinal
    if (raw_imm & (1 << 25)) {
        raw_imm |= 0xFFFFFFFFFC000000;
    }

    instruction.opcode = GET_BITS(data, 0x1F, 1, 26);
    instruction.imm = raw_imm * 4;

    return instruction;
}

// Conditional branches
Instruction buildBEQ(uint32_t data) {
    Instruction instruction = {0};
    uint64_t raw_imm = (GET_BITS(data, 0x7FFFF, 1, 5));

    // Verify sinal
    if (raw_imm & (1 << 18)) {
        raw_imm |= 0xFFFFFFFFFFF80000;
    }

    instruction.opcode = GET_BITS(data, 0xFF, 1, 24);
    instruction.imm = raw_imm * 4;

    // Condition, not register.
    instruction.rd = (uint8_t)GET_BITS(data, 0xF, 1, 0);

    return instruction;
}
Instruction buildBNE(uint32_t data) {
    Instruction instruction = {0};
    uint64_t raw_imm = (GET_BITS(data, 0x7FFFF, 1, 5));

    // Verify sinal
    if (raw_imm & (1 << 18)) {
        raw_imm |= 0xFFFFFFFFFFF80000;
    }

    instruction.opcode = GET_BITS(data, 0xFF, 1, 24);
    instruction.imm = raw_imm * 4;

    // Condition, not register.
    instruction.rd = (uint8_t)GET_BITS(data, 0xF, 1, 0);

    return instruction;
}

// Unconditional branch
Instruction buildRET(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = GET_BITS(data, 0x7F, 1, 25);

    // Return register, X30
    instruction.rn = (uint8_t)GET_BITS(data, 0x1F, 1, 5);

    return instruction;
}