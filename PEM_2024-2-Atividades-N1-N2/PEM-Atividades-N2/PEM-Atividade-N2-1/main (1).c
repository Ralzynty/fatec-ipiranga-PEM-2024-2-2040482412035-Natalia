#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int troca_ocorreu;
    for (i = 0; i < n-1; i++) {
        troca_ocorreu = 0;  // Reseta a flag
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                troca_ocorreu = 1;  // Indica que uma troca ocorreu
            }
        }
        // Se não houve troca, a lista já está ordenada
        if (troca_ocorreu == 0) {
            break;
        }
    }
}



void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    int arr[n];  // Array com tamanho baseado na entrada do usuário
    printf("Digite os elementos: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array original: \n");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}
