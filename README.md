# Exercícios de Recursividade em C

Este projeto contém três exercícios desenvolvidos em linguagem C, com foco no uso de recursividade.

Os exercícios abordam:

1. Fibonacci recursivo sem otimização;
2. Fibonacci com memoização e alocação dinâmica;
3. Torres de Hanoi.

---

## 1. Fibonacci Recursivo sem Otimização

O primeiro programa calcula um termo da sequência de Fibonacci utilizando recursão simples.

A sequência de Fibonacci funciona da seguinte forma:

F(0) = 0  
F(1) = 1  
F(n) = F(n - 1) + F(n - 2)

Além de calcular o resultado, o programa também conta quantas chamadas recursivas foram realizadas.

Isso mostra que a versão sem otimização pode ser ineficiente, pois vários valores são calculados repetidamente.

Exemplo com n = 4:

Fibonacci de 4 = 3  
Número de chamadas = 9

---

## 2. Fibonacci com Memoização

O segundo programa também calcula um termo da sequência de Fibonacci, mas utilizando memoização.

A memoização armazena os valores que já foram calculados em um vetor. Assim, quando o programa precisa de um valor que já existe, ele apenas retorna esse valor salvo, evitando cálculos repetidos.

Neste exercício, o vetor é criado com alocação dinâmica usando malloc.

Exemplo com n = 4:

Fibonacci de 4 = 3  
Número de chamadas com memoização = 7

Comparação:

Sem memoização: 9 chamadas  
Com memoização: 7 chamadas

A diferença é pequena com números baixos, mas aumenta bastante conforme o valor de n cresce.

---

## 3. Torres de Hanoi

O terceiro programa resolve o problema das Torres de Hanoi de forma recursiva.

O problema possui três torres:

A = origem  
B = auxiliar  
C = destino

O objetivo é mover todos os discos da torre de origem para a torre de destino, respeitando as regras:

1. Só pode mover um disco por vez;
2. Um disco maior não pode ficar em cima de um disco menor.

A lógica usada é:

1. Mover os discos menores para a torre auxiliar;
2. Mover o disco maior para a torre destino;
3. Mover os discos menores da auxiliar para o destino.

Exemplo com 3 discos:

Mover disco 1 de A para C  
Mover disco 2 de A para B  
Mover disco 1 de C para B  
Mover disco 3 de A para C  
Mover disco 1 de B para A  
Mover disco 2 de B para C  
Mover disco 1 de A para C  

Total de movimentos: 7

A quantidade mínima de movimentos é calculada pela fórmula:

2^n - 1

Exemplos:

1 disco = 1 movimento  
2 discos = 3 movimentos  
3 discos = 7 movimentos  
4 discos = 15 movimentos  

---

## Conceitos Utilizados

Neste projeto foram utilizados os seguintes conceitos:

- Linguagem C;
- Funções;
- Recursividade;
- Variáveis globais;
- Estruturas condicionais;
- Entrada de dados com scanf;
- Saída de dados com printf;
- Vetores;
- Alocação dinâmica com malloc;
- Liberação de memória com free;
- Contadores de chamadas e movimentos.

---

## Como Executar

Para compilar um dos arquivos, utilize um compilador C, como o GCC.

Exemplo:

gcc nome_do_arquivo.c -o programa

Para executar no Linux ou Git Bash:

./programa

Para executar no Windows:

programa.exe

---

## Objetivo do Projeto

O objetivo deste projeto é praticar recursividade em C por meio de problemas clássicos.

O exercício de Fibonacci sem otimização mostra como a recursão simples pode gerar muitas chamadas repetidas.

O exercício com memoização demonstra uma forma de melhorar o desempenho, armazenando resultados já calculados.

O exercício das Torres de Hanoi mostra como a recursão pode resolver um problema maior dividindo-o em partes menores.
