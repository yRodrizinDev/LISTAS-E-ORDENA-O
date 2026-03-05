#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// ========================
// STRUCT DO ITEM
// ========================
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// ========================
// STRUCT DA LISTA ENCADEADA
// ========================
typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// ========================
// VARIÁVEIS GLOBAIS
// ========================

Item mochilaVetor[MAX];
int total = 0;

No* lista = NULL;

int comparacoesSeq = 0;
int comparacoesBin = 0;


// ========================
// FUNÇÕES DO VETOR
// ========================

void inserirItemVetor() {

    if (total >= MAX) {
        printf("Mochila cheia!\n");
        return;
    }

    printf("Nome: ");
    scanf("%s", mochilaVetor[total].nome);

    printf("Tipo: ");
    scanf("%s", mochilaVetor[total].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochilaVetor[total].quantidade);

    total++;
}

void listarVetor() {

    printf("\n--- Mochila (Vetor) ---\n");

    for (int i = 0; i < total; i++) {
        printf("%s | %s | %d\n",
               mochilaVetor[i].nome,
               mochilaVetor[i].tipo,
               mochilaVetor[i].quantidade);
    }
}

void removerItemVetor() {

    char nome[30];

    printf("Nome do item para remover: ");
    scanf("%s", nome);

    for (int i = 0; i < total; i++) {

        if (strcmp(mochilaVetor[i].nome, nome) == 0) {

            for (int j = i; j < total - 1; j++) {
                mochilaVetor[j] = mochilaVetor[j + 1];
            }

            total--;
            printf("Item removido!\n");
            return;
        }
    }

    printf("Item nao encontrado.\n");
}

void ordenarVetor() {

    Item temp;

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {

            if (strcmp(mochilaVetor[j].nome,
                       mochilaVetor[j + 1].nome) > 0) {

                temp = mochilaVetor[j];
                mochilaVetor[j] = mochilaVetor[j + 1];
                mochilaVetor[j + 1] = temp;
            }
        }
    }

    printf("Vetor ordenado!\n");
}

void buscaSequencialVetor() {

    char nome[30];
    comparacoesSeq = 0;

    printf("Item para buscar: ");
    scanf("%s", nome);

    for (int i = 0; i < total; i++) {

        comparacoesSeq++;

        if (strcmp(mochilaVetor[i].nome, nome) == 0) {

            printf("Encontrado: %s | %s | %d\n",
                   mochilaVetor[i].nome,
                   mochilaVetor[i].tipo,
                   mochilaVetor[i].quantidade);

            printf("Comparacoes: %d\n", comparacoesSeq);
            return;
        }
    }

    printf("Item nao encontrado.\n");
    printf("Comparacoes: %d\n", comparacoesSeq);
}

void buscaBinariaVetor() {

    char nome[30];
    int inicio = 0;
    int fim = total - 1;

    comparacoesBin = 0;

    printf("Item para busca binaria: ");
    scanf("%s", nome);

    while (inicio <= fim) {

        int meio = (inicio + fim) / 2;

        comparacoesBin++;

        int resultado = strcmp(nome, mochilaVetor[meio].nome);

        if (resultado == 0) {

            printf("Encontrado: %s | %s | %d\n",
                   mochilaVetor[meio].nome,
                   mochilaVetor[meio].tipo,
                   mochilaVetor[meio].quantidade);

            printf("Comparacoes: %d\n", comparacoesBin);
            return;
        }

        if (resultado > 0)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    printf("Item nao encontrado.\n");
    printf("Comparacoes: %d\n", comparacoesBin);
}


// ========================
// FUNÇÕES DA LISTA ENCADEADA
// ========================

void inserirLista() {

    No* novo = (No*) malloc(sizeof(No));

    printf("Nome: ");
    scanf("%s", novo->dados.nome);

    printf("Tipo: ");
    scanf("%s", novo->dados.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo->dados.quantidade);

    novo->proximo = lista;
    lista = novo;
}

void listarLista() {

    No* atual = lista;

    printf("\n--- Mochila (Lista) ---\n");

    while (atual != NULL) {

        printf("%s | %s | %d\n",
               atual->dados.nome,
               atual->dados.tipo,
               atual->dados.quantidade);

        atual = atual->proximo;
    }
}

void removerLista() {

    char nome[30];
    No *atual = lista, *anterior = NULL;

    printf("Nome para remover: ");
    scanf("%s", nome);

    while (atual != NULL) {

        if (strcmp(atual->dados.nome, nome) == 0) {

            if (anterior == NULL)
                lista = atual->proximo;
            else
                anterior->proximo = atual->proximo;

            free(atual);

            printf("Item removido!\n");
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("Item nao encontrado.\n");
}

void buscarLista() {

    char nome[30];
    int comparacoes = 0;

    No* atual = lista;

    printf("Buscar item: ");
    scanf("%s", nome);

    while (atual != NULL) {

        comparacoes++;

        if (strcmp(atual->dados.nome, nome) == 0) {

            printf("Encontrado: %s | %s | %d\n",
                   atual->dados.nome,
                   atual->dados.tipo,
                   atual->dados.quantidade);

            printf("Comparacoes: %d\n", comparacoes);
            return;
        }

        atual = atual->proximo;
    }

    printf("Item nao encontrado.\n");
    printf("Comparacoes: %d\n", comparacoes);
}


// ========================
// MENU
// ========================

int main() {

    int op;

    do {

        printf("\n===== SISTEMA MOCHILA =====\n");
        printf("1 Inserir Vetor\n");
        printf("2 Remover Vetor\n");
        printf("3 Listar Vetor\n");
        printf("4 Ordenar Vetor\n");
        printf("5 Busca Sequencial Vetor\n");
        printf("6 Busca Binaria Vetor\n");

        printf("7 Inserir Lista\n");
        printf("8 Remover Lista\n");
        printf("9 Listar Lista\n");
        printf("10 Buscar Lista\n");

        printf("0 Sair\n");

        scanf("%d", &op);

        switch (op) {

        case 1: inserirItemVetor(); break;
        case 2: removerItemVetor(); break;
        case 3: listarVetor(); break;
        case 4: ordenarVetor(); break;
        case 5: buscaSequencialVetor(); break;
        case 6: buscaBinariaVetor(); break;

        case 7: inserirLista(); break;
        case 8: removerLista(); break;
        case 9: listarLista(); break;
        case 10: buscarLista(); break;

        }

    } while (op != 0);

    return 0;
}