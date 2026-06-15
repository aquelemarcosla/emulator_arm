#ifndef BUILDINSTRUCTIONDPR_H
#define BUILDINSTRUCTIONDPR_H
#include <stdint.h>
#include "cpu/cpu.h"

/* Aritmética. */
instruction buildADD(uint32_t data);
instruction buildSUB(uint32_t data);

/* Lógica. */
instruction buildAND(uint32_t data);
instruction buildORR(uint32_t data);
instruction buildEOR(uint32_t data);

/* Deslocamento. */
instruction buildLSRV(uint32_t data);
instruction buildLSLV(uint32_t data);

#endif //BUILDINSTRUCTIONDPR_H
