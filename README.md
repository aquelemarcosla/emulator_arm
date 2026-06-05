# 🔧 Emulador AArch64 em C

Um emulador de arquitetura **ARMv8/v9 (AArch64)** desenvolvido em C, com foco em compreensão prática de execução de instruções, organização interna da CPU e separação clara entre etapas de processamento.

## 📋 Visão Geral

Este projeto implementa um emulador funcional da arquitetura ARM 64-bit, permitindo:
- ✅ Decodificação de instruções ARMv8/v9
- ✅ Execução controlada de operações
- ✅ Gerenciamento de estado da CPU (registradores, flags)
- ✅ Simulação de memória

## 🏗️ Arquitetura do Projeto

```
├── cpu/              # Núcleo da CPU (registradores, flags NZCV)
├── memory/           # Gerenciamento de memória
├── decode/           # Decodificação de instruções
│   ├── dpi/         # Instruções Data Processing Immediate
│   ├── dpr/         # Instruções Data Processing Register
│   ├── m/           # Instruções Load/Store Memory
│   └── b/           # Instruções Branch
├── encode/           # Codificação de instruções
│   └── builders/
│       └── builderDPI/
│           ├── dpi_Arithmetic/  # ADDI, SUBI, CMPI
│           ├── dpi_Logic/       # ANDI, ORRI, EORI
│           └── dpi_Move/        # MOVZ, MOVN (instruções de movimento)
├── execute/          # Execução de instruções
├── tests/            # Suite de testes (Unity framework)
└── main.c            # Ponto de entrada
```

## 🛠️ Requisitos

- **CMake** >= 3.20
- **Compilador C** com suporte a C11 (GCC, Clang ou MSVC)
- **Framework de testes**: Unity (baixado automaticamente via FetchContent)

## 🚀 Build e Execução

### Compilar o projeto

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### Executar o emulador

```bash
./emulador_arm
```

### Executar testes

```bash
./tests
```

## 📚 Documentação

**Documentação completa** (em desenvolvimento):
📖 [Acesse a documentação detalhada](https://docs.google.com/document/d/1nCxWcpsC2XD4zM9s9ckRc43idRU_xRvVgKaxZFFLdBc/edit?usp=sharing)

A documentação contém:
- Especificação de instruções suportadas
- Pipeline de execução
- Formato de instruções ARMv8/v9
- Exemplos de uso

## 📋 Estrutura da CPU

### Registradores
- **x0-x31**: 32 registradores de propósito geral (64-bit)
- **PC**: Program Counter
- **SP**: Stack Pointer
- **NZCV**: Flags (Negative, Zero, Carry, oVerflow)

### Formato de Instrução
```c
typedef struct {
    uint8_t opcode;   // Código da operação
    uint8_t type;     // Tipo de instrução
    uint8_t rd;       // Registrador de destino
    uint8_t rn;       // Registrador operando 1
    uint8_t rm;       // Registrador operando 2
    int64_t imm;      // Valor imediato
} instruction;
```

## 📜 Licença

MIT License - Copyright (c) 2026 Marcos Aurelio

Veja o arquivo [LICENSE](LICENSE) para detalhes completos.
