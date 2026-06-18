// Created by Lenovo on 18/06/2026.
#include <string.h>
#include "unity.h"
#include "../cpu/cpu.h"
#include "../encode/encode.h"
#include "../cpu/labels_table/labels_table.h"

static void print_binary32(uint32_t value) {
    for (int i = 31; i >= 0; i--) {
        printf("%u", (value >> i) & 1u);

        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

void test_encode_BNE(void) {
    addLabel("label", 123);

    uint32_t result = encode("BNE label");

    uint32_t expected = (0x54 << 24) | (123u << 5) | 1;

    printf("\n=== test_encode_BNE ===\n");

    printf("Result   : 0x%08X\n", result);
    print_binary32(result);

    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_BEQ(void) {
    addLabel("label", 123);

    uint32_t result = encode("BEQ label");

    uint32_t expected = (0x54 << 24) | (123u << 5);

    printf("\n=== test_encode_BEQ ===\n");

    printf("Result   : 0x%08X\n", result);
    print_binary32(result);

    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_branch(void) {
    addLabel("label", 123);

    uint32_t result = encode("B label");

    uint32_t expected = (5u << 26) | 123u; // Expected bits

    printf("\n=== test_encode_branch ===\n");

    printf("Result   : 0x%08X\n", result);
    print_binary32(result);

    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

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

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_encode_ADDI);
    RUN_TEST(test_encode_BNE);
    RUN_TEST(test_encode_BEQ);
    RUN_TEST(test_encode_branch);
    return UNITY_END();
}

void setUp(void) {}
void tearDown(void) {}
