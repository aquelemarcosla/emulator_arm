#ifndef BUILDERB_H
#define BUILDERB_H
#include "stdint.h"

uint32_t builderB(char **saveptr);
uint32_t builderBL(char **saveptr);
uint32_t builderRET(char **saveptr);
uint32_t builderBEQ(char **saveptr);
uint32_t builderBNE(char **saveptr);

#endif // BUILDERB_H