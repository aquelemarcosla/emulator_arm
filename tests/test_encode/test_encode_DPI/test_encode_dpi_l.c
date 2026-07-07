#include <stdio.h>
#include "unity.h"
#include "../../../cpu/cpu.h"
#include "../../../encode/encode.h"

#include "../../print_utils.h"

void test_encode_ANDI(void) {
        uint32_t result = encode("ANDI X0, X1, #100");

        // ADDI: bits [31:23] = 0x244, [22:10] = imm13, [9:5] = rn, [4:0] = rd
        uint32_t expected = (0x124u << 23) | (100u << 10) | (1u << 5) | 0u;

        printf("\n=== test_encode_ANDI ===\n");
        printf("Result   : 0x%08X\n", result);
        print_binary32(result);
        printf("Expected : 0x%08X\n", expected);
        print_binary32(expected);

        TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_ORRI(void) {
    uint32_t result = encode("ORRI X0, X1, #100");

    // ADDI: bits [31:23] = 0x244, [22:10] = imm13, [9:5] = rn, [4:0] = rd
    uint32_t expected = (0x164u << 23) | (100u << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_ORRI ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_EORI(void) {
    uint32_t result = encode("EORI X0, X1, #100");

    // ADDI: bits [31:23] = 0x244, [22:10] = imm13, [9:5] = rn, [4:0] = rd
    uint32_t expected = (0x1A4u << 23) | (100u << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_EORI ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

