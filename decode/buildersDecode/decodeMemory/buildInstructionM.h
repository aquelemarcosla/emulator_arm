#ifndef BUILDINSTRUCTIONM_H
#define BUILDINSTRUCTIONM_H
#include <stdint.h>
#include "cpu/cpu.h"

/* Memory access */
Instruction buildLDR(uint32_t data);
Instruction buildSTR(uint32_t data);

#endif //BUILDINSTRUCTIONM_H
