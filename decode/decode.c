#include "../cpu/cpu.h"
#include "stdint.h"
#include "decode.h"

/*
 * GET_BITS
 * Macro para facilitar desconstrução do dado bruto, composto por shift para direita e mascara de bits
 */
#define GET_BITS(data, shift, mask) (((data) >> (shift)) & (mask))

instruction buildDPI(uint32_t data) {  // Data Processing - Immediate

}

instruction buildDPR(uint32_t data) { // Data Processing - Register

}

instruction buildB(uint32_t data) {  // Branches

}

instruction buildM(uint32_t data) { // Memory Access

}

instruction decode(uint32_t data) {
    instruction inst;
    uint8_t op1 = GET_BITS(data, 25, 0xF); // Preserva somente [28:25] opcode primário major group

    /*
     *  Teste dos bits [28:25] para calssificação do major group
     *  Usei mascra para isolar os bits
     */
    if ((op1 & 0xE) == 0x8) {  // op1 == 100x DATA PROCESSING IMMEDIATE
        return buildDPI(data);
    } else if ((op1 & 0xE) == 0xA){  // op1 == 101x BRANCH
        return buildB(data);
    } else if ((op1 & 0x7) == 0x5){  // op1 == x101 DATA PROCESSING REGISTER
        return buildDPR(data);
    } else if ((op1 & 0x5) == 0x4) {  // op1 == x1x0 MEMORY ACCESS
        return buildM(data);
    }
}