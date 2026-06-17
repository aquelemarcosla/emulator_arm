# Emulador ARMv8/v9 (AArch64)

Um emulador de CPU de arquitetura **ARM 64-bit** implementado em **C11**, com suporte completo ao conjunto de instruções ARMv8 básico. Segue a especificação ISA real com decodificação bit a bit.

## 🎯 Visão Geral

```
                    ASSEMBLY INPUT
                    "ADDI x0, x1, 100"
                           ↓
                    ┌──────────────┐
                    │   READER     │  (Lê do arquivo)
                    └──────────────┘
                           ↓
                    ┌──────────────┐
                    │   ENCODE     │  (Mnemônico → 32-bit)
                    └──────────────┘
                           ↓
                    ┌──────────────┐
                    │ PROG_TABLE   │  (Armazena bytecode)
                    └──────────────┘
                           ↓
        ╔═══════════ EXECUTION LOOP ════════════╗
        ║  ┌──────────────────────────────────┐ ║
        ║  │ DECODE: 32-bit → instruction    │ ║
        ║  └──────────────────────────────────┘ ║
        ║                 ↓                      ║
        ║  ┌──────────────────────────────────┐ ║
        ║  │ EXECUTE: instruction → resultado │ ║
        ║  └──────────────────────────────────┘ ║
        ║                 ↓                      ║
        ║  ┌──────────────────────────────────┐ ║
        ║  │ CPU STATE UPDATED                │ ║
        ║  │ (registradores, flags, PC, SP)   │ ║
        ║  └──────────────────────────────────┘ ║
        ╚════════════════════════════════════════╝
                           ↓
                    CPU STATE OUTPUT
```

## 📦 Estrutura do Projeto

```
emulador_arm/
├── cpu/                          # Estado da CPU (registradores, flags, PC, SP)
│   ├── cpu.h/c                  # Definição: 32 regs, PC, SP, NZCV
│   ├── registers_table/         # Mapear "x0" → índice 0
│   ├── labels_table/            # Mapear "loop:" → endereço
│   └── program_table/           # Armazenar instruções compiladas
│
├── memory/                       # Memória flat 128KB (131.072 bytes)
│   ├── memory.h/c              # mem_read() / mem_write()
│
├── decode/                       # Converter 32-bit → instruction struct
│   ├── decode.h/c              # Classificador (major groups)
│   └── buildersDecode/          # Decodificadores especializados
│       ├── dpi/                 # Data Processing Immediate
│       ├── dpr/                 # Data Processing Register
│       ├── m/                   # Memory Access (LDR/STR)
│       └── b/                   # Branch (B/B.cond)
│
├── encode/                       # Converter mnemônico → 32-bit
│   ├── encode.h/c              # Parser principal
│   ├── opcode_table/           # Lookup mnemônico → builder
│   └── builders/                # Construtores especializados
│       ├── builderDPI/         # Arit/Log/Mov/Shift
│       ├── builderDPR/         # Arit/Log/Shift (com registrador)
│       ├── builderM/           # LDR/STR
│       └── builderB/           # B/B.cond
│
├── execute/                      # Engine de execução ⚠️ [VAZIO]
│   ├── execute.h/c             # Implementar operações
│
├── reader/                       # Ler arquivo assembly
│   ├── reader.h/c
│
├── tests/                        # Testes unitários (Unity Framework)
│   └── test_cpu.c              # Suite de testes
│
├── main.c                        # Entry point (incompleto)
├── CMakeLists.txt              # Build system
└── README.md                    # Este arquivo
```

## 🏗️ Arquitetura em Camadas

### 1️⃣ **CPU** - Estado do Processador
- **32 registradores gerais** (x0-x31, 64-bit cada)
- **Program Counter** (PC = reg 32)
- **Stack Pointer** (SP = reg 33)
- **Flags NZCV** (Negative, Zero, Carry, oVerflow - 4-bit)

### 2️⃣ **Memória** - Espaço de Endereçamento
- **Tamanho:** 128 KB (131.072 bytes)
- **Tipo:** Flat, byte-addressable
- **API:** `mem_read(addr)` / `mem_write(addr, data)`

### 3️⃣ **Decode** - Conversão 32-bit → Instruction
Classifica instruções por **major group** (bits [28:25]):
- `100x` → **DPI** (Data Processing Immediate)
- `101x` → **B** (Branch)
- `x101` → **DPR** (Data Processing Register)
- `x1x0` → **M** (Memory Access)

