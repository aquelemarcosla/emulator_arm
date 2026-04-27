#include <string.h>
#include "unity.h"
#include "../cpu/cpu.h"

void test_reg_read_and_write(void) {
    //  CPU LIMPA
    CPU cpu;
    memset(&cpu, 0, sizeof(cpu));
    int MAX_REG = (sizeof(cpu.regs) / sizeof(cpu.regs[0])) - 1;
    uint64_t valueComparation = 0x1234567890123456;

    // TESTANDO LEITURA E ESCRITA EM TODOS OS REGISTRADORES GERAIS (31 == 0  não é testado aqui)
    for (int i = 0; i <= (MAX_REG - 1); i++) {
        reg_write(&cpu, i, valueComparation);
        TEST_ASSERT_EQUAL_UINT64(valueComparation, reg_read(&cpu, i));
    }

    // TESTE ZXR (Escreve valor e deve retornar zero sempre)
    reg_write(&cpu, 31, valueComparation);
    TEST_ASSERT_EQUAL_UINT64(0, reg_read(&cpu, 31));

    // TESTE PC(32) E SP(33) (Leitura e escrita)
    for (int i = 32; i <= 33; i++) {
        reg_write(&cpu, i, valueComparation);
        TEST_ASSERT_EQUAL_UINT64(valueComparation, reg_read(&cpu, i));
    }
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_reg_read_and_write);
    return UNITY_END();
}

void setUp(void) {}
void tearDown(void) {}