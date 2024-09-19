/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *
*---------------------------------------------------------*
* Objetivo do Programa: Calculadora HP12c                 *         
* Data – 19/09/2024                                       * 
* Autor: Natalia Yuri Ike                                 *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 4 

typedef struct {
    int valores[MAX]; 
    int topo;         
} Pilha;

void inicializaPilha(Pilha *p) {
    p->topo = -1; 
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, int valor) {
    if (!pilhaCheia(p)) {
        p->valores[++(p->topo)] = valor; 
    } else {
        printf("Erro: Pilha cheia!\n");
    }
}

int desempilhar(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->valores[(p->topo)--]; 
    } else {
        printf("Erro: Pilha vazia!\n");
        return 0; 
    }
}

int processaRPN(char entrada[]) {
    Pilha p;
    inicializaPilha(&p);

    char *token = strtok(entrada, " "); 
    
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            empilhar(&p, atoi(token));
        } 
        else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            if (p.topo < 1) { 
                printf("Erro: Operandos insuficientes!\n");
                return 0;
            }

            int b = desempilhar(&p); 
            int a = desempilhar(&p); 

            switch (token[0]) {
                case '+': empilhar(&p, a + b); break;
                case '-': empilhar(&p, a - b); break;
                case '*': empilhar(&p, a * b); break;
                case '/': 
                    if (b == 0) {
                        printf("Erro: Divisão por zero!\n");
                        return 0;
                    }
                    empilhar(&p, a / b); 
                    break;
            }
        } 
        else {
            printf("Erro: Entrada inválida!\n");
            return 0;
        }

        token = strtok(NULL, " "); 
    }

    if (p.topo == 0) {
        return desempilhar(&p); 
    } else {
        printf("Erro: Fórmula malformada!\n");
        return 0;
    }
}

int main() {
    char entrada[100];
    int continuar = 1;

    while (continuar) {
        printf("Digite a fórmula RPN (exemplo: 3 4 +): ");
        fgets(entrada, 100, stdin); 
        entrada[strcspn(entrada, "\n")] = '\0'; 

        int resultado = processaRPN(entrada);

        if (resultado != 0 || entrada[0] == '0') { 
            printf("Resultado: %d\n", resultado);
        }

        printf("Deseja fazer nova entrada? (1 - Sim / 0 - Não): ");
        scanf("%d", &continuar);
        getchar(); 
    }

    printf("Obrigado por usar nossa Calculadora Fatec-HP12c!\n");

    return 0;
}