### 4️⃣ **Encode** - Conversão Mnemônico → 32-bit
Parser com lookup em `OpcodeTable`:
1. Extrai mnemônico ("ADDI")
2. Busca builder correspondente
3. Builder parsa operandos e monta opcode

### 5️⃣ **Execute** - Execução de Instruções
**⚠️ VAZIO - A IMPLEMENTAR**

Deverá executar:
- Operações DPI (ADDI, SUBI, ANDI, MOVZ, UBFM, etc.)
- Operações DPR (ADD, SUB, AND, LSL, ROR, etc.)
- Memory Access (LDR, STR)
- Branch (B, B.cond)

## 📋 Instruções Suportadas

### ✅ Implementadas (Encode/Decode)

#### Data Processing Immediate (DPI)
| Operação | Mnemônico | Descrição |
|---|---|---|
| Aritmética | ADDI, SUBI | Adicionar/Subtrair imediato |
| | CMP | Comparar (atualiza flags) |
| Lógica | ANDI, ORRI, EORI | AND/OR/XOR imediato |
| Transferência | MOVZ, MOVN | Move com zero/NOT |
| Deslocamento | UBFM | Unsigned Bit Field Move |

#### Data Processing Register (DPR)
| Operação | Mnemônico | Descrição |
|---|---|---|
| Aritmética | ADD, SUB | Adicionar/Subtrair |
| | CMP | Comparar (atualiza flags) |
| Lógica | AND, ORR, EOR | AND/OR/XOR |
| Deslocamento | LSL, LSR, ASR, ROR | Shift/Rotate |

#### Memory Access (M)
| Operação | Mnemônico | Descrição |
|---|---|---|
| Carregamento | LDR | Load Register (64-bit) |
| | LDR (signed) | Load com extensão de sinal |
| Armazenamento | STR | Store Register |

#### Branch (B)
| Operação | Mnemônico | Descrição |
|---|---|---|
| Incondicional | B | Branch (26-bit offset) |
| Condicional | B.cond | Branch se condição atendida |

### 🟡 Estrutura Definida (Execute Vazio)
- Todas as decodificações prontas
- Builders de encode prontos
- **Falta:** Lógica de execução em `execute.c`

## 🚀 Build & Execução

### Pré-requisitos
- GCC/Clang com suporte C11
- CMake ≥ 3.20

### Compilar

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

**Produtos:**
- `emulador_arm` - Executável principal
- `tests` - Executável de testes (com Unity)

### Executar Testes

```bash
cd build
./tests
```

Ou no Windows:
```bash
.\tests.exe
```

### Executar Emulador

```bash
./emulador_arm
```

**Nota:** `main.c` está incompleto. Implementar loop de execução.

## 🔍 Exemplo de Fluxo

### Input: Assembly
```asm
ADDI x0, x1, 100
```

### 1️⃣ Encode
```
"ADDI x0, x1, 100"
    ↓
Lookup: "ADDI" → builderADDI
    ↓
Parse: rd=0, rn=1, imm=100
    ↓
Monta: 0x91000000 | (0) | (1<<5) | (100<<10)
    ↓
Resultado: 0x91019020
```

### 2️⃣ Decode
```
0x91019000
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
```
instruction { opcode: ADDI, rd: 0, rn: 1, imm: 100 }
    ↓
operando1 = CPU.regs[1]
operando2 = 100
    ↓
resultado = operando1 + operando2
    ↓
CPU.regs[0] = resultado
    ↓
Atualizar flags NZCV conforme necessário
    ↓
