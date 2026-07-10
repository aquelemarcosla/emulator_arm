#include <stdio.h>
#include "unity.h"
#include "../../../cpu/cpu.h"
#include "../../../encode/encode.h"
#include "../../../decode/decode.h"

#include "../../print_utils.h"


/* Arithmetic Tests */
void test_decode_ADD(void) {
    uint32_t encoded = encode("ADD X0, X1, X2");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_ADD ===\n");
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

    TEST_ASSERT_EQUAL_UINT8(0, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(1, instruction.rn);
    TEST_ASSERT_EQUAL_UINT8(2, instruction.rm);
}

void test_decode_SUB(void) {
    uint32_t encoded = encode("SUB X3, X4, X5");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_SUB ===\n");
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

    TEST_ASSERT_EQUAL_UINT8(3, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(4, instruction.rn);
    TEST_ASSERT_EQUAL_UINT8(5, instruction.rm);
}

/* Logic Tests */

void test_decode_AND(void) {
    uint32_t encoded = encode("AND X6, X7, X8");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_AND ===\n");
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

    TEST_ASSERT_EQUAL_UINT8(6, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(7, instruction.rn);
    TEST_ASSERT_EQUAL_UINT8(8, instruction.rm);
}

void test_decode_ORR(void) {
    uint32_t encoded = encode("ORR X9, X10, X11");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_ORR ===\n");
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

    TEST_ASSERT_EQUAL_UINT8(9, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(10, instruction.rn);
    TEST_ASSERT_EQUAL_UINT8(11, instruction.rm);
}

void test_decode_EOR(void) {
    uint32_t encoded = encode("EOR X12, X13, X14");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_EOR ===\n");
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

    TEST_ASSERT_EQUAL_UINT8(12, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(13, instruction.rn);
    TEST_ASSERT_EQUAL_UINT8(14, instruction.rm);
}

/* Shift Tests */

void test_decode_LSRV(void) {
    uint32_t encoded = encode("LSRV X15, X16, X17");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_LSRV ===\n");
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

    TEST_ASSERT_EQUAL_UINT8(15, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(16, instruction.rn);
    TEST_ASSERT_EQUAL_UINT8(17, instruction.rm);
}

void test_decode_LSLV(void) {
    uint32_t encoded = encode("LSLV X18, X19, X20");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_LSLV ===\n");
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

    TEST_ASSERT_EQUAL_UINT8(18, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(19, instruction.rn);
    TEST_ASSERT_EQUAL_UINT8(20, instruction.rm);
}
