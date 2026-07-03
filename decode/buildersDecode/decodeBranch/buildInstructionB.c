#include "buildInstructionB.h"
#include "stdint.h"
#include "cpu/cpu.h"
#include "stdint.h"

/* Branches (Jumps) */
Instruction buildBranch(uint32_t data) {
    Instruction instruction = {0};
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