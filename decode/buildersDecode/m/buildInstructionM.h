#ifndef BUILDINSTRUCTIONM_H
#define BUILDINSTRUCTIONM_H
#include <stdint.h>
#include "../../../cpu/cpu.h"

/* Acesso a memória */
instruction buildLDR(uint32_t data);
instruction buildSTR(uint32_t data);

#endif //BUILDINSTRUCTIONM_H
