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

    uint32_t expected = (5u << 26) | 123u; // Bits esperados

    printf("\n=== test_encode_branch ===\n");

    printf("Result   : 0x%08X\n", result);
    print_binary32(result);

    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_reg_read_and_write(void) {
    // CPU limpa
    CPU cpu;
    memset(&cpu, 0, sizeof(cpu));
    int MAX_REG = (sizeof(cpu.regs) / sizeof(cpu.regs[0])) - 1;
    uint64_t valueTest = 0x1234567890123456;

    // Testando leitura e escrita em registradores gerais (XZR não é testado aqui)
    for (int i = 0; i <= (MAX_REG - 1); i++) {
        reg_write(&cpu, i, valueTest);
        TEST_ASSERT_EQUAL_UINT64(valueTest, reg_read(&cpu, i));
    }

    // Teste XZR (escreve valor e deve retornar zero sempre)
    reg_write(&cpu, 31, valueTest);
    TEST_ASSERT_EQUAL_UINT64(0, reg_read(&cpu, 31));

    // Teste PC(32) e SP(33) (leitura e escrita)
    for (int i = 32; i <= 33; i++) {
        reg_write(&cpu, i, valueTest);
        TEST_ASSERT_EQUAL_UINT64(valueTest, reg_read(&cpu, i));
    }

    // Teste de limite de índice (leitura e escrita)
    reg_write(&cpu, -1, valueTest);  // Abaixo do índice
    TEST_ASSERT_EQUAL_UINT64(0, reg_read(&cpu, -1));
    reg_write(&cpu, 38, valueTest);  // Acima do índice
    TEST_ASSERT_EQUAL_UINT64(0, reg_read(&cpu, 38));
}

void test_nzcv(void) {
    CPU cpu;
    memset(&cpu, 0, sizeof(cpu));
    uint8_t nzcvValue = 0xFF;
    set_nzcv(&cpu, nzcvValue);
    TEST_ASSERT_EQUAL_UINT8(0xFF, get_nzcv(&cpu));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_encode_BNE);
    RUN_TEST(test_encode_BEQ);
    RUN_TEST(test_encode_branch);
    return UNITY_END();
}

void setUp(void) {}
void tearDown(void) {}
