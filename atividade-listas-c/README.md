# Atividade Avaliativa 2 - Estruturas de Dados em C

### Aluno: Daniel Martins Ciriaco Nicoli
### RA: 25254073-2

O objetivo da atividade é implementar operações com listas encadeadas em linguagem C e também criar uma playlist de músicas utilizando lista circular duplamente encadeada.

O projeto possui dois arquivos principais:

- `lista_inteiros.c`
- `playlist.c`

---

## Estrutura do projeto

```txt
atividade-listas-c/
│
├── lista_inteiros.c
├── playlist.c
└── README.md
```

---

# Parte 1 a 4 - Lista Encadeada Simples de Inteiros

As partes 1, 2, 3 e 4 foram implementadas no arquivo:

```txt
lista_inteiros.c
```

Nesse arquivo foi criada uma lista encadeada simples de números inteiros.

A estrutura utilizada foi:

```c
typedef struct No {
    int valor;
    struct No *prox;
} No;
```

O programa possui um menu interativo, permitindo que o usuário escolha as operações desejadas.

---

## Funcionalidades implementadas

### 1. Inserir valor no final da lista

Permite que o usuário digite um número inteiro e adicione esse valor ao final da lista.

Função utilizada:

```c
void inserirFinal(No **head, int valor);
```

---

### 2. Inserir valor em uma posição específica

Permite que o usuário informe:

- o valor que deseja inserir;
- a posição em que deseja inserir esse valor.

A posição começa em 0.

Função obrigatória da atividade:

```c
void inserirPosicao(No **head, int valor, int posicao);
```

Essa função funciona para:

- lista vazia;
- inserção no início;
- inserção no meio;
- inserção no final;
- posição inválida.

Caso a posição informada seja inválida, o programa exibe uma mensagem de erro.

Exemplo:

```txt
Lista: 10 -> 20 -> 30 -> NULL

Inserir valor: 99
Posição: 1

Resultado:
10 -> 99 -> 20 -> 30 -> NULL
```

---

### 3. Buscar valor na lista

Permite que o usuário digite um número e verifique se ele existe na lista.

Função obrigatória da atividade:

```c
int buscarValor(No *head, int valor);
```

A função retorna a posição da primeira ocorrência do valor.

Caso o valor não seja encontrado, retorna `-1`.

Exemplo:

```txt
Lista: 10 -> 20 -> 30 -> NULL

Buscar valor: 20

Resultado:
Valor encontrado na posição 1.
```

---

### 4. Inverter lista

Inverte a ordem dos elementos da lista usando apenas ponteiros.

Função obrigatória da atividade:

```c
void inverterLista(No **head);
```

Não foi utilizado vetor auxiliar e não foi criada uma nova lista.

Exemplo:

```txt
Antes:
10 -> 20 -> 30 -> NULL

Depois:
30 -> 20 -> 10 -> NULL
```

---

### 5. Dividir lista em duas

Divide a lista em duas partes utilizando a técnica de ponteiro rápido e ponteiro lento.

Função obrigatória da atividade:

```c
void dividirLista(No *head, No **lista1, No **lista2);
```

A lista é dividida sem contar os elementos previamente.

Caso a quantidade de elementos seja ímpar, a primeira lista recebe um elemento a mais.

Exemplo:

```txt
Lista original:
10 -> 20 -> 30 -> 40 -> 50 -> NULL

Primeira lista:
10 -> 20 -> 30 -> NULL

Segunda lista:
40 -> 50 -> NULL
```

---

### 6. Exibir lista

Mostra todos os elementos cadastrados na lista.

Função utilizada:

```c
void exibirLista(No *head);
```

---

### 7. Liberar memória

Ao final do programa, a memória alocada dinamicamente é liberada.

Função utilizada:

```c
void liberarLista(No **head);
```

---

## Menu do programa de lista de inteiros

O arquivo `lista_inteiros.c` apresenta o seguinte menu:

```txt
===== MENU - LISTA ENCADEADA =====
1 - Inserir valor no final da lista
2 - Inserir valor em uma posicao especifica
3 - Buscar valor
4 - Inverter lista
5 - Dividir lista em duas
6 - Exibir lista
0 - Sair
```

---

# Parte 5 - Playlist Circular Duplamente Encadeada

A parte 5 foi implementada no arquivo:

```txt
playlist.c
```

