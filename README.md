# Emulador AArch64

Emulador da arquitetura **ARMv8/v9 (AArch64)** desenvolvido em C11, seguindo o ISA real bit a bit.

## Estrutura

```
├── cpu/        # Registradores, PC, SP, flags NZCV
├── memory/     # Memória flat 128KB
├── decode/     # Decodificação por major group → subgrupo → instrução
│   ├── dpi/    # Data Processing Immediate
│   ├── dpr/    # Data Processing Register
│   ├── m/      # Load/Store
│   └── b/      # Branch
├── encode/     # Conversão mnemônico → 32 bits
│   └── builders/
│       └── builderDPI/
│           ├── dpi_Arithmetic/
│           ├── dpi_Logic/
│           ├── dpi_Move/
│           └── dpi_Shift/
├── execute/    # Engine de execução
├── tests/      # Unity Framework
└── main.c
```

## Build

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

## Documentação

Especificação técnica completa com mapeamento binário das instruções:
[docs.google.com/...](https://docs.google.com/document/d/1nCxWcpsC2XD4zM9s9ckRc43idRU_xRvVgKaxZFFLdBc/edit?usp=sharing)

## Licença

MIT License — Copyright (c) 2026 Marcos Aurelio