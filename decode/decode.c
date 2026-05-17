#include "../cpu/cpu.h"
#include "decode.h"
#include <stdint.h>
#include "dpi/BuildInstructionDPI.h"
#include "dpr/BuildInstructionDPR.h"

/* Extrai bits de data aplicando deslocamento e máscara. */
#define GET_BITS(data, shift, mask) (((data) >> (shift)) & (mask))

/* Classifica o major group e delega para o decodificador correspondente. */
instruction decode(uint32_t data) {

    /* Caso indefinido */
    instruction inst = {0};

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

    return inst;
}

/* Decodifica instruções do grupo Data Processing - Immediate. */
instruction buildDPI(uint32_t data) {

    /* Caso indefinido */
    instruction inst = {0};

    /* Mascára para subgrupo DPI [28:23]. */
    uint8_t opSubGp = GET_BITS(data, 23, 0x3F);

    /* Mascára para opocde [30:29]. */
    uint8_t opcode = GET_BITS(data, 29, 0x3);

    /* Subgrupo aritmético [100010] */
    if ((opSubGp & 0x22) == 0x22) {
        switch (opcode) {
            case 0x0:  /* ADDI [00] */
                return buildADDI(data);
            case 0x1:  /* SUBI [01] */
                return buildSUBI(data);
            case 0x2:  /* CMP [10] */
                return buildCMP(data);
            default:
                return inst;
        }
    /* Subgrupo lógico  [100100] */
    } else if ((opSubGp & 0x24) == 0x24) {
        switch (opcode) {
            case 0x0:  /* ANDI [00] */
                return buildANDI(data);
            case 0x1:  /* ORRI [01] */
                return buildORRI(data);
            case 0x2:  /* EORI [10] */
                return buildEORI(data);
            default:
                return inst;
        }
    /* Subgrupo transferencia [100101] */
    } else if ((opSubGp & 0x25) == 0x25) {
        switch (opcode) {
            case 0x0:  /* MOVZ [00] */
                return buildMOVZ(data);
            case 0x1:  /* MOVN [01] */
                return buildMOVN(data);
            default:
                return inst;
        }
    /* Subgrupo deslocamento [100110] */
    } else if ((opSubGp & 0x26) == 0x26) {
        /* UBFM */
        return buildUBFM(data);
    }

    return inst;
}

/* Decodifica instruções do grupo Data Processing - Register. */
instruction buildDPR(uint32_t data) {

    /* Caso indefinido */
    instruction inst = {0};

    /* Máscara subgrupo [28:24] Aritmética e Lógica. */
    uint8_t opSubGp = GET_BITS(data, 24, 0x1F);

    /* Máscara subgrupo [24:21] Deslocamento. */
    uint8_t opSubGp2 = GET_BITS(data, 21, 0xF);

    /* Máscara opcode aritmética [30] */
    uint8_t opcode = GET_BITS(data, 30, 0x1);

    /* Subgrupo Aritmético. */
    if ((opSubGp & 0xC) == 0xC) {
        switch (opcode) {
            case 0x0:
                return buildADD(data);
            case 0x1:
                return buildSUB(data);
            default:
                return inst;
        }
    }

    return inst;
}

/* Decodifica instruções do grupo Branches. */
instruction buildB(uint32_t data) {

}

/* Decodifica instruções do grupo Memory Access. */
instruction buildM(uint32_t data) {

}
