/*------------------------------------------------------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular                                                         *
*          Prof. Carlos Veríssimo                                                                       *
*-------------------------------------------------------------------------------------------------------*
* Objetivo do Programa: Desenvolver um programa em C que demonstre a ocupação de um tabuleiro de xadrez *
* Data - 29/08/2024                                                                                     * 
* Autor: Natalia Yuri Ike                                                                               *
*------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define SIZE 64
#define ROWS 8
#define COLS 8

void initializeBoard(char board[ROWS][COLS][4]) {
    // Limpar o tabuleiro (tudo é " X ")
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            strcpy(board[i][j], " X ");
        }
    }

    // Definindo as peças das brancas
    // Torres
    strcpy(board[0][0], "BT1"); strcpy(board[0][7], "BT2");
    // Cavalos
    strcpy(board[0][1], "BC1"); strcpy(board[0][6], "BC2");
    // Bispos
    strcpy(board[0][2], "BB1"); strcpy(board[0][5], "BB2");
    // Rainha
    strcpy(board[0][3], "BD ");
    // Rei
    strcpy(board[0][4], "BR ");
    // Peões
    for (int j = 0; j < COLS; j++) {
        sprintf(board[1][j], "BP%d", j + 1);
    }

    // Definindo as peças das pretas
    // Torres
    strcpy(board[7][0], "PT1"); strcpy(board[7][7], "PT2");
    // Cavalos
    strcpy(board[7][1], "PC1"); strcpy(board[7][6], "PC2");
    // Bispos
    strcpy(board[7][2], "PB1"); strcpy(board[7][5], "PB2");
    // Rainha
    strcpy(board[7][3], "PD ");
    // Rei
    strcpy(board[7][4], "PR ");
    // Peões
    for (int j = 0; j < COLS; j++) {
        sprintf(board[6][j], "PP%d", j + 1);
    }
}

void printBoard(char board[ROWS][COLS][4]) {
    printf("   a   b   c   d   e   f   g   h\n");
    for (int i = ROWS - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("%s ", board[i][j]);
        }
        printf("%d\n", i + 1);
    }
    printf("   a   b   c   d   e   f   g   h\n");
}

int main() {
    char board[ROWS][COLS][4];

    initializeBoard(board);
    printBoard(board);

    return 0;
}