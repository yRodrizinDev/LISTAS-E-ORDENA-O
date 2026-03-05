#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ==== DEFINIÇÕES ==== */
#define MAX_ITENS 10

/* ==== STRUCT ==== */
/*
   A struct Item representa cada objeto da mochila.
   Ela agrupa:
   - nome do item
   - tipo (arma, munição, cura, ferramenta etc)
   - quantidade disponível
*/
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

/* ==== PROTÓTIPOS ==== */
void inserirItem(Item mochila[], int *total);
void removerItem(Item mochila[], int *total);
void listarItens(Item mochila[], int total);
void buscarItem(Item mochila[], int total);

/* ==== FUNÇÃO PRINCIPAL ==== */
int main() {
    Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n===== SISTEMA DE INVENTÁRIO =====\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        getchar(); // limpa buffer do enter

        switch(opcao) {
            case 1:
                inserirItem(mochila, &totalItens);
                listarItens(mochila, totalItens);
                break;

            case 2:
                removerItem(mochila, &totalItens);
                listarItens(mochila, totalItens);
                break;

            case 3:
                listarItens(mochila, totalItens);
                break;

            case 4:
                buscarItem(mochila, totalItens);
                break;

            case 0:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while(opcao != 0);

    return 0;
}

/* ==== INSERIR ITEM ==== */
/*
   Insere um novo item na mochila,
   desde que não ultrapasse o limite máximo.
*/
void inserirItem(Item mochila[], int *total) {

    if (*total >= MAX_ITENS) {
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("Nome do item: ");
    fgets(mochila[*total].nome, 30, stdin);
    mochila[*total].nome[strcspn(mochila[*total].nome, "\n")] = '\0';

    printf("Tipo do item: ");
    fgets(mochila[*total].tipo, 20, stdin);
    mochila[*total].tipo[strcspn(mochila[*total].tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);
    getchar(); // limpa buffer

    (*total)++;

    printf("Item adicionado com sucesso!\n");
}

/* ==== REMOVER ITEM ==== */
/*
   Remove um item pelo nome.
   Após encontrar, desloca os elementos
   para manter a lista sequencial.
*/
void removerItem(Item mochila[], int *total) {

    char nomeBusca[30];
    int encontrado = -1;

    printf("Digite o nome do item a remover: ");
    fgets(nomeBusca, 30, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for(int i = 0; i < *total; i++) {
        if(strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1) {
        printf("Item não encontrado.\n");
        return;
    }

    for(int i = encontrado; i < *total - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*total)--;

    printf("Item removido com sucesso!\n");
}

/* ==== LISTAR ITENS ==== */
/*
   Percorre o vetor e exibe todos os itens cadastrados.
*/
void listarItens(Item mochila[], int total) {

    if(total == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    printf("\n--- ITENS NA MOCHILA ---\n");

    for(int i = 0; i < total; i++) {
        printf("\nItem %d\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
}

/* ==== BUSCA SEQUENCIAL ==== */
/*
   Realiza busca sequencial pelo nome do item.
   Percorre todo o vetor até encontrar.
*/
void buscarItem(Item mochila[], int total) {

    char nomeBusca[30];
    int encontrado = 0;

    printf("Digite o nome do item a buscar: ");
    fgets(nomeBusca, 30, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for(int i = 0; i < total; i++) {
        if(strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if(!encontrado) {
        printf("Item não encontrado.\n");
    }
}