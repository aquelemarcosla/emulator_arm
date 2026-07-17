#include <stdio.h>
#include "unity.h"
#include "../../../cpu/cpu.h"
#include "../../../encode/encode.h"
#include "../../../decode/decode.h"

#include "../../print_utils.h"

extern uint64_t decodeLogicalImmediate(uint16_t field);

static void assert_logical_immediate_decode(uint32_t encoded, Instruction instruction) {
    TEST_ASSERT_EQUAL_UINT16((encoded >> 23) & 0x1FFu, instruction.opcode);
    TEST_ASSERT_EQUAL_UINT8((encoded >> 0) & 0x1Fu, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8((encoded >> 5) & 0x1Fu, instruction.rn);
    uint16_t rawField = (uint16_t)((encoded >> 10) & 0x1FFFu);
    uint64_t expectedImm = decodeLogicalImmediate(rawField);
    TEST_ASSERT_EQUAL_UINT64(expectedImm, instruction.imm);
}


/* Arithmetic Tests */
void test_decode_ADDI(void) {
    uint32_t encoded = encode("ADDI X0, X1, #100");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_ADDI ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.opcode, 4, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("rm       : ");
    print_bits_with_value(instruction.rm, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 12, 1);

    TEST_ASSERT_EQUAL_UINT16(0x244, instruction.opcode);
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
    print_bits_with_value(instruction.opcode, 4, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 12, 1);

    TEST_ASSERT_EQUAL_UINT16(0x344, instruction.opcode);
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
    print_bits_with_value(instruction.opcode, 4, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 12, 1);

    TEST_ASSERT_EQUAL_UINT16(0x3C4, instruction.opcode);
    TEST_ASSERT_EQUAL_UINT8(3, instruction.rn);
    TEST_ASSERT_EQUAL_INT64(25, instruction.imm);
}

/* Logic Tests */

void test_decode_ANDI(void) {
    uint32_t encoded = encode("ANDI X1, X2, #0xF");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_ANDI ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.opcode, 4, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 13, 0);

    assert_logical_immediate_decode(encoded, instruction);
}

void test_decode_ORRI(void) {
    uint32_t encoded = encode("ORRI X3, X4, #0xAAAAAAAAAAAAAAAA");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_ORRI ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.opcode, 4, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 13, 0);

    assert_logical_immediate_decode(encoded, instruction);
}

void test_decode_EORI(void) {
    uint32_t encoded = encode("EORI X6, X7, #0xFF00FF00FF00FF00");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_EORI ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.opcode, 4, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 13, 0);

    assert_logical_immediate_decode(encoded, instruction);
}

/* Transfer Tests */

void test_decode_MOVZ(void) {
    uint32_t encoded = encode("MOVZ X8, #0x1234");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_MOVZ ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.opcode, 8, 0);
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
    print_bits_with_value(instruction.opcode, 8, 0);
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
    print_bits_with_value(instruction.opcode, 4, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 12, 1);

    TEST_ASSERT_EQUAL_UINT8(10, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(11, instruction.rn);
}
