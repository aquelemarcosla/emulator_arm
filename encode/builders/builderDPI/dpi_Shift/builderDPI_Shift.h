#ifndef BUILDERDPI_SHIFT_H
#define BUILDERDPI_SHIFT_H
#include "stdint.h"

uint32_t builderLSL(uint32_t value, char **saveptr);
uint32_t builderLSR(uint32_t value, char **saveptr);

#endif // BUILDERDPI_SHIFT_H
