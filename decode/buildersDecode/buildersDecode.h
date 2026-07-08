#ifndef BUILDERSDECODE_H
#define BUILDERSDECODE_H

#define GET_BITS(data, mask, type_shift, shift) \
((type_shift == 0) ? \
((data) << (shift)) & (mask) : \
((data) >> (shift)) & (mask))

#include "decodeBranch/buildInstructionB.h"
#include "decodeDPI/buildInstructionDPI.h"
#include "decodeDPR/buildInstructionDPR.h"
#include "decodeMemory/buildInstructionM.h"

#endif //BUILDERSDECODE_H