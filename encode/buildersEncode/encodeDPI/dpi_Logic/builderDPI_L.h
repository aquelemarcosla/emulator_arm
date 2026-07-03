#ifndef BUILDERDPI_L_H
#define BUILDERDPI_L_H
#include "stdint.h"

uint32_t builderANDI(uint32_t value, char **saveptr);
uint32_t builderORRI(uint32_t value, char **saveptr);
uint32_t builderEORI(uint32_t value, char **saveptr);

#endif // BUILDERDPI_L_H
