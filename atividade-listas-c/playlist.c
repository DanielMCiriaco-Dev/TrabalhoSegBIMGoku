#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char musica[100];
    struct No *prox;
    struct No *ant;
} No;

void limparBuffer() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void lerTexto(char texto[], int tamanho) {
    int i = 0;
    char caractere;

    while (i < tamanho - 1) {
        caractere = getchar();

        if (caractere == '\n' || caractere == EOF) {
            break;
        }

        texto[i] = caractere;
        i++;
    }

    texto[i] = '\0';
}

void copiarTexto(char destino[], char origem[]) {
    int i = 0;

    while (origem[i] != '\0' && i < 99) {
        destino[i] = origem[i];
        i++;
    }

    destino[i] = '\0';
}

No* criarNo(char *nome) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    copiarTexto(novo->musica, nome);

    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}

void adicionarMusica(No **head, char *nome) {
    No *novo = criarNo(nome);

    if (*head == NULL) {
        *head = novo;
        novo->prox = novo;
        novo->ant = novo;
        printf("Musica adicionada com sucesso.\n");
        return;
    }

    No *ultimo = (*head)->ant;

    ultimo->prox = novo;
    novo->ant = ultimo;
    novo->prox = *head;
    (*head)->ant = novo;

    printf("Musica adicionada com sucesso.\n");
}

void proximaMusica(No **atual) {
    if (*atual == NULL) {
        printf("Playlist vazia.\n");
        return;
    }

    *atual = (*atual)->prox;
    printf("Musica atual: %s\n", (*atual)->musica);
}

void musicaAnterior(No **atual) {
    if (*atual == NULL) {
        printf("Playlist vazia.\n");
        return;
    }

    *atual = (*atual)->ant;
    printf("Musica atual: %s\n", (*atual)->musica);
}

void exibirPlaylist(No *head) {
    if (head == NULL) {
        printf("Playlist vazia.\n");
        return;
    }

    No *atual = head;

    printf("\nPlaylist:\n");

    do {
        printf("[%s] <-> ", atual->musica);
        atual = atual->prox;
    } while (atual != head);

    printf("(volta para o inicio)\n");
}

int totalMusicas(No *head) {
    if (head == NULL) {
        return 0;
    }

    int total = 0;
    No *atual = head;

    do {
        total++;
        atual = atual->prox;
    } while (atual != head);

    return total;
}

void tocarTodas(No *head) {
    if (head == NULL) {
        printf("Playlist vazia.\n");
        return;
    }

    No *atual = head;
    int total = totalMusicas(head);
    int contador = 0;

    printf("\nTocando todas as musicas uma vez:\n");

    while (contador < total) {
        printf("Tocando: %s\n", atual->musica);
        atual = atual->prox;
        contador++;
    }

    printf("Todas as musicas foram tocadas.\n");
}

void liberarPlaylist(No **head) {
    if (*head == NULL) {
        return;
    }

    No *atual = *head;
    No *proximo = NULL;
    No *inicio = *head;

    do {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    } while (atual != inicio);

    *head = NULL;
}

int main() {
    No *playlist = NULL;
    No *atual = NULL;

    int opcao;
    char nomeMusica[100];

    do {
        printf("\n===== MENU - PLAYLIST =====\n");
        printf("1 - Adicionar musica\n");
        printf("2 - Proxima musica\n");
        printf("3 - Musica anterior\n");
        printf("4 - Exibir playlist\n");
        printf("5 - Mostrar total de musicas\n");
        printf("6 - Tocar todas as musicas uma vez\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                printf("Digite o nome da musica: ");
                lerTexto(nomeMusica, 100);

                adicionarMusica(&playlist, nomeMusica);

                if (atual == NULL) {
                    atual = playlist;
                    printf("Musica atual: %s\n", atual->musica);
                }
                break;

            case 2:
                proximaMusica(&atual);
                break;

            case 3:
                musicaAnterior(&atual);
                break;

            case 4:
                exibirPlaylist(playlist);
                break;

            case 5:
                printf("Total de musicas: %d\n", totalMusicas(playlist));
                break;

            case 6:
                tocarTodas(playlist);
                break;

            case 0:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }

    } while (opcao != 0);

    liberarPlaylist(&playlist);

    return 0;
}
