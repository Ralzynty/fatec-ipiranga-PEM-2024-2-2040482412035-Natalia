/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *                                  *                                                         *
*---------------------------------------------------------*
* Objetivo do Programa: Simulador Xeque-Pastor            *
*   ***PROGRAMA CODIFICADO DE FORMA MODULAR**             *          
* Data – 12/09/2024                                       * 
* Autor: Natalia Yuri Ike                                 *
*--------------------------------------------------------*/

#include <stdio.h>

void inicializarTabuleiro(char tabuleiro[8][8]) {
    char configuracaoInicial[8][8] = {
        {'t', 'c', 'b', 'd', 'r', 'b', 'c', 't'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'}
    };

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tabuleiro[i][j] = configuracaoInicial[i][j];
        }
    }
}

void imprimirTabuleiro(char tabuleiro[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void realizarJogada(char tabuleiro[8][8], int origemLinha, int origemColuna, int destinoLinha, int destinoColuna) {
    tabuleiro[destinoLinha][destinoColuna] = tabuleiro[origemLinha][origemColuna];
    tabuleiro[origemLinha][origemColuna] = '.';
}

int main() {
    char tabuleiro[8][8];

    inicializarTabuleiro(tabuleiro);
    printf("Tabuleiro inicial:\n");
    imprimirTabuleiro(tabuleiro);

    // Jogada 1: Peão do Rei e2 para e4
    realizarJogada(tabuleiro, 6, 4, 4, 4);
    printf("Após jogada #1 das Brancas (Peão do Rei e2 para e4):\n");
    imprimirTabuleiro(tabuleiro);

    // Jogada 2: Peão do Rei e7 para e5
    realizarJogada(tabuleiro, 1, 4, 3, 4);
    printf("Após jogada #1 das Pretas (Peão do Rei e7 para e5):\n");
    imprimirTabuleiro(tabuleiro);

    // Jogada 3: Bispo do Rei f1 para c4
    realizarJogada(tabuleiro, 7, 5, 4, 2);
    printf("Após jogada #2 das Brancas (Bispo do Rei f1 para c4):\n");
    imprimirTabuleiro(tabuleiro);

    // Jogada 4: Cavalo da Dama b8 para c6
    realizarJogada(tabuleiro, 0, 1, 2, 2);
    printf("Após jogada #2 das Pretas (Cavalo da Dama b8 para c6):\n");
    imprimirTabuleiro(tabuleiro);

    // Jogada 5: Dama d1 para h5
    realizarJogada(tabuleiro, 7, 3, 3, 7);
    printf("Após jogada #3 das Brancas (Dama d1 para h5):\n");
    imprimirTabuleiro(tabuleiro);

    // Jogada 6: Cavalo do Rei g8 para f6
    realizarJogada(tabuleiro, 0, 6, 2, 5);
    printf("Após jogada #3 das Pretas (Cavalo do Rei g8 para f6):\n");
    imprimirTabuleiro(tabuleiro);

    // Jogada 7: Dama h5 captura Peão f7 - Xeque Mate
    realizarJogada(tabuleiro, 3, 7, 1, 5);
    printf("Após jogada #4 das Brancas (Dama h5 captura Peão f7 - Xeque Mate):\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
