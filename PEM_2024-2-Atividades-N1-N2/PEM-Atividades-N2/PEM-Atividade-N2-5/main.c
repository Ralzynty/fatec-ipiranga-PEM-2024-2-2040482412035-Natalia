/*---------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular*
*          Prof. Carlos Veríssimo              *
*----------------------------------------------*
* Objetivo do Programa: Utilizando os ponteiros*
* Data - 25/10/2024                            * 
* Autor: Natalia Yuri Ike                      *
*----------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

// Definição da estrutura do Produto
typedef struct {
    int id;
    char nome[50];
    int quantidadeEmEstoque;
    double valorDoProduto;
} Produto;

// Declaração das funções
void incluirProduto(Produto *produtos, int *total);
void consultarProduto(Produto *produtos, int total);
void alterarProduto(Produto *produtos, int total);
void excluirProduto(Produto *produtos, int *total);
void venderProduto(Produto *produtos, int total);
void imprimirProduto(Produto *produto);

int main() {
    Produto produtos[MAX_PRODUTOS];
    int total = 0;
    int opcao;

    do {
        printf("\nLoja de Produtos Eletrônicos\n");
        printf("1. Incluir Produto\n");
        printf("2. Consultar Produto\n");
        printf("3. Alterar Produto\n");
        printf("4. Excluir Produto\n");
        printf("5. Vender Produto\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirProduto(produtos, &total);
                break;
            case 2:
                consultarProduto(produtos, total);
                break;
            case 3:
                alterarProduto(produtos, total);
                break;
            case 4:
                excluirProduto(produtos, &total);
                break;
            case 5:
                venderProduto(produtos, total);
                break;
            case 6:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}

// Função para incluir um produto
void incluirProduto(Produto *produtos, int *total) {
    if (*total >= MAX_PRODUTOS) {
        printf("Capacidade máxima de produtos atingida.\n");
        return;
    }

    Produto *novoProduto = &produtos[*total];
    novoProduto->id = *total + 1;

    printf("Insira o nome do produto: ");
    scanf(" %[^\n]", novoProduto->nome);
    printf("Insira a quantidade em estoque: ");
    scanf("%d", &novoProduto->quantidadeEmEstoque);
    printf("Insira o valor do produto: ");
    scanf("%lf", &novoProduto->valorDoProduto);

    (*total)++;
    printf("Produto inserido com sucesso!\n");
}

// Função para consultar um produto por ID
void consultarProduto(Produto *produtos, int total) {
    int id;
    printf("Digite o ID do produto para consulta: ");
    scanf("%d", &id);

    for (int i = 0; i < total; i++) {
        if (produtos[i].id == id) {
            imprimirProduto(&produtos[i]);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

// Função para alterar um produto por ID
void alterarProduto(Produto *produtos, int total) {
    int id;
    printf("Digite o ID do produto para alteração: ");
    scanf("%d", &id);

    for (int i = 0; i < total; i++) {
        if (produtos[i].id == id) {
            printf("Alterando o produto ID %d\n", id);
            printf("Nome atual: %s\n", produtos[i].nome);
            printf("Novo nome: ");
            scanf(" %[^\n]", produtos[i].nome);
            printf("Quantidade atual: %d\n", produtos[i].quantidadeEmEstoque);
            printf("Nova quantidade: ");
            scanf("%d", &produtos[i].quantidadeEmEstoque);
            printf("Valor atual: %.2f\n", produtos[i].valorDoProduto);
            printf("Novo valor: ");
            scanf("%lf", &produtos[i].valorDoProduto);
            printf("Produto alterado com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

// Função para excluir um produto por ID
void excluirProduto(Produto *produtos, int *total) {
    int id;
    printf("Digite o ID do produto para exclusão: ");
    scanf("%d", &id);

    for (int i = 0; i < *total; i++) {
        if (produtos[i].id == id) {
            for (int j = i; j < *total - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*total)--;
            printf("Produto excluído com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

// Função para vender um produto por ID, reduzindo a quantidade em estoque
void venderProduto(Produto *produtos, int total) {
    int id, quantidade;
    printf("Digite o ID do produto para venda: ");
    scanf("%d", &id);

    for (int i = 0; i < total; i++) {
        if (produtos[i].id == id) {
            printf("Produto encontrado: %s\n", produtos[i].nome);
            printf("Quantidade disponível: %d\n", produtos[i].quantidadeEmEstoque);
            printf("Insira a quantidade a ser vendida: ");
            scanf("%d", &quantidade);

            if (quantidade > produtos[i].quantidadeEmEstoque) {
                printf("Quantidade em estoque insuficiente para essa venda.\n");
            } else {
                produtos[i].quantidadeEmEstoque -= quantidade;
                double totalVenda = produtos[i].valorDoProduto * quantidade;
                printf("Venda realizada com sucesso!\n");
                printf("Total a pagar: R$ %.2f\n", totalVenda);
            }
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

// Função para imprimir os dados de um produto (usando ponteiro)
void imprimirProduto(Produto *produto) {
    printf("ID: %d\n", produto->id);
    printf("Nome: %s\n", produto->nome);
    printf("Quantidade em Estoque: %d\n", produto->quantidadeEmEstoque);
    printf("Valor do Produto: %.2f\n", produto->valorDoProduto);
}
