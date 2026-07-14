#include "builderDPI_L.h"

#include "stdint.h"
#include "encode/buildersEncode/buildersEncode.h"

#define MOVE_BITS(data, mask, shift) (((uint32_t)(data) & (mask)) << (shift))

static uint16_t encodeLogicalImmediate(uint64_t imm) {
    uint32_t size = 64;
    while (size > 2) {
        uint32_t half = size / 2;
        uint64_t mask = (1ULL << half) - 1;
        if ((imm & mask) != ((imm >> half) & mask)) break;
        size = half;
    }

    uint64_t mask = (size == 64) ? ~0ULL : (1ULL << size) - 1;
    uint64_t elem = imm & mask;

    uint32_t r = 0;
    uint64_t rotated = elem;
    while (r < size) {
        rotated = (r == 0) ? elem : ((elem >> r) | (elem << (size - r))) & mask;
        if (rotated != 0 && (rotated & (rotated + 1)) == 0) break;
        r++;
    }

    uint32_t s = 0;
    uint64_t ones = rotated;
    while (ones & 1) {
        s++;
        ones >>= 1;
    }

    uint32_t n = (size == 64) ? 1 : 0;
    uint32_t immr = (size - r) & (size - 1);
    uint32_t imms = (uint32_t)(((~(uint64_t)(size - 1)) << 1) & 0x3F) | (s - 1);

    return (uint16_t)((n << 12) | (immr << 6) | imms);
}

uint32_t builderANDI(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint64_t imm;
    uint16_t imm13;
    uint8_t rn;
    uint8_t rd;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    imm = find_immediate(saveptr);
    imm13 = encodeLogicalImmediate(imm);

    instructionExit |= MOVE_BITS(value, 0xFFF, 23);
    instructionExit |= MOVE_BITS(imm13, 0x1FFF, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);

    return instructionExit;
}

// ORRI Rd, Rn, #imm
uint32_t builderORRI(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint64_t imm;
    uint16_t imm13;
    uint8_t rn;
    uint8_t rd;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    imm = find_immediate(saveptr);
    imm13 = encodeLogicalImmediate(imm);

    instructionExit |= MOVE_BITS(value, 0xFFF, 23);
    instructionExit |= MOVE_BITS(imm13, 0x1FFF, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);

    return instructionExit;
}

// EORI Rd, Rn, #imm
uint32_t builderEORI(uint32_t value, char **saveptr) {
    uint32_t instructionExit = 0;
    uint64_t imm;
    uint16_t imm13;
    uint8_t rn;
    uint8_t rd;

    rd = find_register(saveptr);
    rn = find_register(saveptr);
    imm = find_immediate(saveptr);
    imm13 = encodeLogicalImmediate(imm);

    instructionExit |= MOVE_BITS(value, 0xFFF, 23);
    instructionExit |= MOVE_BITS(imm13, 0x1FFF, 10);
    instructionExit |= MOVE_BITS(rn, 0x1F, 5);
    instructionExit |= MOVE_BITS(rd, 0x1F, 0);

    return instructionExit;
}