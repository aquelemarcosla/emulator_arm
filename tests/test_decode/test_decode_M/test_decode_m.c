
#include <stdio.h>
#include "unity.h"
#include "../../../cpu/cpu.h"
#include "../../../encode/encode.h"
#include "../../../decode/decode.h"

#include "../../print_utils.h"

void test_decode_LDR(void) {
    uint32_t encoded = encode("LDR X0, [X1, #-8]");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_LDR ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.type, 4, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 12, 0);

    TEST_ASSERT_EQUAL_UINT8(12, instruction.type);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(1, instruction.rn);
    TEST_ASSERT_EQUAL_INT64(-8, instruction.imm);
}

void test_decode_STR(void) {
    uint32_t encoded = encode("STR X0, [X1, #8]");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_STR ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.type, 4, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 12, 0);

    TEST_ASSERT_EQUAL_UINT8(12, instruction.type);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(1, instruction.rn);
    TEST_ASSERT_EQUAL_INT64(8, instruction.imm);
}