CPU.pc += 4 (próxima instrução)
```

## 📊 Estruturas de Dados Principais

### CPU
```c
typedef struct {
    uint64_t regs[32];  // R0-R31 (64-bit)
    uint64_t pc;        // Program Counter
    uint64_t sp;        // Stack Pointer
    uint8_t nzcv;       // Flags NZCV
} CPU;
```

### instruction (Decodificada)
```c
typedef struct {
    uint8_t opcode;     // ID da instrução
    uint8_t type;       // DPI, DPR, M, B
    uint8_t rd;         // Registrador destino
    uint8_t rn;         // Registrador operando 1
    uint8_t rm;         // Registrador operando 2
    int64_t imm;        // Imediato com sinal
} instruction;
```

### OpcodeTable (Lookup Encode)
```c
typedef struct {
    char *mnemonic;                    // "ADDI", "ADD", etc.
    uint32_t value;                    // Base opcode
    uint32_t (*builder)(uint32_t, char **);  // Function builder
} OpcodeTable;
```

## 🧪 Testes

### Framework
- **Unity** (ThrowTheSwitch/Unity)
- Integrado via FetchContent em CMakeLists.txt

### Rodar Testes
```bash
./tests
```

### Exemplo de Teste
```c
TEST_IGNORE_MESSAGE("Implementar execute");
TEST(cpu, test_addi_basic) {
    CPU cpu = {0};
    cpu.regs[1] = 10;
    
    instruction inst = { .opcode = ADDI, .rd = 0, .rn = 1, .imm = 5 };
    execute(&cpu, inst);
    
    TEST_ASSERT_EQUAL_INT(15, cpu.regs[0]);
}
```

## 📈 Status do Projeto

| Componente | Status | Notas |
|---|---|---|
| **CPU** | ✅ Implementado | Registradores, PC, SP, NZCV |
| **Memória** | ✅ Implementado | 128KB, read/write |
| **Decode** | ✅ Implementado | Major groups + builders especializados |
| **Encode** | ✅ Implementado | Builders para DPI, DPR, M, B |
| **Execute** | 🔴 VAZIO | **PRIORIDADE: Implementar** |
| **Reader** | 🟡 Parcial | Interface definida |
| **Main** | 🟡 Incompleto | Sem loop de execução |
| **Testes** | ✅ Framework | Unity integrado, testes básicos |

## 🎯 Próximos Passos

### 🔴 CRÍTICO

1. **Implementar `execute.c`**
   - [ ] Estrutura switch por tipo (DPI, DPR, M, B)
   - [ ] Operações aritméticas (ADD, SUB, CMP)
   - [ ] Operações lógicas (AND, OR, EOR)
   - [ ] Deslocamentos (LSL, LSR, ASR, ROR)
   - [ ] Memory Access (LDR, STR)
   - [ ] Branch (B, B.cond)
   - [ ] Atualizar flags NZCV

2. **Completar `main.c`**
   - [ ] Loop de execução
   - [ ] Carregamento de programa
   - [ ] Debugging/output

### 🟡 IMPORTANTE

3. **Validação**
   - [ ] Testes para cada instrução
   - [ ] Testes de flags
   - [ ] Testes de memória

4. **Integração**
   - [ ] Reader funcional
   - [ ] Program table integrada

### 🟢 OPCIONAL

5. **Otimizações**
   - [ ] JIT compilation
   - [ ] Cache de decodificação
   - [ ] Profiling de performance

## 📚 Referências Técnicas

### Flags NZCV
| Flag | Bit | Significado |
|---|---|---|
| **N** | 3 | Negative (resultado < 0) |
| **Z** | 2 | Zero (resultado = 0) |
| **C** | 1 | Carry (overflow unsigned) |
| **V** | 0 | oVerflow (overflow signed) |

### Mapeamento de Registradores
- `x0` - `x30` - General purpose (64-bit)
- `sp` (x31) - Stack Pointer
- `pc` (reg 32) - Program Counter
- `lr` (x30) - Link Register

### Formato de Instruções (32-bit)

#### DPI (Data Processing Immediate)
```
[31:30] = opcode
[28:23] = subgrupo
[21:10] = imm12
[9:5]   = Rn
[4:0]   = Rd
```

#### DPR (Data Processing Register)
```
[31:30] = opcode
[28:23] = subgrupo
[20:16] = Rm
[15:10] = shift
[9:5]   = Rn
[4:0]   = Rd
```

#### Memory (Load/Store)
```
[31:30] = opcode
[28:26] = tipo
[20:12] = offset
[9:5]   = Rn (base)
[4:0]   = Rd
```

#### Branch
```
[31:26] = tipo
[25:0]  = offset (incondicional)
[23:5]  = offset (condicional)
[3:0]   = condição
```

## 🔗 Documentação Completa

Especificação técnica com decodificação completa:
[Google Docs - Especificação ARMv8](https://docs.google.com/document/d/1nCxWcpsC2XD4zM9s9ckRc43idRU_xRvVgKaxZFFLdBc/edit?usp=sharing)

Mapa completo do projeto:
`~/.copilot/session-state/.../MAPA_COMPLETO.md`

## 📝 Licença

MIT License — Copyright (c) 2026 Marcos Aurelio

---

## 🤝 Contribuindo

Este é um projeto educacional. Para contribuir:

1. Implementar `execute.c` com operações básicas
2. Expandir testes em `test_cpu.c`
3. Adicionar suporte para mais instruções ARMv8
4. Melhorar documentação

---

**Última atualização:** 2026-06-17
**Status Geral:** Estrutura completa, execução em desenvolvimento ⚠️