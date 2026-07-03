#ifndef BUILDER_DPR_LOGIC_H
#define BUILDER_DPR_LOGIC_H
#include "stdint.h"

uint32_t builderAND(uint32_t value, char **saveptr);
uint32_t builderORR(uint32_t value, char **saveptr);
uint32_t builderEOR(uint32_t value, char **saveptr);

#endif
