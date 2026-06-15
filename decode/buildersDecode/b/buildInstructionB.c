#include "buildInstructionB.h"
#include "stdint.h"
#include "cpu/cpu.h"
#include "stdint.h"

/* Branches (Desvios) */
instruction buildBranch(uint32_t data) {
    instruction instruction = {0};
    return instruction;
}
instruction buildBL(uint32_t data) {
    instruction instruction = {0};
    return instruction;
}

// Desvios condicionais
instruction buildBEQ(uint32_t data) {
    instruction instruction = {0};
    return instruction;
}
instruction buildBNE(uint32_t data) {
    instruction instruction = {0};
    return instruction;
}

// Desvio incondicional
instruction buildRET(uint32_t data) {
    instruction instruction = {0};
    return instruction;
}