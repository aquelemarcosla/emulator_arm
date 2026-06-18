# ARMv8/v9 Emulator (AArch64)

A **64-bit ARM architecture CPU emulator** implemented in **C11**, featuring support for the core ARMv8 instruction set. The project follows the real ISA specification with bit-level instruction decoding.

## 🎯 Overview

```
                    ASSEMBLY INPUT
                    "ADDI x0, x1, 100"
                           ↓
                    ┌──────────────┐
                    │    READER    │  (Reads from file)
                    └──────────────┘
                           ↓
                    ┌──────────────┐
                    │    ENCODE    │  (Mnemonic → 32-bit)
                    └──────────────┘
                           ↓
                    ┌──────────────┐
                    │ PROG_TABLE   │  (Stores bytecode)
                    └──────────────┘
                           ↓
        ╔═══════════ EXECUTION LOOP ═══════════╗
        ║  ┌─────────────────────────────────┐ ║
        ║  │ DECODE: 32-bit → instruction    │ ║
        ║  └─────────────────────────────────┘ ║
        ║                 ↓                     ║
        ║  ┌─────────────────────────────────┐ ║
        ║  │ EXECUTE: instruction → result   │ ║
        ║  └─────────────────────────────────┘ ║
        ║                 ↓                     ║
        ║  ┌─────────────────────────────────┐ ║
        ║  │ CPU STATE UPDATED               │ ║
        ║  │ (registers, flags, PC, SP)      │ ║
        ║  └─────────────────────────────────┘ ║
        ╚═══════════════════════════════════════╝
                           ↓
                    CPU STATE OUTPUT
```

## 📦 Project Structure

```
emulator_arm/
├── cpu/                          # CPU state (registers, flags, PC, SP)
│   ├── cpu.h/c                   # Definition: 32 registers, PC, SP, NZCV
│   ├── registers_table/          # Maps "x0" → index 0
│   ├── labels_table/             # Maps "loop:" → address
│   └── program_table/            # Stores compiled instructions
│
├── memory/                       # Flat memory model (128 KB)
│   ├── memory.h/c                # mem_read() / mem_write()
│
├── decode/                       # Convert 32-bit → instruction struct
│   ├── decode.h/c                # Instruction classifier
│   └── buildersDecode/           # Specialized decoders
│       ├── dpi/                  # Data Processing Immediate
│       ├── dpr/                  # Data Processing Register
│       ├── m/                    # Memory Access (LDR/STR)
│       └── b/                    # Branch (B/B.cond)
│
├── encode/                       # Convert mnemonic → 32-bit
│   ├── encode.h/c                # Main parser
│   ├── opcode_table/             # Mnemonic → builder lookup
│   └── builders/                 # Specialized builders
│       ├── builderDPI/           # Arithmetic/Logic/Move/Shift
│       ├── builderDPR/           # Register-based operations
│       ├── builderM/             # LDR/STR
│       └── builderB/             # B/B.cond
│
├── execute/                      # Execution engine ⚠️ [EMPTY]
│   ├── execute.h/c               # Instruction execution logic
│
├── reader/                       # Assembly file reader
│   ├── reader.h/c
│
├── tests/                        # Unit tests (Unity Framework)
│   └── test_cpu.c
│
├── main.c                        # Entry point (incomplete)
├── CMakeLists.txt                # Build system
└── README.md
```

## 🏗️ Layered Architecture

### 1️⃣ CPU – Processor State

* **32 general-purpose registers** (x0–x31, 64-bit)
* **Program Counter** (PC)
* **Stack Pointer** (SP)
* **NZCV Flags** (Negative, Zero, Carry, Overflow)

### 2️⃣ Memory – Address Space

* **Size:** 128 KB (131,072 bytes)
* **Type:** Flat, byte-addressable memory
* **API:** `mem_read(addr)` / `mem_write(addr, data)`

### 3️⃣ Decode – 32-bit → Instruction

Instructions are classified by **major group** (bits [28:25]):

* `100x` → **DPI** (Data Processing Immediate)
* `101x` → **B** (Branch)
* `x101` → **DPR** (Data Processing Register)
* `x1x0` → **M** (Memory Access)

### 4️⃣ Encode – Mnemonic → 32-bit

Parser workflow using `OpcodeTable`:

1. Extract mnemonic (`"ADDI"`)
2. Find the corresponding builder
3. Parse operands and build the opcode

### 5️⃣ Execute – Instruction Execution

⚠️ **Not yet implemented**

Planned support:

* DPI operations (ADDI, SUBI, ANDI, MOVZ, UBFM, etc.)
* DPR operations (ADD, SUB, AND, LSL, ROR, etc.)
* Memory access (LDR, STR)
* Branch instructions (B, B.cond)

## 📋 Supported Instructions

### ✅ Implemented (Encode/Decode)

#### Data Processing Immediate (DPI)

| Operation  | Mnemonic         | Description             |
| ---------- | ---------------- | ----------------------- |
| Arithmetic | ADDI, SUBI       | Add/Subtract Immediate  |
|            | CMP              | Compare (updates flags) |
| Logical    | ANDI, ORRI, EORI | Immediate AND/OR/XOR    |
| Move       | MOVZ, MOVN       | Move with Zero / NOT    |
| Shift      | UBFM             | Unsigned Bit Field Move |

#### Data Processing Register (DPR)

| Operation  | Mnemonic           | Description             |
| ---------- | ------------------ | ----------------------- |
| Arithmetic | ADD, SUB           | Add/Subtract            |
|            | CMP                | Compare (updates flags) |
| Logical    | AND, ORR, EOR      | AND/OR/XOR              |
| Shift      | LSL, LSR, ASR, ROR | Shift/Rotate            |

