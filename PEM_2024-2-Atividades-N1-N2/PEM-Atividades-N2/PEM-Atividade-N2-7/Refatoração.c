/*---------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular*
*          Prof. Carlos Veríssimo              *
*----------------------------------------------*
* Objetivo do Programa: Refatorar o Programa   *
* Data - 25/11/2024                            * 
* Autor: Natalia Yuri Ike                      *
*----------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define MAXPRODUTOS 50

typedef struct {
    int ID;
    char nomeProduto[50];
    int quantidadeEmEstoque;
    double valorDoProduto;
} Produto;

// Funções auxiliares
int validarQuantidade(int quantidade);
double validarValor(double valor);

// Funções CRUD e operacionais
void cadastrarProduto(Produto *listaProdutos, int *contadorProduto);
void alterarProduto(Produto *listaProdutos, int ID, int contadorProduto);
void consultarProduto(Produto *listaProdutos, int ID, int contadorProduto);
void excluirProduto(Produto *listaProdutos, int ID, int *contadorProduto);
void imprimirDados(const Produto *produto);
void imprimirLista(const Produto *listaProdutos, int contadorProduto);
void venderProduto(Produto *listaProdutos, int ID, int quantidade, int contadorProduto);
void aplicarDesconto(Produto *listaProdutos, int ID, int contadorProduto);

int main() {
    Produto listaProdutos[MAXPRODUTOS];
    int contadorProduto = 0;
    int opcao, ID, quantidade;

    do {
        printf("\n------ MENU ------\n");
        printf("1. Cadastrar produto\n");
        printf("2. Alterar produto\n");
        printf("3. Consultar produto\n");
        printf("4. Excluir produto\n");
        printf("5. Listar produtos\n");
        printf("6. Vender produto\n");
        printf("7. Aplicar desconto\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(listaProdutos, &contadorProduto);
                break;
            case 2:
                printf("Digite o ID do produto a ser alterado: ");
                scanf("%d", &ID);
                alterarProduto(listaProdutos, ID, contadorProduto);
                break;
            case 3:
                printf("Digite o ID do produto a ser consultado: ");
                scanf("%d", &ID);
                consultarProduto(listaProdutos, ID, contadorProduto);
                break;
            case 4:
                printf("Digite o ID do produto a ser excluído: ");
                scanf("%d", &ID);
                excluirProduto(listaProdutos, ID, &contadorProduto);
                break;
            case 5:
                imprimirLista(listaProdutos, contadorProduto);
                break;
            case 6:
                printf("Digite o ID do produto a ser vendido: ");
                scanf("%d", &ID);
                printf("Digite a quantidade: ");
                scanf("%d", &quantidade);
                venderProduto(listaProdutos, ID, quantidade, contadorProduto);
                break;
            case 7:
                printf("Digite o ID do produto para aplicar desconto: ");
                scanf("%d", &ID);
                aplicarDesconto(listaProdutos, ID, contadorProduto);
                break;
            case 8:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}

// Validação de quantidade
int validarQuantidade(int quantidade) {
    if (quantidade < 0) {
        printf("Quantidade inválida. Deve ser maior ou igual a zero. Digite novamente: ");
        scanf("%d", &quantidade);
    }
    return quantidade;
}

// Validação de valor
double validarValor(double valor) {
    if (valor < 0) {
        printf("Valor inválido. Deve ser maior ou igual a zero. Digite novamente: ");
        scanf("%lf", &valor);
    }
    return valor;
}

// Cadastrar um novo produto
void cadastrarProduto(Produto *listaProdutos, int *contadorProduto) {
    if (*contadorProduto >= MAXPRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    Produto *produto = &listaProdutos[*contadorProduto];
    produto->ID = *contadorProduto + 1;

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", produto->nomeProduto);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto->quantidadeEmEstoque);
    produto->quantidadeEmEstoque = validarQuantidade(produto->quantidadeEmEstoque);

    printf("Digite o valor do produto: ");
    scanf("%lf", &produto->valorDoProduto);
    produto->valorDoProduto = validarValor(produto->valorDoProduto);

    (*contadorProduto)++;
    printf("Produto cadastrado com sucesso!\n");
}

// Alterar dados de um produto por ID
void alterarProduto(Produto *listaProdutos, int ID, int contadorProduto) {
    for (int i = 0; i < contadorProduto; i++) {
        if (listaProdutos[i].ID == ID) {
            printf("Alterando produto: %s\n", listaProdutos[i].nomeProduto);

            printf("Novo nome do produto: ");
            scanf(" %[^\n]", listaProdutos[i].nomeProduto);

            printf("Nova quantidade em estoque: ");
            scanf("%d", &listaProdutos[i].quantidadeEmEstoque);
            listaProdutos[i].quantidadeEmEstoque = validarQuantidade(listaProdutos[i].quantidadeEmEstoque);

            printf("Novo valor do produto: ");
            scanf("%lf", &listaProdutos[i].valorDoProduto);
            listaProdutos[i].valorDoProduto = validarValor(listaProdutos[i].valorDoProduto);

            printf("Produto alterado com sucesso!\n");
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", ID);
}

// Consultar produto por ID
void consultarProduto(Produto *listaProdutos, int ID, int contadorProduto) {
    for (int i = 0; i < contadorProduto; i++) {
        if (listaProdutos[i].ID == ID) {
            imprimirDados(&listaProdutos[i]);
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", ID);
}

// Excluir produto por ID
void excluirProduto(Produto *listaProdutos, int ID, int *contadorProduto) {
    for (int i = 0; i < *contadorProduto; i++) {
        if (listaProdutos[i].ID == ID) {
            for (int j = i; j < *contadorProduto - 1; j++) {
                listaProdutos[j] = listaProdutos[j + 1];
            }
            (*contadorProduto)--;
            printf("Produto excluído com sucesso!\n");
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", ID);
}

// Imprimir dados de um produto
void imprimirDados(const Produto *produto) {
    printf("\nID: %d\n", produto->ID);
    printf("Nome: %s\n", produto->nomeProduto);
    printf("Quantidade em Estoque: %d\n", produto->quantidadeEmEstoque);
    printf("Valor: %.2f\n\n", produto->valorDoProduto);
}

// Listar todos os produtos cadastrados
void imprimirLista(const Produto *listaProdutos, int contadorProduto) {
    printf("\nProdutos cadastrados:\n");
    for (int i = 0; i < contadorProduto; i++) {
        printf("ID: %d - Nome: %s\n", listaProdutos[i].ID, listaProdutos[i].nomeProduto);
    }
    printf("\n");
}

// Realizar a venda de um produto
void venderProduto(Produto *listaProdutos, int ID, int quantidade, int contadorProduto) {
    for (int i = 0; i < contadorProduto; i++) {
        if (listaProdutos[i].ID == ID) {
            if (listaProdutos[i].quantidadeEmEstoque >= quantidade) {
                listaProdutos[i].quantidadeEmEstoque -= quantidade;
                printf("Venda realizada. Total: %.2f\n", listaProdutos[i].valorDoProduto * quantidade);
                return;
            } else {
                printf("Estoque insuficiente.\n");
                return;
            }
        }
    }
    printf("Produto com ID %d não encontrado.\n", ID);
}

// Aplicar desconto no preço de um produto
void aplicarDesconto(Produto *listaProdutos, int ID, int contadorProduto) {
    for (int i = 0; i < contadorProduto; i++) {
        if (listaProdutos[i].ID == ID) {
            double desconto;
            printf("Digite o percentual de desconto: ");
            scanf("%lf", &desconto);
            listaProdutos[i].valorDoProduto *= (1 - desconto / 100);
            printf("Desconto aplicado! Novo valor: %.2f\n", listaProdutos[i].valorDoProduto);
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", ID);
}
