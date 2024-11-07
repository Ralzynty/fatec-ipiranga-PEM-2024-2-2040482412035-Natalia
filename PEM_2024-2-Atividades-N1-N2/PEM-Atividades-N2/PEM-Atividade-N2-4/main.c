/*---------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular*
*          Prof. Carlos Veríssimo              *
*----------------------------------------------*
* Objetivo do Programa: Manipulando Struct     *
* Data - 25/10/2024                            * 
* Autor: Natalia Yuri Ike                      *
*----------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

// Definição da estrutura do produto
typedef struct {
    int id;
    char nome[50];
    char descricao[100];
    float preco;
    int quantidade;
} Produto;

// Declaração de funções
void inserirProduto(Produto *produtos, int *total);
void listarProdutos(Produto *produtos, int total);
void bubbleSort(Produto *produtos, int total);
void simularCompra(Produto *produtos, int *total);

int main() {
    Produto produtos[MAX_PRODUTOS];
    int total = 0;
    int opcao;

    do {
        printf("\nLoja de Produtos Eletrônicos\n");
        printf("1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Simular compra\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirProduto(produtos, &total);
                break;
            case 2:
                listarProdutos(produtos, total);
                break;
            case 3:
                simularCompra(produtos, &total);
                break;
            case 4:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}

// Função para inserir um produto
void inserirProduto(Produto *produtos, int *total) {
    if (*total >= MAX_PRODUTOS) {
        printf("Capacidade máxima de produtos atingida.\n");
        return;
    }

    Produto novoProduto;
    novoProduto.id = *total + 1;

    printf("Insira o nome do produto: ");
    scanf(" %[^\n]", novoProduto.nome);
    printf("Insira a descrição do produto: ");
    scanf(" %[^\n]", novoProduto.descricao);
    printf("Insira o preço unitário do produto: ");
    scanf("%f", &novoProduto.preco);
    printf("Insira a quantidade em estoque: ");
    scanf("%d", &novoProduto.quantidade);

    produtos[*total] = novoProduto;
    (*total)++;
    printf("Produto inserido com sucesso!\n");
}

// Função para listar produtos em ordem alfabética
void listarProdutos(Produto *produtos, int total) {
    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    bubbleSort(produtos, total);

    printf("\nLista de Produtos:\n");
    for (int i = 0; i < total; i++) {
        printf("ID: %d, Nome: %s, Descrição: %s, Preço: %.2f, Estoque: %d\n",
               produtos[i].id, produtos[i].nome, produtos[i].descricao,
               produtos[i].preco, produtos[i].quantidade);
    }
}

// Função Bubble Sort para ordenar os produtos pelo nome
void bubbleSort(Produto *produtos, int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

// Função para simular a compra de um produto
void simularCompra(Produto *produtos, int *total) {
    int id, quantidade;

    if (*total == 0) {
        printf("Nenhum produto disponível para compra.\n");
        return;
    }

    printf("Insira o ID do produto que deseja comprar: ");
    scanf("%d", &id);

    int encontrado = -1;
    for (int i = 0; i < *total; i++) {
        if (produtos[i].id == id) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Produto inexistente.\n");
        return;
    }

    printf("Insira a quantidade que deseja comprar: ");
    scanf("%d", &quantidade);

    if (quantidade > produtos[encontrado].quantidade) {
        printf("Quantidade em estoque insuficiente.\n");
    } else {
        produtos[encontrado].quantidade -= quantidade;
        printf("Compra realizada com sucesso!\n");
        printf("Total a pagar: R$ %.2f\n", produtos[encontrado].preco * quantidade);
    }
}
