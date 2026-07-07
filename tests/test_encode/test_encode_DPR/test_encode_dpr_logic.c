#include <stdio.h>
#include "unity.h"
#include "../../../cpu/cpu.h"
#include "../../../encode/encode.h"

#include "../../print_utils.h"

void test_encode_dpr_AND(void) {
    uint32_t result = encode("AND X0, X1, X2");

    // AND: bits [31:21] = 0x450, [20:16] = rm, [15:10] = imm6, [9:5] = rn, [4:0] = rd
    uint32_t expected = (0x450u << 21) | (2u << 16) | (0u << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_dpr_AND ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_dpr_ORR(void) {
    uint32_t result = encode("ORR X0, X1, X2");

    // ORR: bits [31:21] = 0x550, [20:16] = rm, [15:10] = imm6, [9:5] = rn, [4:0] = rd
    uint32_t expected = (0x550u << 21) | (2u << 16) | (0u << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_dpr_ORR ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_dpr_EOR(void) {
    uint32_t result = encode("EOR X0, X1, X2");

    // EOR: bits [31:21] = 0x650, [20:16] = rm, [15:10] = imm6, [9:5] = rn, [4:0] = rd
    uint32_t expected = (0x650u << 21) | (2u << 16) | (0u << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_dpr_EOR ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}
