#include <stdio.h>
#include <time.h>

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

// Função Bubble Sort com medição de trocas e ciclos
void bubbleSort(int arr[], int tamanho, int *trocas, int *ciclos) {
    *trocas = 0;
    *ciclos = 0;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            (*ciclos)++;
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
                (*trocas)++;
            }
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2, 115, 113, 118, 114, 112, 125, 123, 128, 124, 122, 35, 33, 38, 34, 32, 45, 43, 48, 44, 42, 55, 53, 58, 54, 52, 65, 63, 68, 64, 62, 75, 73, 78, 74, 72, 85, 83, 88, 84, 82, 95, 93, 98, 94, 92, 15, 13, 18, 14, 12, 25, 23, 28, 24, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    int trocas, ciclos;

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    bubbleSort(arr, n, &trocas, &ciclos);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Bubble Sort:\n");
    printf("Tempo de execução: %f segundos\n", cpu_time_used);
    printf("Trocas: %d\n", trocas);
    printf("Ciclos: %d\n", ciclos);

    return 0;
}
