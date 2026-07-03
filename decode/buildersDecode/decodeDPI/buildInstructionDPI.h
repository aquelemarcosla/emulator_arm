#ifndef BUILDINSTRUCTIONDPI_H
#define BUILDINSTRUCTIONDPI_H
#include <stdint.h>
#include "cpu/cpu.h"

/* Arithmetic. */
Instruction buildADDI(uint32_t data);
Instruction buildSUBI(uint32_t data);
Instruction buildCMP(uint32_t data);

/* Logic. */
Instruction buildANDI(uint32_t data);
Instruction buildORRI(uint32_t data);
Instruction buildEORI(uint32_t data);

/* Transfer. */
Instruction buildMOVZ(uint32_t data);
Instruction buildMOVN(uint32_t data);

/* Shift. */
Instruction buildUBFM(uint32_t data);

#endif //BUILDINSTRUCTIONDPI_H
