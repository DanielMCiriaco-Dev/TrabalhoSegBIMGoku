#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    novo->valor = valor;
    novo->prox = NULL;

    return novo;
}

void inserirFinal(No **head, int valor) {
    No *novo = criarNo(valor);

    if (*head == NULL) {
        *head = novo;
        return;
    }

    No *atual = *head;

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novo;
}

void inserirPosicao(No **head, int valor, int posicao) {
    if (posicao < 0) {
        printf("Erro: posicao invalida.\n");
        return;
    }

    No *novo = criarNo(valor);

    if (posicao == 0) {
        novo->prox = *head;
        *head = novo;
        printf("Valor inserido com sucesso.\n");
        return;
    }

    No *atual = *head;
    int i = 0;

    while (atual != NULL && i < posicao - 1) {
        atual = atual->prox;
        i++;
    }

    if (atual == NULL) {
        printf("Erro: posicao invalida.\n");
        free(novo);
        return;
    }

    novo->prox = atual->prox;
    atual->prox = novo;

    printf("Valor inserido com sucesso.\n");
}

int buscarValor(No *head, int valor) {
    No *atual = head;
    int posicao = 0;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return posicao;
        }

        atual = atual->prox;
        posicao++;
    }

    return -1;
}

void inverterLista(No **head) {
    No *anterior = NULL;
    No *atual = *head;
    No *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *head = anterior;

    printf("Lista invertida com sucesso.\n");
}

void dividirLista(No *head, No **lista1, No **lista2) {
    if (head == NULL) {
        *lista1 = NULL;
        *lista2 = NULL;
        return;
    }

    No *lento = head;
    No *rapido = head;
    No *anterior = NULL;

    while (rapido != NULL && rapido->prox != NULL) {
        anterior = lento;
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    if (rapido != NULL) {
        anterior = lento;
        lento = lento->prox;
    }

    *lista1 = head;
    *lista2 = lento;

    if (anterior != NULL) {
        anterior->prox = NULL;
    }
}

void exibirLista(No *head) {
    if (head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = head;

    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }

    printf("NULL\n");
}

void liberarLista(No **head) {
    No *atual = *head;
    No *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    *head = NULL;
}

int main() {
    No *lista = NULL;
    No *lista1 = NULL;
    No *lista2 = NULL;

    int opcao;
    int valor;
    int posicao;
    int resultado;

    do {
        printf("\n===== MENU - LISTA ENCADEADA =====\n");
        printf("1 - Inserir valor no final da lista\n");
        printf("2 - Inserir valor em uma posicao especifica\n");
        printf("3 - Buscar valor\n");
        printf("4 - Inverter lista\n");
        printf("5 - Dividir lista em duas\n");
        printf("6 - Exibir lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor que deseja inserir no final: ");
                scanf("%d", &valor);

                inserirFinal(&lista, valor);
                printf("Valor inserido com sucesso.\n");
                break;

            case 2:
                printf("Digite o valor que deseja inserir: ");
                scanf("%d", &valor);

                printf("Digite a posicao desejada: ");
                scanf("%d", &posicao);

                inserirPosicao(&lista, valor, posicao);
                break;

            case 3:
                printf("Digite o valor que deseja buscar: ");
                scanf("%d", &valor);

                resultado = buscarValor(lista, valor);

                if (resultado != -1) {
                    printf("Valor encontrado na posicao %d.\n", resultado);
                } else {
                    printf("Valor nao encontrado.\n");
                }
                break;

            case 4:
                inverterLista(&lista);
                break;

            case 5:
                dividirLista(lista, &lista1, &lista2);

                printf("Primeira lista:\n");
                exibirLista(lista1);

                printf("Segunda lista:\n");
                exibirLista(lista2);

                lista = NULL;
                liberarLista(&lista1);
                liberarLista(&lista2);

                printf("As duas listas foram liberadas da memoria apos a exibicao.\n");
                break;

            case 6:
                printf("Lista atual:\n");
                exibirLista(lista);
                break;

            case 0:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }

    } while (opcao != 0);

    liberarLista(&lista);

    return 0;
}
