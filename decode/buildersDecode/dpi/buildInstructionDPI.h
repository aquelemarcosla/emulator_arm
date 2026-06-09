#ifndef BUILDINSTRUCTIONDPI_H
#define BUILDINSTRUCTIONDPI_H
#include <stdint.h>
#include "../../../cpu/cpu.h"

/* Aritmética. */
instruction buildADDI(uint32_t data) {}
instruction buildSUBI(uint32_t data) {}
instruction buildCMP(uint32_t data) {}

/* Lógica. */
instruction buildANDI(uint32_t data) {}
instruction buildORRI(uint32_t data) {}
instruction buildEORI(uint32_t data) {}

/* Transferencia. */
instruction buildMOVZ(uint32_t data) {}
instruction buildMOVN(uint32_t data) {}

/* Deslocamento */
instruction buildUBFM(uint32_t data) {}

#endif //BUILDINSTRUCTIONDPI_H
