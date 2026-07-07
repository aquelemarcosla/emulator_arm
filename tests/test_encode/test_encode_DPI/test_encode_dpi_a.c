#include <stdio.h>
#include "unity.h"
#include "../../../cpu/cpu.h"
#include "../../../encode/encode.h"

#include "../../print_utils.h"

void test_encode_ADDI(void) {
    uint32_t result = encode("ADDI X0, X1, #100");

    // ADDI: bits [31:22] = 0x244, [21:10] = imm12, [9:5] = rn, [4:0] = rd
    uint32_t expected = (0x244u << 22) | (100u << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_ADDI ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_SUBI(void) {
    uint32_t result = encode("SUBI X0, X1, #100");

    // SUBI: bits [31:22] = 0x344, [21:10] = imm12, [9:5] = rn, [4:0] = rd
    uint32_t expected = (0x344u << 22) | (100u << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_SUBI ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_CMPI(void) {
    uint32_t result = encode("CMPI X0, #1");

    // CMPI: bits [31:22] = 0x3C4, [21:10] = imm12, [9:5] = rn, [4:0] = rd
    uint32_t expected = (0x3C4u << 22) | (1u << 10) | (0u << 5) | 0x1F;

    printf("\n=== test_encode_CMPI ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}


