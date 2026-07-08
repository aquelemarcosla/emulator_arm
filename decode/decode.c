#include "../cpu/cpu.h"
#include "decode.h"
#include <stdint.h>
#include "buildersDecode/buildersDecode.h"

/* Extracts bits from data using shift and mask. */
#define GET_BITS(data, shift, mask) (((data) >> (shift)) & (mask))

/* Classifies the major group and delegates to the corresponding decoder. */
Instruction decode(uint32_t data) {

    /* Undefined case. */
    Instruction inst = {0};

    /* Isolates bits [28:25] to identify the major group. */
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

/* Decodes instructions from the Data Processing - Immediate group. */
Instruction buildDPI(uint32_t data) {

    /* Undefined case */
    Instruction inst = {0};

    /* Mask for DPI subgroup [28:23]. */
    uint8_t opSubGp = GET_BITS(data, 23, 0x3F);

    /* Mask for opcode [30:29]. */
    uint8_t opcode = GET_BITS(data, 29, 0x3);

    /* Arithmetic subgroup [100010] */
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
    /* Logical subgroup [100100] */
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
    /* Transfer subgroup [100101] */
    } else if ((opSubGp & 0x25) == 0x25) {
        switch (opcode) {
            case 0x2:  /* MOVZ [10] */
                return buildMOVZ(data);
            case 0x0:  /* MOVN [00] */
                return buildMOVN(data);
            default:
                return inst;
        }
    /* Shift subgroup [100110] */
    } else if ((opSubGp & 0x26) == 0x26) {
        /* UBFM */
        return buildUBFM(data);
    }

    return inst;
}

/* Decodes instructions from the Data Processing - Register group. */
Instruction buildDPR(uint32_t data) {

    /* Undefined case */
    Instruction inst = {0};

    /* Mask subgroup [28:24] Arithmetic and Logic. */
    uint8_t opSubGp = GET_BITS(data, 24, 0x1F);

    /* Mask subgroup [24:21] Shift. */
    uint8_t opSubGp2 = GET_BITS(data, 21, 0xF);

    /* Mask arithmetic opcode [30] */
    uint8_t opAri = GET_BITS(data, 30, 0x1);

    /* Mask logic opcode [30:29] */
    uint8_t opLog = GET_BITS(data, 29, 0x3);

    /* Mask shift opcode [15:10] */
    uint8_t opDes = GET_BITS(data, 10, 0x3F);

    /* Arithmetic subgroup [01011] */
    if ((opSubGp & 0xC) == 0xC) {
        switch (opAri) {
            case 0x0: /* ADD [0] */
                return buildADD(data);
            case 0x1: /* SUB [1] */
                return buildSUB(data);
            default:
                return inst;
        }
    /* Logical subgroup [01010] */
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
    /* Shift subgroup [0110] */
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

/* Decodes instructions from the Memory Access group. */
Instruction buildM(uint32_t data) {
    Instruction inst = {0};

    /* Mask for memory access subgroup [29:24] */
    uint8_t opSubGp = GET_BITS(data, 24, 0x3F);

    /* Mask for opcode [23:22] */
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

/* Decodes instructions from the Branches group. */
Instruction buildB(uint32_t data) {

    Instruction inst = {0};

    /* Mask subgroup [30:26] */
    uint8_t opSubGp = GET_BITS(data, 26, 0x1F);

    /* Mask subgroup 2 [31:24] */
    uint8_t opSubGp2 = GET_BITS(data, 24, 0xFF);

    // Mask subgroup 3 [31:25]
    uint8_t opSubGp3 = GET_BITS(data, 25, 0x7F);

    /* Mask opcode [31] */
    uint8_t opcode = GET_BITS(data, 31, 0x1);

    // Mask opcode 2 [3:0]
    uint8_t opcode2 = GET_BITS(data, 0, 0xF);

    // Mask opcode 3 [24:10]
    uint16_t opcode3 = GET_BITS(data, 10, 0x7FFF);

    if (opSubGp == 0x5) {
        switch (opcode) {
            case 0x0: // BRANCH [0]
                return buildBranch(data);
            case 0x1: // BL [1]
                return buildBL(data);
            default:
                return inst;
        }
        // BEQ and BNE
    } else if (opSubGp2 == 0x54) {
        switch (opcode2) {
            case 0x0: // BEQ [0000]
                return buildBEQ(data);
            case 0x1: // BNE [0001]
                return buildBNE(data);
            default:
                return inst;
        }
        // RET
    } else if (opSubGp3 == 0x6B) {
        if (opcode3 == 0x2F80) { // RET [010111110000000]
            return buildRET(data);
        }
    }

    return inst;
}
