#include <stdio.h>
#include "unity.h"
#include "../../../cpu/cpu.h"
#include "../../../encode/encode.h"

#include "../../print_utils.h"

void test_encode_ANDI(void) {
        uint32_t result = encode("ANDI X0, X1, #0xF");

        uint32_t expected = (0x124u << 23) | (0x1003u << 10) | (1u << 5) | 0u;

        printf("\n=== test_encode_ANDI ===\n");
        printf("Result   : 0x%08X\n", result);
        print_binary32(result);
        printf("Expected : 0x%08X\n", expected);
        print_binary32(expected);

        TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_ORRI(void) {
    uint32_t result = encode("ORRI X0, X1, #0xF");

    // #0xF -> N=1, immr=0, imms=3 → imm13 = 0x1003
    uint32_t expected = (0x164u << 23) | (0x1003u << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_ORRI ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_EORI(void) {
    uint32_t result = encode("EORI X0, X1, #0xF");

    // #0xF -> N=1, immr=0, imms=3 → imm13 = 0x1003
    uint32_t expected = (0x1A4u << 23) | (0x1003u << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_EORI ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}
