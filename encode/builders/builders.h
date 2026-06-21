#ifndef BUILDERS_H
#define BUILDERS_H

// DPI
#include "builderDPI/dpi_Arithmetic/builderDPI_A.h"
#include "builderDPI/dpi_Logic/builderDPI_L.h"
#include "builderDPI/dpi_Move/builderDPI_MOV.h"
#include "builderDPI/dpi_Shift/builderDPI_Shift.h"
#include "builderDPR/dpr_Arithmetic/builderDPR_A.h"
#include "builderDPR/dpr_Logic/builderDPR_L.h"
#include "builderDPR/dpi_Shift/builderDPR_Shift.h"
// DPR
#include "builderDPR/dpr_Arithmetic/builderDPR_A.h"
#include "builderDPR/dpr_Logic/builderDPR_L.h"
#include "builderDPR/dpi_Shift/builderDPR_Shift.h"
// Memory access
#include "builderM/m_Access/builderM.h"
// Branch & System
#include "builderB/b_Branch/builderB.h"

uint32_t find_immediate(char **saveptr);
uint8_t find_register(char **saveptr);

#endif
