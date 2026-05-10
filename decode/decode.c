#include "../cpu/cpu.h"
#include "decode.h"
#include <stdint.h>
#include "dpi/BuildInstructionDPI.h"

/* Extrai bits de data aplicando deslocamento e máscara. */
#define GET_BITS(data, shift, mask) (((data) >> (shift)) & (mask))

/* Classifica o major group e delega para o decodificador correspondente. */
instruction decode(uint32_t data) {
    instruction inst;

    /* Isola os bits [28:25] para identificar o major group. */
    uint8_t op1 = GET_BITS(data, 25, 0xF);

    if ((op1 & 0xE) == 0x8) {  /* op1 == 100x: Data Processing - Immediate */
        return buildDPI(data);
    } else if ((op1 & 0xE) == 0xA) {  /* op1 == 101x: Branch */
        return buildB(data);
    } else if ((op1 & 0x7) == 0x5) {  /* op1 == x101: Data Processing - Register */
        return buildDPR(data);
    } else if ((op1 & 0x5) == 0x4) {  /* op1 == x1x0: Memory Access */
        return buildM(data);
    }
}

/* Decodifica instruções do grupo Data Processing - Immediate. */
instruction buildDPI(uint32_t data) {

    /* Mascaára para subgrupo em [28:23] e outra para opocde [30:29]. */
    uint8_t op2 = GET_BITS(data, 23, 0x3F);
    uint8_t op3 = GET_BITS(data, 29, 0x3);

    /* Subgrupo ADDI / SUBI / CMP. */
    if ((op2 & 0x22) == 0x22) {
        if ((op3 & 0x3) == 0x0) { /* ADDI */
            return buildADDI(data);
        }
    }
}

/* Decodifica instruções do grupo Data Processing - Register. */
instruction buildDPR(uint32_t data) {

}

/* Decodifica instruções do grupo Branches. */
instruction buildB(uint32_t data) {

}

/* Decodifica instruções do grupo Memory Access. */
instruction buildM(uint32_t data) {

}
