#ifndef BUILDERM_H
#define BUILDERM_H
#include "stdint.h"

uint32_t builderLDR(uint32_t value, char **saveptr);
uint32_t builderSTR(uint32_t value, char **saveptr);

#endif // BUILDERM_H
