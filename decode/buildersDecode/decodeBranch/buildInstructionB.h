#ifndef BUILDINSTRUCTIONB_H
#define BUILDINSTRUCTIONB_H
#include "stdint.h"
#include "cpu/cpu.h"

/* Branches (Jumps) */
Instruction buildBranch(uint32_t data);
Instruction buildBL(uint32_t data);

// Conditional branches
Instruction buildBEQ(uint32_t data);
Instruction buildBNE(uint32_t data);

// Unconditional branch
Instruction buildRET(uint32_t data);

#endif //BUILDINSTRUCTIONB_H
