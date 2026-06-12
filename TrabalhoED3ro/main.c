//Daniel Martins Ciriaco Nicoli |RA:25254073-2|Esoft 3S-NB 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10
#define TAMANHO_TEXTO 100

typedef struct Registro {
    char palavra[TAMANHO_TEXTO];
    char definicao[TAMANHO_TEXTO];
    struct Registro *proximo;
} Registro;

Registro *tabela[TAMANHO_TABELA];

int quantidadeElementos = 0;
int quantidadeColisoes = 0;

int funcaoHash(char palavra[]) {
    int soma = 0;

    for (int i = 0; palavra[i] != '\0'; i++) {
        soma += palavra[i];
    }

    return soma % TAMANHO_TABELA;
}

void removerQuebraLinha(char texto[]) {
    texto[strcspn(texto, "\n")] = '\0';
}

void inserir() {
    char palavra[TAMANHO_TEXTO];
    char definicao[TAMANHO_TEXTO];

    printf("Digite a palavra: ");
    fgets(palavra, TAMANHO_TEXTO, stdin);
    removerQuebraLinha(palavra);

    printf("Digite a definicao: ");
    fgets(definicao, TAMANHO_TEXTO, stdin);
    removerQuebraLinha(definicao);

    int indice = funcaoHash(palavra);

    Registro *atual = tabela[indice];

    while (atual != NULL) {
        if (strcmp(atual->palavra, palavra) == 0) {
            strcpy(atual->definicao, definicao);
            printf("Palavra atualizada com sucesso.\n");
            return;
        }

        atual = atual->proximo;
    }

    Registro *novo = (Registro *) malloc(sizeof(Registro));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    strcpy(novo->palavra, palavra);
    strcpy(novo->definicao, definicao);

    if (tabela[indice] != NULL) {
        quantidadeColisoes++;
    }

    novo->proximo = tabela[indice];
    tabela[indice] = novo;

    quantidadeElementos++;

    printf("Palavra inserida com sucesso.\n");
}

void buscar() {
    char palavra[TAMANHO_TEXTO];

    printf("Digite a palavra que deseja buscar: ");
    fgets(palavra, TAMANHO_TEXTO, stdin);
    removerQuebraLinha(palavra);

    int indice = funcaoHash(palavra);

    Registro *atual = tabela[indice];

    while (atual != NULL) {
        if (strcmp(atual->palavra, palavra) == 0) {
            printf("Palavra encontrada.\n");
            printf("Definicao: %s\n", atual->definicao);
            return;
        }

        atual = atual->proximo;
    }

    printf("Palavra nao encontrada.\n");
}

void removerPalavra() {
    char palavra[TAMANHO_TEXTO];

    printf("Digite a palavra que deseja remover: ");
    fgets(palavra, TAMANHO_TEXTO, stdin);
    removerQuebraLinha(palavra);

    int indice = funcaoHash(palavra);

    Registro *atual = tabela[indice];
    Registro *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->palavra, palavra) == 0) {
            if (anterior == NULL) {
                tabela[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            free(atual);
            quantidadeElementos--;

            printf("Palavra removida com sucesso.\n");
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("Palavra nao encontrada.\n");
}

void exibirTabela() {
    printf("\n Tabela HASH \n");

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        printf("[%d] ", i);

        Registro *atual = tabela[i];

        while (atual != NULL) {
            printf("-> (%s: %s) ", atual->palavra, atual->definicao);
            atual = atual->proximo;
        }

        printf("\n");
    }
}

int maiorListaEncadeada() {
    int maior = 0;

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        int tamanho = 0;
        Registro *atual = tabela[i];

        while (atual != NULL) {
            tamanho++;
            atual = atual->proximo;
        }

        if (tamanho > maior) {
            maior = tamanho;
        }
    }

    return maior;
}

void exibirEstatisticas() {
    float fatorCarga = (float) quantidadeElementos / TAMANHO_TABELA;

    printf("\nEstatisticas\n");
    printf("Quantidade de elementos: %d\n", quantidadeElementos);
    printf("Quantidade de colisoes: %d\n", quantidadeColisoes);
    printf("Fator de carga: %.2f\n", fatorCarga);
    printf("Maior lista encadeada: %d\n", maiorListaEncadeada());
}

void liberarMemoria() {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Registro *atual = tabela[i];

        while (atual != NULL) {
            Registro *temporario = atual;
            atual = atual->proximo;
            free(temporario);
        }
    }
}

int main() {
    int opcao;

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela[i] = NULL;
    }

    do {
        printf("\n Dicionario Daniel's\n");
        printf("1 - Inserir palavra\n");
        printf("2 - Buscar palavra\n");
        printf("3 - Remover palavra\n");
        printf("4 - Exibir tabela hash\n");
        printf("5 - Exibir estatisticas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inserir();
                break;

            case 2:
                buscar();
                break;

            case 3:
                removerPalavra();
                break;

            case 4:
                exibirTabela();
                break;

            case 5:
                exibirEstatisticas();
                break;

            case 0:
                liberarMemoria();
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}