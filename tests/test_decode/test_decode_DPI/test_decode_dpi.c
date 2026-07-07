#include <stdio.h>
#include "unity.h"
#include "../../../cpu/cpu.h"
#include "../../../encode/encode.h"
#include "../../../decode/decode.h"

#include "../../print_utils.h"


/* Arithmetic Tests */

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

void test_decode_SUBI(void) {
    uint32_t encoded = encode("SUBI X5, X2, #50");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_SUBI ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.type, 4, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 12, 1);

    TEST_ASSERT_EQUAL_UINT8(instruction.type, instruction.type);
    TEST_ASSERT_EQUAL_UINT8(5, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(2, instruction.rn);
    TEST_ASSERT_EQUAL_INT64(50, instruction.imm);
}

void test_decode_CMP(void) {
    uint32_t encoded = encode("CMPI X3, #25");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_CMP ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.type, 4, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 12, 1);

    TEST_ASSERT_EQUAL_UINT8(3, instruction.rn);
    TEST_ASSERT_EQUAL_INT64(25, instruction.imm);
}

/* Logic Tests */

void test_decode_ANDI(void) {
    uint32_t encoded = encode("ANDI X1, X2, #0x7FF");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_ANDI ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.type, 8, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 13, 1);

    TEST_ASSERT_EQUAL_UINT8(1, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(2, instruction.rn);
    TEST_ASSERT_EQUAL_INT64(0x7FF, instruction.imm);
}

void test_decode_ORRI(void) {
    uint32_t encoded = encode("ORRI X3, X4, #0x555");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_ORRI ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.type, 8, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 13, 1);

    TEST_ASSERT_EQUAL_UINT8(3, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(4, instruction.rn);
    TEST_ASSERT_EQUAL_INT64(0x555, instruction.imm);
}

void test_decode_EORI(void) {
    uint32_t encoded = encode("EORI X6, X7, #0xAAA");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_EORI ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.type, 8, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 13, 1);

    TEST_ASSERT_EQUAL_UINT8(6, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(7, instruction.rn);
    TEST_ASSERT_EQUAL_INT64(0xAAA, instruction.imm);
}

/* Transfer Tests */

void test_decode_MOVZ(void) {
    uint32_t encoded = encode("MOVZ X8, #0x1234");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_MOVZ ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.type, 8, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 16, 0);

    TEST_ASSERT_EQUAL_UINT8(8, instruction.rd);
}

void test_decode_MOVN(void) {
    uint32_t encoded = encode("MOVN X9, #0x5678");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_MOVN ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.type, 8, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 16, 0);

    TEST_ASSERT_EQUAL_UINT8(9, instruction.rd);
}

/* Shift Tests */

void test_decode_UBFM(void) {
    uint32_t encoded = encode("LSR X10, X11, #2");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_UBFM (via LSR) ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.type, 4, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 12, 1);

    TEST_ASSERT_EQUAL_UINT8(10, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(11, instruction.rn);
}
