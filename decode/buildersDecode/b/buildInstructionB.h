#ifndef BUILDINSTRUCTIONB_H
#define BUILDINSTRUCTIONB_H
#include "stdint.h"
#include "cpu/cpu.h"

/* Branches (Desvios) */
instruction buildBranch(uint32_t data);
instruction buildBL(uint32_t data);

// Desvios condicionais
instruction buildBEQ(uint32_t data);
instruction buildBNE(uint32_t data);

// Desvio incondicional
instruction buildRET(uint32_t data);

#endif //BUILDINSTRUCTIONB_H