Nesse arquivo foi criada uma playlist de músicas utilizando lista circular duplamente encadeada.

A estrutura utilizada foi:

```c
typedef struct No {
    char musica[100];
    struct No *prox;
    struct No *ant;
} No;
```

Cada nó armazena o nome de uma música, um ponteiro para a próxima música e um ponteiro para a música anterior.

---

## Funcionamento da lista circular duplamente encadeada

A playlist é circular porque:

- o último nó aponta para o primeiro;
- o primeiro nó aponta para o último por meio do ponteiro `ant`;
- ao avançar depois da última música, o programa volta para a primeira;
- ao voltar antes da primeira música, o programa vai para a última.

Exemplo:

```txt
[Rock] <-> [Jazz] <-> [Pop] <-> (volta para o início)
```

---

## Funcionalidades implementadas na playlist

### 1. Adicionar música

Permite que o usuário digite o nome de uma música e adicione essa música ao final da playlist.

Função obrigatória da atividade:

```c
void adicionarMusica(No **head, char *nome);
```

A função mantém a circularidade da lista.

---

### 2. Próxima música

Avança para a próxima música da playlist.

Função obrigatória da atividade:

```c
void proximaMusica(No **atual);
```

Se a música atual for a última, a próxima será a primeira, pois a lista é circular.

---

### 3. Música anterior

Volta para a música anterior da playlist.

Função obrigatória da atividade:

```c
void musicaAnterior(No **atual);
```

Se a música atual for a primeira, a anterior será a última.

---

### 4. Exibir playlist

Exibe todas as músicas cadastradas na playlist.

Função obrigatória da atividade:

```c
void exibirPlaylist(No *head);
```

O percurso é controlado para evitar loop infinito.

---

### 5. Total de músicas

Retorna a quantidade total de músicas cadastradas.

Função obrigatória da atividade:

```c
int totalMusicas(No *head);
```

---

### 6. Tocar todas as músicas uma vez

Foi criada uma função para percorrer a playlist apenas uma vez, evitando loop infinito.

Função utilizada:

```c
void tocarTodas(No *head);
```

Essa função calcula o total de músicas e percorre somente essa quantidade de nós.

---

### 7. Liberar memória

Ao final do programa, a memória alocada dinamicamente para a playlist é liberada.

Função utilizada:

```c
void liberarPlaylist(No **head);
```

---

## Menu do programa da playlist

O arquivo `playlist.c` apresenta o seguinte menu:

```txt
===== MENU - PLAYLIST =====
1 - Adicionar musica
2 - Proxima musica
3 - Musica anterior
4 - Exibir playlist
5 - Mostrar total de musicas
6 - Tocar todas as musicas uma vez
0 - Sair
```

---

# Bibliotecas utilizadas

Foram utilizadas apenas as bibliotecas permitidas pela atividade:

```c
#include <stdio.h>
#include <stdlib.h>
```

Não foi utilizada a biblioteca `string.h`.

Para copiar textos, ler nomes de músicas e limpar o buffer, foram criadas funções próprias no código da playlist.

---

# Gerenciamento de memória

O projeto utiliza alocação dinâmica de memória com `malloc`.

Também foram criadas funções para liberar a memória com `free`, evitando vazamento de memória.

Funções responsáveis pela liberação:

```c
void liberarLista(No **head);
void liberarPlaylist(No **head);
```

---

# Como compilar e executar

## Compilar a lista de inteiros

Dentro da pasta `atividade-listas-c`, use:

```bash
gcc lista_inteiros.c -o lista_inteiros
```

Para executar no Windows:

```bash
lista_inteiros.exe
```

Ou:

```bash
./lista_inteiros
```

---

## Compilar a playlist

Dentro da pasta `atividade-listas-c`, use:

```bash
gcc playlist.c -o playlist
```

Para executar no Windows:

```bash
playlist.exe
```

Ou:

```bash
./playlist
```

---

# Observações finais

O projeto atende aos requisitos da atividade, pois:

- utiliza listas encadeadas;
- utiliza lista circular duplamente encadeada na playlist;
- permite interação com o usuário por meio de menu;
- utiliza apenas `stdio.h` e `stdlib.h`;
- não utiliza vetores auxiliares para manipulação das listas;
- utiliza ponteiros para realizar as operações;
- gerencia a memória corretamente com `malloc` e `free`;
- evita loop infinito no percurso da playlist.
