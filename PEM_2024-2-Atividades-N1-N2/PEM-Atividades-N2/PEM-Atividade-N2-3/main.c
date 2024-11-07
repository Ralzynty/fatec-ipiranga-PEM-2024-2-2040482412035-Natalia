/*---------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular*
*          Prof. Carlos Veríssimo              *
*----------------------------------------------*
* Objetivo do Programa: Bubble Sort            *
* Data - 18/10/2024                            * 
* Autor: Natalia Yuri Ike                      *
*----------------------------------------------*/

#include <stdio.h>

void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particao(int arr[], int limInf, int limSup) {
    int pivo = arr[limSup];
    int ind = limInf - 1;

    for (int j = limInf; j < limSup; j++) {
        if (arr[j] <= pivo) {
            ind++;
            troca(&arr[ind], &arr[j]);
        }
    }
    troca(&arr[ind + 1], &arr[limSup]);
    return ind + 1;
}

void quickSort(int arr[], int limInf, int limSup) {
    if (limInf < limSup) {
        int indParticao = particao(arr, limInf, limSup);

        quickSort(arr, limInf, indParticao - 1);
        quickSort(arr, indParticao + 1, limSup);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {100, 70, 90, 90, 10, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}
