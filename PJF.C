#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRATOS 100
#define MAX_PEDIDOS 50

typedef struct {
    char nome[50];
    char descricao[200];
    float preco;
} Prato;

typedef struct {
    char nome[50];
    int quantidade;
} Pedido;

Prato cardapio[MAX_PRATOS];
int quantidade_pratos = 0;

Pedido pedidos[MAX_PEDIDOS];
int quantidade_pedidos = 0;

void cadastrar_prato() {
    if (quantidade_pratos >= MAX_PRATOS) {
        printf("Capacidade máxima de pratos atingida.\n");
        return;
    }
    Prato novo_prato;
    printf("Digite o nome do prato: ");
    scanf(" %[^\n]s", novo_prato.nome);
    printf("Digite a descrição do prato: ");
    scanf(" %[^\n]s", novo_prato.descricao);
    printf("Digite o preço do prato: ");
    scanf("%f", &novo_prato.preco);
    cardapio[quantidade_pratos] = novo_prato;
    quantidade_pratos++;
    printf("Prato cadastrado com sucesso!\n");
}

void remover_prato() {
    if (quantidade_pratos == 0) {
        printf("Não há pratos cadastrados para remover.\n");
        return;
    }
    char nome[50];
    printf("Digite o nome do prato a ser removido: ");
    scanf(" %[^\n]s", nome);
    int encontrado = 0;
    for (int i = 0; i < quantidade_pratos; i++) {
        if (strcmp(cardapio[i].nome, nome) == 0) {
            encontrado = 1;
            for (int j = i; j < quantidade_pratos - 1; j++) {
                cardapio[j] = cardapio[j + 1];
            }
            quantidade_pratos--;
            printf("Prato removido com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("Prato não encontrado.\n");
    }
}

void buscar_prato() {
    if (quantidade_pratos == 0) {
        printf("Não há pratos cadastrados.\n");
        return;
    }
    char termo[50];
    printf("Digite o nome ou descrição do prato: ");
    scanf(" %[^\n]s", termo);
    int encontrado = 0;
    for (int i = 0; i < quantidade_pratos; i++) {
        if (strstr(cardapio[i].nome, termo) != NULL || strstr(cardapio[i].descricao, termo) != NULL) {
            printf("Nome: %s\nDescrição: %s\nPreço: R$%.2f\n", cardapio[i].nome, cardapio[i].descricao, cardapio[i].preco);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Prato não encontrado.\n");
    }
}

void listar_pratos() {
    if (quantidade_pratos == 0) {
        printf("Não há pratos cadastrados.\n");
        return;
    }
    for (int i = 0; i < quantidade_pratos; i++) {
        printf("Nome: %s\nDescrição: %s\nPreço: R$%.2f\n", cardapio[i].nome, cardapio[i].descricao, cardapio[i].preco);
    }
}

void registrar_pedido() {
    if (quantidade_pratos == 0) {
        printf("Não há pratos disponíveis para pedido.\n");
        return;
    }
    int quantidade_itens;
    printf("Quantos pratos deseja pedir? ");
    scanf("%d", &quantidade_itens);
    float total = 0;
    for (int i = 0; i < quantidade_itens; i++) {
        char nome[50];
        int quantidade;
        printf("Digite o nome do prato: ");
        scanf(" %[^\n]s", nome);
        printf("Digite a quantidade: ");
        scanf("%d", &quantidade);
        int encontrado = 0;
        for (int j = 0; j < quantidade_pratos; j++) {
            if (strcmp(cardapio[j].nome, nome) == 0) {
                total += cardapio[j].preco * quantidade;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("Prato não encontrado. Pedido ignorado.\n");
        }
    }
    printf("Total do pedido: R$%.2f\n", total);
}

int main() {
    int escolha;
    do {
        printf("Menu:\n");
        printf("1. Cadastrar prato\n");
        printf("2. Remover prato\n");
        printf("3. Buscar prato\n");
        printf("4. Listar pratos\n");
        printf("5. Registrar pedido\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                cadastrar_prato();
                break;
            case 2:
                remover_prato();
                break;
            case 3:
                buscar_prato();
                break;
            case 4:
                listar_pratos();
                break;
            case 5:
                registrar_pedido();
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 6);

    return 0;
}
