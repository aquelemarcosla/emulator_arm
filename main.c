#include <stdio.h>
#include <string.h>

#include "cpu/cpu.h"
#include "cpu/program_table/program_table.h"
#include "decode/decode.h"
#include "reader/reader.h"
#include "execute/execute.h"

void print_cpu_state(CPU *cpu) {
    printf("\n--- CPU STATE ---\n");
    for (int i = 0; i < 32; i++) {
        printf("R%-2d = 0x%016llX\n", i, cpu->regs[i]);
    }
    printf("PC  = 0x%016llX\n", cpu->pc);
    printf("SP  = 0x%016llX\n", cpu->sp);
    printf("NZCV = N:%d Z:%d C:%d V:%d\n",
        (cpu->nzcv >> 3) & 1,
        (cpu->nzcv >> 2) & 1,
        (cpu->nzcv >> 1) & 1,
        (cpu->nzcv >> 0) & 1);
    printf("-----------------\n");
}

int main(void) {
    // Init CPU.
    CPU cpu = {0};
    reg_write(&cpu, 33, 0x1FFFF);  // Setting SP.

    char code[50];
    Instruction inst = {0};

    printf("Code: ");

    fgets(code, sizeof(code), stdin);

    code[strcspn(code, "\n")] = '\0';

    reader(code);

    inst = decode(getInstruction(1));

    execute(inst, &cpu);

    print_cpu_state(&cpu);
}
