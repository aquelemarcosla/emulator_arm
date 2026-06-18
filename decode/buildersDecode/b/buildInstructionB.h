#ifndef BUILDINSTRUCTIONB_H
#define BUILDINSTRUCTIONB_H
#include "stdint.h"
#include "cpu/cpu.h"

/* Branches (Jumps) */
instruction buildBranch(uint32_t data);
instruction buildBL(uint32_t data);

// Conditional branches
instruction buildBEQ(uint32_t data);
instruction buildBNE(uint32_t data);

// Unconditional branch
instruction buildRET(uint32_t data);

#endif //BUILDINSTRUCTIONB_H
