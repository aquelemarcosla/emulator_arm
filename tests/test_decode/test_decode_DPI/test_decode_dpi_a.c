#include <stdio.h>
#include "unity.h"
#include "../../../cpu/cpu.h"
#include "../../../encode/encode.h"
#include "../../../decode/decode.h"

#include "../../print_utils.h"


void test_decode_ADDI(void) {
    uint32_t encoded = encode("ADDI X0, X1, #100");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_ADDI ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.type, 4, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("rm       : ");
    print_bits_with_value(instruction.rm, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 12, 1);

    TEST_ASSERT_EQUAL_UINT8(8, instruction.type);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(1, instruction.rn);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rm);
    TEST_ASSERT_EQUAL_INT64(100, instruction.imm);
}
