#include <stdio.h>
#include <stdlib.h>

    float calcular_nota_final(int n, float notas[]) {
    float maior, menor, soma = 0.0;
    float soma_total = 0.0;
    
    maior = menor = notas[0];
    
    for (int i = 0; i < n; i++) {
        soma_total += notas[i];
        if (notas[i] > maior) {
            maior = notas[i];
        }
        if (notas[i] < menor) {
            menor = notas[i];
        }
    }
    
    soma = soma_total - maior - menor;
    
    return soma;
}

int main() {
    int n;
    float notas[100];
    char *nomes_provas[] = {
        "Raciocínio lógico",
        "conceitos de gerenciamento de projetos",
        "lingua inglesa",
        "conceitos de metodologia ágil",
        "linguagem javascript"
    };
    int num_provas = sizeof(nomes_provas) / sizeof(nomes_provas[0]);
    float nota_total_candidato = 0.0;
    
    for (int i = 0; i < num_provas; i++) {
        printf("Entre com o número de notas para %s: ", nomes_provas[i]);
        scanf("%d", &n);
        
        if (n <= 2) {
            printf("Número de notas deve ser maior que 2.\n");
            return 1;
        }
        
        printf("Entre com as %d notas separadas por espaço: ", n);
        for (int j = 0; j < n; j++) {
            scanf("%f", &notas[j]);
        }
        
        float nota_final = calcular_nota_final(n, notas);
        printf("Nota %s = %.0f\n", nomes_provas[i], nota_final);
        
        nota_total_candidato += nota_final;
    }
    
    printf("Nota final do candidato = %.0f\n", nota_total_candidato);
    
    return 0;
}
