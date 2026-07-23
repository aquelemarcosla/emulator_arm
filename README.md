# ARM Emulator (AArch64) — C11

> **⚠️ In development:** the project does not yet run end-to-end programs.  
> The **encode/decode** pipeline exists, but the **execute** stage is still incomplete.

Educational 64-bit ARM architecture emulator focused on instruction representation, assembly (text → opcode), and disassembly (opcode → struct).

## Current status

| Component | Status | Notes                                                 |
| --- | --- |-------------------------------------------------------|
| CPU (`cpu/`) | ✅ | Registers, PC, SP, and NZCV                           |
| Memory (`memory/`) | ✅ | Flat 128 KB model                                     |
| Encode (`encode/`) | ✅ | DPI, DPR, memory, and branch builders                 |
| Decode (`decode/`) | ✅ | Group classification + builders                       |
| Reader (`reader/`) | 🟡 | Processes text lines (not a full file/program loader) |
| Execute (`execute/`) | 🟡 | Parcial, some instructions are completed              |
| `main.c` | 🔴 | No emulator execution loop yet                        |

## What already works

### Encode (assembly text → 32-bit instruction)

Mnemonics currently available in the opcode table:

- **DPI:** `ADDI`, `SUBI`, `CMPI`, `ANDI`, `ORRI`, `EORI`, `MOVZ`, `MOVN`, `LSL`, `LSR`
- **DPR:** `ADD`, `SUB`, `AND`, `ORR`, `EOR`, `LSLV`, `LSRV`
- **Memory:** `LDR`, `STR`
- **Branch/System:** `B`, `BL`, `RET`, `BEQ`, `BNE`

### Decode (32-bit instruction → `Instruction`)

Support is implemented for the same groups above (DPI, DPR, memory, and branch), with field extraction (`type`, `rd`, `rn`, `rm`, `imm`).

## Explicit gaps and limitations

1. **No complete flow in `main`:** there is no integrated fetch/decode/execute cycle.
2. **Partial reader:** it does not provide a full program loading/execution pipeline.
3. **Known failing tests:** there are current inconsistencies in immediate logical decode cases (`ANDI`, `ORRI`, `EORI`).

## Project structure

```text
emulator_arm/
├── cpu/
├── memory/
├── encode/
├── decode/
├── execute/
├── reader/
├── tests/
├── main.c
└── CMakeLists.txt
```

## Build and run

Requirements:

- CMake >= 3.20
- GCC/Clang com C11

Build:

```bash
cmake -S . -B build
cmake --build build
```

Generated binaries (Windows):

- `build\emulator_arm.exe`
- `build\tests.exe`

Run tests:

```bash
.\build\tests.exe
```

Run main executable:

```bash
.\build\emulator_arm.exe
```

> **Note:** the main binary compiles, but it still does not represent a complete emulator due to the gaps described above.

## Core structures

```c
typedef struct {
    uint64_t regs[32];
    uint64_t pc;
    uint64_t sp;
    uint8_t nzcv;
} CPU;

typedef struct {
    uint8_t type;
    uint8_t rd;
    uint8_t rn;
    uint8_t rm;
    int64_t imm;
} Instruction;
```

## License

MIT License.
