#include <stdio.h>
#include <stdlib.h>

void inicializarTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            tabuleiro[i][j] = 0;
}

void exibirTabuleiro(int tabuleiro[10][10]) {
    printf("\n   ");
    for (int j = 0; j < 10; j++) printf("%d ", j);
    printf("\n   ---------------------\n");

    for (int i = 0; i < 10; i++) {
        printf("%d | ", i);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void aplicarHabilidade(int tabuleiro[10][10], int habilidade[][5], int habLin, int habCol, int origemX, int origemY) {
    int offsetLin = habLin / 2;
    int offsetCol = habCol / 2;

    for (int i = 0; i < habLin; i++) {
        for (int j = 0; j < habCol; j++) {
            if (habilidade[i][j] == 1) {
                int x = origemX - offsetLin + i;
                int y = origemY - offsetCol + j;
                if (x >= 0 && x < 10 && y >= 0 && y < 10 && tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

void gerarCone(int cone[3][5]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cone[i][j] = 0;
        }
    }
    // Linha 0 - 1 ponto no centro
    cone[0][2] = 1;
    // Linha 1 - 3 pontos
    cone[1][1] = 1;
    cone[1][2] = 1;
    cone[1][3] = 1;
    // Linha 2 - 5 pontos
    for (int j = 0; j < 5; j++) cone[2][j] = 1;
}

void gerarCruz(int cruz[5][5]) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cruz[i][j] = (i == 2 || j == 2) ? 1 : 0;
}

void gerarOctaedro(int octaedro[3][5]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            octaedro[i][j] = 0;

    // Linha 0 - centro
    octaedro[0][2] = 1;
    // Linha 1 - 3 pontos
    octaedro[1][1] = 1;
    octaedro[1][2] = 1;
    octaedro[1][3] = 1;
    // Linha 2 - centro
    octaedro[2][2] = 1;
}

int main() {
    int tabuleiro[10][10];
    int cone[3][5];
    int cruz[5][5];
    int octaedro[3][5];

    inicializarTabuleiro(tabuleiro);

    // Navios
    tabuleiro[6][0] = 3;
    tabuleiro[7][0] = 3;
    tabuleiro[8][0] = 3;

    tabuleiro[0][7] = 3;
    tabuleiro[0][8] = 3;
    tabuleiro[0][9] = 3;

    tabuleiro[2][8] = 3;
    tabuleiro[3][8] = 3;
    tabuleiro[4][8] = 3;

    // Gerar e aplicar habilidades
    gerarCone(cone);
    aplicarHabilidade(tabuleiro, cone, 3, 5, 1, 2); // cone no topo esquerdo

    gerarCruz(cruz);
    aplicarHabilidade(tabuleiro, cruz, 5, 5, 5, 5); // cruz no centro

    gerarOctaedro(octaedro);
    aplicarHabilidade(tabuleiro, octaedro, 3, 5, 8, 8); // octaedro no canto inferior direito

    exibirTabuleiro(tabuleiro);

    return 0;
}
