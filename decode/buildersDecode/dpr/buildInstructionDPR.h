#ifndef BUILDINSTRUCTIONDPR_H
#define BUILDINSTRUCTIONDPR_H
#include <stdint.h>
#include "cpu/cpu.h"

/* Arithmetic. */
instruction buildADD(uint32_t data);
instruction buildSUB(uint32_t data);

/* Logic. */
instruction buildAND(uint32_t data);
instruction buildORR(uint32_t data);
instruction buildEOR(uint32_t data);

/* Shift. */
instruction buildLSRV(uint32_t data);
instruction buildLSLV(uint32_t data);

#endif //BUILDINSTRUCTIONDPR_H
