#include <stdio.h>
#include "unity.h"
#include "../../../cpu/cpu.h"
#include "../../../encode/encode.h"

#include "../../print_utils.h"

void test_encode_dpr_ADD(void) {
    uint32_t result = encode("ADD X0, X1, X2");

    // ADDI: bits [31:21] = 0x458, [20:16] = rm, [15:10] = imm6, [9:5] = rn, [5:0] = rm
    uint32_t expected = (0x458u << 21) | (2u << 16) | (0u << 10) | 1u << 5 | 0u;

    printf("\n=== test_encode_ADD ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_dpr_SUB(void) {
    uint32_t result = encode("SUB X0, X1, X2");

    // ADDI: bits [31:21] = 0x658, [20:16] = rm, [15:10] = imm6, [9:5] = rn, [5:0] = rm
    uint32_t expected = (0x658u << 21) | (2u << 16) | (0u << 10) | 1u << 5 | 0u;

    printf("\n=== test_encode_SUB ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}