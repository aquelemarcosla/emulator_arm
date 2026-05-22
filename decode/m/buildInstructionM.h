#ifndef EMULADOR_ARM_BUILDINSTRUCTIONM_H
#define EMULADOR_ARM_BUILDINSTRUCTIONM_H
#include <stdint.h>
#include "../../cpu/cpu.h"

/* Acesso a memória */
instruction buildLDR(uint32_t data);
instruction buildSTR(uint32_t data);

#endif //EMULADOR_ARM_BUILDINSTRUCTIONM_H
