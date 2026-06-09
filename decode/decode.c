#include "../cpu/cpu.h"
#include "decode.h"
#include <stdint.h>
#include "buildersDecode/buildersDecode.h"

/* Extrai bits de data aplicando deslocamento e máscara. */
#define GET_BITS(data, shift, mask) (((data) >> (shift)) & (mask))

/* Classifica o major group e delega para o decodificador correspondente. */
instruction decode(uint32_t data) {

    /* Caso indefinido. */
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
            case 0x2:  /* SUBI [10] */
                return buildSUBI(data);
            case 0x3:  /* CMP [11] */
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
            case 0x2:  /* MOVZ [10] */
                return buildMOVZ(data);
            case 0x0:  /* MOVN [00] */
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

    /* Máscara opcode Aritmética [30] */
    uint8_t opAri = GET_BITS(data, 30, 0x1);

    /* Máscara opcode Lógica [30:29] */
    uint8_t opLog = GET_BITS(data, 29, 0x3);

    /* Máscara opcode Deslocamento [15:10] */
    uint8_t opDes = GET_BITS(data, 10, 0x3F);

    /* Subgrupo Aritmético [01011] */
    if ((opSubGp & 0xC) == 0xC) {
        switch (opAri) {
            case 0x0: /* ADD [0] */
                return buildADD(data);
            case 0x1: /* SUB [1] */
                return buildSUB(data);
            default:
                return inst;
        }
    /* Subgrupo Lógica [01010] */
    } else if ((opSubGp & 0xA) == 0xA) {
        switch (opLog) {
            case 0x0: /* AND [00] */
                return buildAND(data);
            case 0x1: /* ORR [01] */
                return buildORR(data);
            case 0x2: /* EOR [10] */
                return buildEOR(data);
            default:
                return inst;
        }
    /* Subgrupo Deslocamento [0110] */
    } else if ((opSubGp2 & 0x6) == 0x6) {
        if ((opDes & 0x8) == 0x8) { /* LSLV [001000] */
            return buildLSLV(data);
        } else if ((opSubGp2 & 0x9) == 0x9) {  /* LSRV [001001] */
            return buildLSRV(data);
        }

        return inst;
    }

    return inst;
}

/* Decodifica instruções do grupo Memory Access. */
instruction buildM(uint32_t data) {
    instruction inst = {0};

    /* Máscara de subgrupo de acesso a memória [29:24] */
    uint8_t opSubGp = GET_BITS(data, 24, 0x3F);

    /* Máscara de opcode [23:22] */
    uint8_t opcode = GET_BITS(data, 22, 0x3);

    if ((opSubGp & 0x39) == 0x39) {
        switch (opcode) {
            case 0x0: /* STR [00] */
                return buildSTR(data);
            case 0x1: /* LDR [01] */
                return buildLDR(data);
            default:
                return inst;
        }
    }

    return inst;
}

/* Decodifica instruções do grupo Branches. */
instruction buildB(uint32_t data) {

    instruction inst = {0};

    /* Máscara subgrupo [30:26] */
    uint8_t opSubGp = GET_BITS(data, 26, 0x1F);

    /* Máscara subgrupo 2 [31:24] */
    uint8_t opSubGp2 = GET_BITS(data, 24, 0xFF);

    // Máscara subgrupo 3 [31:25]
    uint8_t opSubGp3 = GET_BITS(data, 25, 0x7F);

    /* Máscara opcode [31] */
    uint8_t opcode = GET_BITS(data, 31, 0x1);

    // Máscara opcode 2 [3:0]
    uint8_t opcode2 = GET_BITS(data, 0, 0xF);

    // Máscara opcode 3 [24:10]
    uint16_t opcode3 = GET_BITS(data, 10, 0x7FFF);

    if ((opSubGp & 0x5) == 0x5) {
        switch (opcode) {
            case 0x0: // BRANCH [0]
                return buildBranch(data);
            case 0x1: // BL [1]
                return buildBL(data);
            default:
                return inst;
        }
        // BEQ e BNE
    } else if ((opSubGp2 & 0x54) == 0x54) { 
        switch (opcode2) {
            case 0x0: // BEQ [0000]
                return buildBEQ(data);
            case 0x1: // BNE [0001]
                return buildBNE(data);
            default:
                return inst;
        }
        // RET
    } else if ((opSubGp3 & 0x6B) == 0x6B) {
        if (opcode3 == 0x2F80) { // RET [101111111000000]
            return buildRET(data);
        }
    }

    return inst;
}
