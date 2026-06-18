#include "buildInstructionB.h"
#include "stdint.h"
#include "cpu/cpu.h"
#include "stdint.h"

/* Branches (Jumps) */
instruction buildBranch(uint32_t data) {
    instruction instruction = {0};
    return instruction;
}
instruction buildBL(uint32_t data) {
    instruction instruction = {0};
    return instruction;
}

// Conditional branches
instruction buildBEQ(uint32_t data) {
    instruction instruction = {0};
    return instruction;
}
instruction buildBNE(uint32_t data) {
    instruction instruction = {0};
    return instruction;
}

// Unconditional branch
instruction buildRET(uint32_t data) {
    instruction instruction = {0};
    return instruction;
}