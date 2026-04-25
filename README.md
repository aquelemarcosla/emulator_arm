# Emulador Aarch64 em C

## Documentação disponível em https://docs.google.com/document/d/1nCxWcpsC2XD4zM9s9ckRc43idRU_xRvVgKaxZFFLdBc/edit?usp=sharing

# ESTE DOCUMENTO ESTÁ EM CONSTANTE ALTERAÇÃO, NÃO SE TRATA DE UM DOCUMENTO FINAL.

Emulador Aarch64 (ARMv8/v9)
Sobre

Este projeto está sendo desenvolvido para consolidação e aplicação prática dos conhecimentos adquiridos sobre arquitetura de computadores e desenvolvimento de sistemas de baixo nível.

Neste projeto será desenvolvido um emulador da arquitetura ARMv8/v9 seguindo o padrão ISA Aarch64 como instrução padronizada. A tecnologia escolhida a princípio foi a linguagem C11 e pode sofrer alterações futuras conforme necessidades.

Este documento visa estabelecer regras e as normas do planejamento, tratará sobre a estrutura de cada componente e regras de aplicação que deverão ser seguidas ou referenciadas.

Estrutura Virtual
Registradores

Seguindo o padrão da arquitetura, teremos 32 registradores de propósito geral administrados conforme a norma ABI de organização. E outros registradores extras para funcionamento e outras normas. Todos os registradores terão 64 bits e modo de operação que permite trabalhar com apenas metade, 32 bits, trabalhando com a extensão em zero para preenchimento.

Nomenclatura
Registradores X0 a X31 - Uso geral (32)
Registrador PC - Program Counter (Separado)
Registrador SP - Stack Pointer (Separado)
Norma ABI para registradores de propósito geral (X0 - X31)

A norma ABI (Application Binary Interface) estabelece um padrão sólido e que estabelece o uso dos registradores de modo que a organização e leitura seja facilitada. Nessa arquitetura são eles:

X0 - X07 | Argumentos / retorno de funções
X8 | Resultado indireto (Permite retornos extensos)
X9 - X15 | Temporários (Caller-Saved, se estiver em uso é responsabilidade do chamador salvar o dado antes do branch)
X16 - X17 | Reservados pelo Linker
X18 | Reservado pelo Sistema Operacional
X19 - X28 | Salvos (Callee-Saved, salvos sempre devem ser preservados em funções caso necessidade do uso)
X29 (FP) | Frame Pointer
X30 (LR) | Link Register (Endereço de retorno da instrução BL)
X31 (XZR) | Registrador zerado de somente leitura
Memória
Especificação Geral

O tamanho da memória será de 128KB podendo sofrer alterações conforme necessidade e escolha de projeto. A memória escolhida e inspirada na arquitetura original é a memória não segmentada (flat), uma memória linear do começo ao fim. As células virtualizadas terão o tamanho de 1 byte (8 bits) cada, seguindo o padrão de alinhamento que deve ser múltiplo ao tamanho do dado acessado como navegação em offset.

Abordagem de como será implementada no capítulo de implementação.

Instruções
Mala de instruções

Instruções escolhidas para serem implementadas, a escolha foi pensada na viabilidade de a execução de um programa real mas deixando o emulador mais enxuto em comparação ao hardware real, poderão ser adicionadas instruções conforme necessidade do projeto.

Aritmética: MOV, ADD, SUB, MUL
Memória: LDR, STR
Controle: CMP, B, BL, RET
Lógica/Shift: AND, ORR, EOR, LSL, LSR

Todas as instruções são baseadas no hardware real da arquitetura ARMv8/v9 e serão implementadas seguindo a lógica original.

Estrutura das instruções

Aqui é demonstrado a estrutura de cada instrução, cada parte dos 32 bits das instruções e sua respectiva nomenclatura acompanhado de sua posição em bit entre colchetes, também terá a quantidade em bits em parênteses.

Instruções de tipo R:
OPCODE [31:21] (11 bits)
RM [20:16] (5 bits)
IGNORA [15:10] (6 bits)
RN [9:5] (5 bits)
RD [4:0] (5 bits)
Instruções de tipo I:
OPCODE [31:23] (9 bits)
IGNORA [22:21] (2 bits)
IMEDIATO [20:10] (11 bits)
RN [9:5] (5 bits)
RD [4:0] (5 bits)
Instruções de tipo B:
OPCODE [31:26] (6 bits)
IMEDIATO [25:0] (26 bits)

Todos os detalhes de implementação estarão no capítulo de implementação.

Ciclo de execução

Vai ser adotado o ciclo de execução semelhante ao do hardware real, retirando somente a parte de paralelismo do pipeline, onde enquanto uma instrução é executada outra já está sendo buscada no PC (Program Counter).

Ciclo:
Busca (Fetch) -> Decodificação (Decode) -> Execução (Execute)

Todos os detalhes de implementação estarão no capítulo de implementação.

Implementação

Neste capítulo serão abordadas as decisões de implementação da estrutura do emulador ARM em C, soluções, decisões, implementação prática e etc.

Código fonte está hospedado em:
https://github.com/aquelemarcosla/emulador_arm

Ficha Técnica

Neste projeto será usada a linguagem de programação C em versão C11, a escolha foi feita a partir da compatibilidade da usabilidade da versão C11 com o projeto. Exemplos de uso que a versão C99 não disponibilizaria:

Threads

A funcionalidade threads do C11 permite utilizar uma segunda thread enquanto a primeira se encontra em espera, aumentando o desempenho total já que permite um uso completo da CPU a depender de como for implementado.

É uma funcionalidade extra que poderá ou não ser implementada conforme necessidade. Um detalhe importante é que essa feature do C11 não será utilizada para a funcionalidade abstrata do emulador em si e sim para aumentar o seu desempenho geral.

Átomos

O C11 trouxe uma feature que usada com a funcionalidade Thread permite que duas threads possam atualizar uma mesma variável, mantendo assim o contexto e evitando perda de atualização entre processos.

Static Assert (_Static_assert)

Com o C11 podemos “quebrar” o build caso algo esteja errado, permitindo que suposições falsas nem sejam compiladas.

Como mencionado, nenhuma dessas features da linguagem C11 será implementada para funcionalidade do emulador e sim para otimização de execução da estrutura virtual.

CPU

Código bruto do header cpu.h

#ifndef
#include

