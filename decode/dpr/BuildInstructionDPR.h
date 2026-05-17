#ifndef EMULADOR_ARM_BUILDINSTRUCTIONDPR_H
#define EMULADOR_ARM_BUILDINSTRUCTIONDPR_H
#include <stdint.h>
#include "../../cpu/cpu.h"

/* Aritmética. */
instruction buildADD(uint32_t data);
instruction buildSUB(uint32_t data);

#endif //EMULADOR_ARM_BUILDINSTRUCTIONDPR_H
