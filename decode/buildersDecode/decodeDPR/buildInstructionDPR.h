#ifndef BUILDINSTRUCTIONDPR_H
#define BUILDINSTRUCTIONDPR_H
#include <stdint.h>
#include "cpu/cpu.h"

/* Arithmetic. */
Instruction buildADD(uint32_t data);
Instruction buildSUB(uint32_t data);

/* Logic. */
Instruction buildAND(uint32_t data);
Instruction buildORR(uint32_t data);
Instruction buildEOR(uint32_t data);

/* Shift. */
Instruction buildLSRV(uint32_t data);
Instruction buildLSLV(uint32_t data);

#endif //BUILDINSTRUCTIONDPR_H
