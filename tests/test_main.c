#include "unity.h"

// Test CPU.
void test_reg_read_and_write(void);
void test_nzcv(void);

// Data Processing Immediate (DPI)
void test_encode_BNE(void);
void test_encode_BEQ(void);
void test_encode_Branch(void);
// Test encode DPI_A
void test_encode_ADDI(void);
void test_encode_SUBI(void);
void test_encode_CMPI(void);
// Test encode DPI_L
void test_encode_ANDI(void);
void test_encode_ORRI(void);
void test_encode_EORI(void);
// Test encode DPI_Move
void test_encode_MOVZ(void);
void test_encode_MOVN(void);
// Test encode DPI_Shift
void test_encode_LSL(void);
void test_encode_LSR(void);

// Data Processing Register (DPR)
void test_encode_dpr_LSLV(void);
void test_encode_dpr_LSRV(void);
// Test encode DPR_A
void test_encode_dpr_ADD(void);
void test_encode_dpr_SUB(void);
// Test encode DPR_L
void test_encode_dpr_AND(void);
void test_encode_dpr_ORR(void);
void test_encode_dpr_EOR(void);

// Test encode Memory
void test_encode_m_LDR(void);
void test_encode_m_STR(void);

//Test decode (DPI)
void test_decode_SUBI(void);
void test_decode_CMP(void);
void test_decode_ANDI(void);
void test_decode_ORRI(void);
void test_decode_EORI(void);
void test_decode_MOVZ(void);
void test_decode_MOVN(void);
void test_decode_UBFM(void);

//Test decode (Branchs)
void test_decode_B(void);
void test_decode_BL(void);
void test_decode_RET(void);
void test_decode_BEQ(void);
void test_decode_BNE(void);

void setUp(void){}
void tearDown(void){}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_decode_BL);
    RUN_TEST(test_decode_RET);
    RUN_TEST(test_decode_BEQ);
    RUN_TEST(test_decode_BNE);
    UNITY_END();
}
