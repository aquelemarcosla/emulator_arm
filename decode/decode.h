#ifndef DECODE_H
#define DECODE_H

#include "../cpu/cpu.h"

instruction decode(uint32_t data);  // Function that returns the decoded instruction

instruction buildDPR(uint32_t data);
instruction buildDPI(uint32_t data);
instruction buildB(uint32_t data);
instruction buildM(uint32_t data);

#endif
