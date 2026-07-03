#ifndef BUILDERS_H
#define BUILDERS_H

// DPI
#include "encodeDPI/dpi_Arithmetic/builderDPI_A.h"
#include "encodeDPI/dpi_Logic/builderDPI_L.h"
#include "encodeDPI/dpi_Move/builderDPI_MOV.h"
#include "encodeDPI/dpi_Shift/builderDPI_Shift.h"
#include "encodeDPR/dpr_Arithmetic/builderDPR_A.h"
#include "encodeDPR/dpr_Logic/builderDPR_L.h"
#include "encodeDPR/dpr_Shift/builderDPR_Shift.h"
// DPR
#include "encodeDPR/dpr_Arithmetic/builderDPR_A.h"
#include "encodeDPR/dpr_Logic/builderDPR_L.h"
#include "encodeDPR/dpr_Shift/builderDPR_Shift.h"
// Memory access
#include "encodeMemory/builderM.h"
// Branch & System
#include "encodeBranch/builderB.h"

uint32_t find_immediate(char **saveptr);
uint8_t find_register(char **saveptr);

#endif
