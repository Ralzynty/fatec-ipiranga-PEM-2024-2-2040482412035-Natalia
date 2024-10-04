/*--------------------------------------------- *
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo               *
*-----------------------------------------------*
* Objetivo do Programa: BubbleSort com Melhorias*
* Data - 04/10/2024                             * 
* Autor: Natalia Yuri Ike                       *
*-----------------------------------------------*/

#include <stdio.h>

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para exibir o array
void exibirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função Bubble Sort
void bubbleSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    
    // Solicitando a entrada de 'n'
    printf("Quantos números você deseja inserir? ");
    scanf("%d", &n);

    int arr[n];

    // Entrada dos números no array
    printf("Insira os números:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Exibindo o array original
    printf("Array original:\n");
    exibirArray(arr, n);

    // Aplicando o Bubble Sort
    bubbleSort(arr, n);

    // Exibindo o array ordenado
    printf("Array ordenado:\n");
    exibirArray(arr, n);

    return 0;
}
