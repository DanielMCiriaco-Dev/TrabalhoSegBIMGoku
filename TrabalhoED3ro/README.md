# Dicionário com Tabela Hash em C

Este projeto é um sistema de dicionário desenvolvido em linguagem C utilizando tabela hash.

## Funcionalidades

O sistema permite:

* Inserir palavras e definições
* Buscar palavras
* Remover palavras
* Exibir a tabela hash
* Tratar colisões utilizando listas encadeadas
* Exibir estatísticas da tabela

## Estrutura dos Dados

Cada registro armazena:

* Palavra
* Definição

A estrutura utilizada possui um ponteiro para o próximo registro, permitindo o tratamento de colisões por meio de lista encadeada.

## Estatísticas Exibidas

O programa informa:

* Quantidade de elementos
* Quantidade de colisões
* Fator de carga
* Maior lista encadeada

## Requisitos Técnicos Utilizados

O projeto utiliza:

* Linguagem C
* Structs
* Ponteiros
* Alocação dinâmica
* Listas encadeadas
* Tabela hash

## Como Compilar

No terminal, execute:

```bash
gcc main.c -o dicionario
```

## Como Executar

Após compilar, execute:

```bash
./dicionario
```

No Windows, execute:

```bash
dicionario.exe
```

## Integrantes

* Nome completo do integrante 1 - usuário GitHub
* Nome completo do integrante 2 - usuário GitHub
* Nome completo do integrante 3 - usuário GitHub
* Nome completo do integrante 4 - usuário GitHub
* Nome completo do integrante 5 - usuário GitHub
* Nome completo do integrante 6 - usuário GitHub

## Descrição da Solução

O sistema utiliza uma tabela hash para armazenar palavras e suas respectivas definições.

A posição de cada palavra na tabela é definida por uma função hash, que calcula um índice com base nos caracteres da palavra.

Quando duas ou mais palavras geram o mesmo índice, ocorre uma colisão. Para tratar essas colisões, o programa utiliza listas encadeadas.

Cada posição da tabela pode apontar para uma lista de registros. Assim, quando ocorre colisão, o novo registro é inserido na lista daquela posição.

## Operações do Sistema

### Inserção

O usuário informa uma palavra e sua definição. O sistema calcula o índice da tabela hash e insere o registro.

Caso a palavra já exista, a definição é atualizada.

### Busca

O usuário informa a palavra que deseja procurar. O sistema calcula o índice correspondente e percorre a lista encadeada daquela posição até encontrar a palavra.

### Remoção

O usuário informa a palavra que deseja remover. O sistema localiza a palavra na tabela e remove o registro da lista encadeada.

### Exibição da Tabela

O sistema mostra todas as posições da tabela hash e os registros armazenados em cada uma delas.

### Estatísticas

O sistema exibe informações sobre a tabela, como quantidade de elementos, quantidade de colisões, fator de carga e tamanho da maior lista encadeada.
