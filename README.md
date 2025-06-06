# Analisador de Instruções RISC-V em Hexadecimal

Este projeto consiste em um programa C++ que lê arquivos contendo instruções RISC-V em formato hexadecimal, identifica o tipo de cada instrução e gera um relatório detalhado.

## Funcionalidades

- Lê arquivos de texto com instruções hexadecimais (ex: `instrucoes1.hex`).
- Identifica o tipo da instrução com base no opcode (tipos: R, I, S, B, U, J).
- Gera um arquivo de relatório com:
  - Cada instrução e seu respectivo tipo.
  - Um resumo com a contagem de instruções por tipo.

## Como usar

1. Prepare os arquivos `.hex` contendo as instruções, um por linha.
2. Configure a lista de arquivos a serem processados no vetor `arquivos` dentro do `main()`.
3. Compile o programa com um compilador compatível C++11 ou superior.
4. Execute o programa; ele criará um arquivo de relatório para cada arquivo de entrada, nomeado como `<nome>_relatorio.txt`.

## Tecnologias

- Linguagem: C++
- Manipulação de arquivos via `ifstream` e `ofstream`
- Utilização de `std::map` para contagem de tipos de instruções
