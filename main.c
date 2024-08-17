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

// Inicializar cardápio com pratos cadastrados
void inicializar_cardapio() {
    strcpy(cardapio[0].nome, "KIDS");
    strcpy(cardapio[0].descricao, "Hambúrguer de costela de 100g, queijo mussarela derretido, tomate, alface americana e maionese caseira.");
    cardapio[0].preco = 24.00;

    strcpy(cardapio[1].nome, "BACON");
    strcpy(cardapio[1].descricao, "Hambúrguer de costela de 160g coberto de queijo mussarela derretido, fatias de bacon crocante, alface americana, tomate e maionese caseira.");
    cardapio[1].preco = 34.00;

    strcpy(cardapio[2].nome, "COSTELA TRADICIONAL");
    strcpy(cardapio[2].descricao, "Hambúrguer de costela de 160g, queijo mussarela derretido, cebola roma, crispy de alho poró, alface americana e a maionese da casa com chimichurri.");
    cardapio[2].preco = 32.00;

    strcpy(cardapio[3].nome, "EGG");
    strcpy(cardapio[3].descricao, "Hambúrguer de costela de 160g coberta de queijo mussarela derretido, ovo frito, crispy de alho poró, alface americana, tomate e maionese caseira.");
    cardapio[3].preco = 32.00;

    quantidade_pratos = 4;
}

// Cadastrar novos pratos
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

// Remover prato
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

// Buscar prato
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

// Listar todos os pratos cadastrados
void listar_pratos() {
    if (quantidade_pratos == 0) {
        printf("Não há pratos cadastrados.\n");
        return;
    }
    for (int i = 0; i < quantidade_pratos; i++) {
        printf("Nome: %s\nDescrição: %s\nPreço: R$%.2f\n", cardapio[i].nome, cardapio[i].descricao, cardapio[i].preco);
    }
}

// Registrar pedido e solicitar feedback
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

    // Solicitar feedback ao cliente
    int feedback;
    do {
        printf("Por favor, avalie seu pedido (0 a 5): ");
        scanf("%d", &feedback);
        if (feedback < 0 || feedback > 5) {
            printf("Avaliação inválida. Tente novamente.\n");
        }
    } while (feedback < 0 || feedback > 5);
    printf("Obrigado pelo feedback! Sua avaliação: %d\n", feedback);
}

// Função principal
int main() {
    inicializar_cardapio();

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
