#ifndef EMULADOR_ARM_BUILDINSTRUCTIONB_H
#define EMULADOR_ARM_BUILDINSTRUCTIONB_H
#include "../../cpu/cpu.h"
#include "stdint.h"

/* Branches (Desvios) */
instruction buildB(uint32_t data);
instruction buildBL(uint32_t data);

#endif //EMULADOR_ARM_BUILDINSTRUCTIONB_H
