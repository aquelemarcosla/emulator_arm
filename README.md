Emulador AArch64 em C

Emulador da arquitetura ARMv8/v9 (AArch64) desenvolvido em C, com foco em compreensão prática de execução de instruções, organização interna da CPU e separação entre etapas como decode e execute.

DOCUMENTAÇÃO (em desenvolvimento):
https://docs.google.com/document/d/1nCxWcpsC2XD4zM9s9ckRc43idRU_xRvVgKaxZFFLdBc/edit?usp=sharing

Sobre o projeto

Este projeto tem como objetivo implementar, de forma explícita, o funcionamento básico de uma CPU AArch64, incluindo:

Decode manual de instruções
Modelagem de registradores
Separação entre etapas de execução (decode / execute)
Organização de memória
Testes unitários para validação de comportamento da CPU

A proposta não é abstrair o funcionamento, mas expor as decisões e estruturas envolvidas na execução de instruções em baixo nível.

O projeto está em evolução contínua e novos conjuntos de instruções e melhorias estruturais estão sendo adicionados progressivamente.

Desafios técnicos

Alguns dos pontos centrais durante o desenvolvimento:

Representação consistente de estados da CPU e registradores
Separação clara entre decode e execução de instruções
Estruturação do código para permitir expansão do conjunto de instruções
Garantia de comportamento previsível através de testes
Sobre o autor

Sou estudante de engenharia de computação e tenho interesse em sistemas de baixo nível, arquitetura de computadores e execução bare-metal.

Meu foco atual é entender, na prática, como instruções são interpretadas e executadas, saindo de camadas mais abstratas e lidando diretamente com o funcionamento da máquina.
