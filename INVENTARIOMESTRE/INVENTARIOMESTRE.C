#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 20

// ================================
// STRUCT DO COMPONENTE
// ================================
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;


// ================================
// FUNÇÃO PARA MOSTRAR COMPONENTES
// ================================
void mostrarComponentes(Componente c[], int n) {

    printf("\n===== COMPONENTES =====\n");

    for (int i = 0; i < n; i++) {
        printf("%d) Nome: %s | Tipo: %s | Prioridade: %d\n",
               i + 1, c[i].nome, c[i].tipo, c[i].prioridade);
    }
}


// ================================
// BUBBLE SORT POR NOME
// ================================
void bubbleSortNome(Componente c[], int n, int *comparacoes) {

    *comparacoes = 0;
    Componente temp;

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            (*comparacoes)++;

            if (strcmp(c[j].nome, c[j + 1].nome) > 0) {

                temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
}


// ================================
// INSERTION SORT POR TIPO
// ================================
void insertionSortTipo(Componente c[], int n, int *comparacoes) {

    *comparacoes = 0;

    for (int i = 1; i < n; i++) {

        Componente chave = c[i];
        int j = i - 1;

        while (j >= 0) {

            (*comparacoes)++;

            if (strcmp(c[j].tipo, chave.tipo) > 0) {
                c[j + 1] = c[j];
                j--;
            } else
                break;
        }

        c[j + 1] = chave;
    }
}


// ================================
// SELECTION SORT POR PRIORIDADE
// ================================
void selectionSortPrioridade(Componente c[], int n, int *comparacoes) {

    *comparacoes = 0;
    Componente temp;

    for (int i = 0; i < n - 1; i++) {

        int menor = i;

        for (int j = i + 1; j < n; j++) {

            (*comparacoes)++;

            if (c[j].prioridade < c[menor].prioridade)
                menor = j;
        }

        temp = c[i];
        c[i] = c[menor];
        c[menor] = temp;
    }
}


// ================================
// BUSCA BINÁRIA POR NOME
// ================================
int buscaBinariaPorNome(Componente c[], int n, char nome[], int *comparacoes) {

    int inicio = 0;
    int fim = n - 1;

    *comparacoes = 0;

    while (inicio <= fim) {

        int meio = (inicio + fim) / 2;

        (*comparacoes)++;

        int resultado = strcmp(nome, c[meio].nome);

        if (resultado == 0)
            return meio;

        if (resultado > 0)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}


// ================================
// FUNÇÃO PRINCIPAL
// ================================
int main() {

    Componente componentes[MAX];
    int total;

    printf("Quantos componentes deseja cadastrar (max 20)? ");
    scanf("%d", &total);
    getchar();

    // ============================
    // CADASTRO
    // ============================
    for (int i = 0; i < total; i++) {

        printf("\nComponente %d\n", i + 1);

        printf("Nome: ");
        fgets(componentes[i].nome, 30, stdin);
        componentes[i].nome[strcspn(componentes[i].nome, "\n")] = 0;

        printf("Tipo: ");
        fgets(componentes[i].tipo, 20, stdin);
        componentes[i].tipo[strcspn(componentes[i].tipo, "\n")] = 0;

        printf("Prioridade (1-10): ");
        scanf("%d", &componentes[i].prioridade);
        getchar();
    }

    int opcao;
    int comparacoes;
    clock_t inicio, fim;

    do {

        printf("\n===== MENU =====\n");
        printf("1 Ordenar por Nome (Bubble Sort)\n");
        printf("2 Ordenar por Tipo (Insertion Sort)\n");
        printf("3 Ordenar por Prioridade (Selection Sort)\n");
        printf("4 Buscar componente-chave (Busca Binaria)\n");
        printf("5 Mostrar componentes\n");
        printf("0 Sair\n");

        scanf("%d", &opcao);
        getchar();

        switch (opcao) {

        case 1:

            inicio = clock();
            bubbleSortNome(componentes, total, &comparacoes);
            fim = clock();

            printf("\nOrdenado por Nome!\n");
            printf("Comparacoes: %d\n", comparacoes);
            printf("Tempo: %.5f segundos\n",
                   (double)(fim - inicio) / CLOCKS_PER_SEC);

            mostrarComponentes(componentes, total);

            break;

        case 2:

            inicio = clock();
            insertionSortTipo(componentes, total, &comparacoes);
            fim = clock();

            printf("\nOrdenado por Tipo!\n");
            printf("Comparacoes: %d\n", comparacoes);
            printf("Tempo: %.5f segundos\n",
                   (double)(fim - inicio) / CLOCKS_PER_SEC);

            mostrarComponentes(componentes, total);

            break;

        case 3:

            inicio = clock();
            selectionSortPrioridade(componentes, total, &comparacoes);
            fim = clock();

            printf("\nOrdenado por Prioridade!\n");
            printf("Comparacoes: %d\n", comparacoes);
            printf("Tempo: %.5f segundos\n",
                   (double)(fim - inicio) / CLOCKS_PER_SEC);

            mostrarComponentes(componentes, total);

            break;

        case 4: {

            char chave[30];
            int pos;

            printf("Nome do componente-chave: ");
            fgets(chave, 30, stdin);
            chave[strcspn(chave, "\n")] = 0;

            pos = buscaBinariaPorNome(componentes, total, chave, &comparacoes);

            if (pos != -1)
                printf("Componente encontrado: %s | Tipo: %s | Prioridade: %d\n",
                       componentes[pos].nome,
                       componentes[pos].tipo,
                       componentes[pos].prioridade);
            else
                printf("Componente nao encontrado!\n");

            printf("Comparacoes: %d\n", comparacoes);

            break;
        }

        case 5:
            mostrarComponentes(componentes, total);
            break;
        }

    } while (opcao != 0);

    return 0;
}