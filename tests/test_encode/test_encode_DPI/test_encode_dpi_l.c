#include <stdio.h>
#include "unity.h"
#include "../../../cpu/cpu.h"
#include "../../../encode/encode.h"

#include "../../print_utils.h"

static void assert_logical_immediate_encoding(uint32_t result, uint32_t opcode, uint16_t imm13, uint8_t rn, uint8_t rd) {
    TEST_ASSERT_EQUAL_UINT32(opcode, (result >> 23) & 0x1FFu);
    TEST_ASSERT_EQUAL_UINT32(imm13, (result >> 10) & 0x1FFFu);
    TEST_ASSERT_EQUAL_UINT32(rn, (result >> 5) & 0x1Fu);
    TEST_ASSERT_EQUAL_UINT32(rd, result & 0x1Fu);
}

void test_encode_ANDI(void) {
    uint32_t result = encode("ANDI X0, X1, #0xF");

    uint32_t expected = (0x124u << 23) | (0x1003u << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_ANDI ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    assert_logical_immediate_encoding(result, 0x124u, 0x1003u, 1u, 0u);
    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_ORRI(void) {
    uint32_t result = encode("ORRI X0, X1, #0xF");

    uint32_t expected = (0x164u << 23) | (0x1003u << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_ORRI ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    assert_logical_immediate_encoding(result, 0x164u, 0x1003u, 1u, 0u);
    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_EORI(void) {
    uint32_t result = encode("EORI X0, X1, #0xF");

    uint32_t expected = (0x1A4u << 23) | (0x1003u << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_EORI ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    assert_logical_immediate_encoding(result, 0x1A4u, 0x1003u, 1u, 0u);
    TEST_ASSERT_EQUAL_HEX32(expected, result);
}
