#include <stdio.h>
#include "unity.h"
#include "../../../cpu/cpu.h"
#include "../../../encode/encode.h"
#include "../../../decode/decode.h"

#include "../../print_utils.h"
#include "cpu/labels_table/labels_table.h"

void test_decode_B(void) {
    addLabel("label", 12);

    uint32_t encoded = encode("B label");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_Branch ===\n");
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

    TEST_ASSERT_EQUAL_UINT8(10, instruction.type);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rn);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rm);
    TEST_ASSERT_EQUAL_INT64(12, instruction.imm);
}

void test_decode_BL(void) {
    addLabel("label", 12);

    uint32_t encoded = encode("BL label");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_Branch and Link ===\n");
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

    TEST_ASSERT_EQUAL_UINT8(10, instruction.type);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rn);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rm);
    TEST_ASSERT_EQUAL_INT64(12, instruction.imm);
}

void test_decode_BEQ(void) {
    addLabel("label", 12);

    uint32_t encoded = encode("BEQ label");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_BEQ ===\n");
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

    TEST_ASSERT_EQUAL_UINT8(10, instruction.type);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rn);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rm);
    TEST_ASSERT_EQUAL_INT64(12, instruction.imm);
}

void test_decode_BNE(void) {
    addLabel("label", 12);

    uint32_t encoded = encode("BNE label");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_BNE ===\n");
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

    TEST_ASSERT_EQUAL_UINT8(10, instruction.type);
    TEST_ASSERT_EQUAL_UINT8(1, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rn);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rm);
    TEST_ASSERT_EQUAL_INT64(12, instruction.imm);
}

void test_decode_RET(void) {
    uint32_t encoded = encode("RET");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_RET ===\n");
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

    TEST_ASSERT_EQUAL_UINT8(11, instruction.type);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(30, instruction.rn);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rm);
    TEST_ASSERT_EQUAL_INT64(0, instruction.imm);
}