#### Memory Access

| Operation | Mnemonic     | Description              |
| --------- | ------------ | ------------------------ |
| Load      | LDR          | Load Register (64-bit)   |
|           | LDR (signed) | Load with sign extension |
| Store     | STR          | Store Register           |

#### Branch

| Operation     | Mnemonic | Description            |
| ------------- | -------- | ---------------------- |
| Unconditional | B        | Branch (26-bit offset) |
| Conditional   | B.cond   | Conditional branch     |

### 🟡 Structure Defined (Execution Missing)

* All instruction decoders implemented
* All encoding builders implemented
* Execution logic pending implementation

## 🚀 Build & Run

### Requirements

* GCC or Clang with C11 support
* CMake ≥ 3.20

### Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Generated binaries:

* `emulator_arm` — Main executable
* `tests` — Unit test executable (Unity)

### Run Tests

```bash
cd build
./tests
```

Windows:

```bash
.\tests.exe
```

### Run Emulator

```bash
./emulator_arm
```

**Note:** `main.c` is currently incomplete and does not yet contain the execution loop.

## 🔍 Example Workflow

### Assembly Input

```asm
ADDI x0, x1, 100
```

### 1️⃣ Encode

```text
"ADDI x0, x1, 100"
    ↓
Lookup: "ADDI" → builderADDI
    ↓
Parse: rd=0, rn=1, imm=100
    ↓
Build: 0x91000000 | (0) | (1<<5) | (100<<10)
    ↓
Result: 0x91019020
```

### 2️⃣ Decode

```text
0x91019020
    ↓
Bits [28:25] = 0x9 (100x) → DPI
    ↓
Bits [30:29] = 0x0 → ADDI
    ↓
Parse: rd=0, rn=1, imm=100
    ↓
instruction { opcode: ADDI, rd: 0, rn: 1, imm: 100 }
```

### 3️⃣ Execute (TODO)

```text
instruction { opcode: ADDI, rd: 0, rn: 1, imm: 100 }
    ↓
operand1 = CPU.regs[1]
operand2 = 100
    ↓
result = operand1 + operand2
    ↓
CPU.regs[0] = result
    ↓
Update NZCV flags if required
    ↓
CPU.pc += 4
```

## 📊 Core Data Structures

### CPU

```c
typedef struct {
    uint64_t regs[32];
    uint64_t pc;
    uint64_t sp;
    uint8_t nzcv;
} CPU;
```

### Decoded Instruction

```c
typedef struct {
    uint8_t opcode;
    uint8_t type;
    uint8_t rd;
    uint8_t rn;
    uint8_t rm;
    int64_t imm;
} instruction;
```

### OpcodeTable

```c
typedef struct {
    char *mnemonic;
    uint32_t value;
    uint32_t (*builder)(uint32_t, char **);
} OpcodeTable;
```

## 🧪 Testing

### Framework

* **Unity** (ThrowTheSwitch/Unity)
* Integrated through CMake FetchContent

### Example Test

```c
TEST_IGNORE_MESSAGE("Implement execute");
TEST(cpu, test_addi_basic) {
    CPU cpu = {0};
    cpu.regs[1] = 10;

    instruction inst = {
        .opcode = ADDI,
        .rd = 0,
        .rn = 1,
        .imm = 5
    };

    execute(&cpu, inst);

    TEST_ASSERT_EQUAL_INT(15, cpu.regs[0]);
}
```

## 📈 Project Status

| Component | Status        | Notes                               |
| --------- | ------------- | ----------------------------------- |
| CPU       | ✅ Implemented | Registers, PC, SP, NZCV             |
| Memory    | ✅ Implemented | 128 KB, read/write                  |
| Decode    | ✅ Implemented | Major groups + specialized builders |
| Encode    | ✅ Implemented | DPI, DPR, M, B builders             |
| Execute   | 🔴 Empty      | Priority implementation             |
| Reader    | 🟡 Partial    | Interface defined                   |
| Main      | 🟡 Incomplete | No execution loop                   |
| Tests     | ✅ Available   | Unity integrated                    |

## 🎯 Next Steps

### 🔴 Critical

1. Implement `execute.c`

   * Arithmetic operations
   * Logical operations
   * Shift operations
   * Memory access
   * Branch handling
   * NZCV updates

2. Complete `main.c`

   * Execution loop
   * Program loading
   * Debugging/output support

### 🟡 Important

3. Validation

   * Instruction tests
   * Flag tests
   * Memory tests

4. Integration

   * Functional reader
   * Program table integration

### 🟢 Optional

5. Optimizations

   * JIT compilation
   * Decode cache
   * Performance profiling

## 📚 Technical References

### NZCV Flags

| Flag | Bit | Meaning  |
| ---- | --- | -------- |
| N    | 3   | Negative |
| Z    | 2   | Zero     |
| C    | 1   | Carry    |
| V    | 0   | Overflow |

### Register Mapping

* `x0`–`x30` — General-purpose registers
* `sp` (`x31`) — Stack Pointer
* `pc` — Program Counter
* `lr` (`x30`) — Link Register

## 📝 License

MIT License — Copyright (c) 2026 Marcos Aurelio

## 🤝 Contributing

Contributions are welcome:

1. Implement `execute.c`
2. Expand unit tests
3. Add support for additional ARMv8 instructions
4. Improve documentation

---

**Last Updated:** 2026-06-17
**Project Status:** Core architecture complete, execution engine under development ⚠️
