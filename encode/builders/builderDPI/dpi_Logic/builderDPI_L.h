#ifndef BUILDERDPI_L_H
#define BUILDERDPI_L_H
#include "stdint.h"

uint32_t builderANDI(char **saveptr);
uint32_t builderORRI(char **saveptr);
uint32_t builderEORI(char **saveptr);

#endif // BUILDERDPI_L_H