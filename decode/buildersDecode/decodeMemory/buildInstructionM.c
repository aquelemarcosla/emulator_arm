#include "buildInstructionM.h"
#include <stdint.h>
#include "cpu/cpu.h"
#include "decode/buildersDecode/buildersDecode.h"

/* Memory access */
Instruction buildLDR(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = GET_BITS(data, 0x3FF, 1, 22);

    int32_t raw_imm = (int32_t)GET_BITS(data, 0xFFF, 1, 10);
    raw_imm = (raw_imm << 20) >> 20;
    instruction.imm = raw_imm * 8;

    instruction.rn = GET_BITS(data, 0x1F, 1, 5);
    instruction.rd = GET_BITS(data, 0x1F, 1, 0);

    return instruction;
}
Instruction buildSTR(uint32_t data) {
    Instruction instruction = {0};

    instruction.opcode = GET_BITS(data, 0x3FF, 1, 22);

    int32_t raw_imm = (int32_t)GET_BITS(data, 0xFFF, 1, 10);
    raw_imm = (raw_imm << 20) >> 20;
    instruction.imm = raw_imm * 8;

    instruction.rn = GET_BITS(data, 0x1F, 1, 5);
    instruction.rd = GET_BITS(data, 0x1F, 1, 0);

    return instruction;
}