#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int linha, coluna;

    // Inicializa o tabuleiro com água (0)
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    int tamanhoNavio = 3;
    int podeColocar;
    
    // ---- NAVIO 1 - Horizontal ----
    int l1 = 2, c1 = 3;
    podeColocar = 1;
    if (c1 + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[l1][c1 + i] != 0) {
                podeColocar = 0;
                break;
            }
        }
    } else {
        podeColocar = 0;
    }

    if (podeColocar) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[l1][c1 + i] = 3;
        }
    } else {
        printf("Erro ao posicionar navio 1 (horizontal).\n");
    }

    // ---- NAVIO 2 - Vertical ----
    int l2 = 5, c2 = 1;
    podeColocar = 1;
    if (l2 + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[l2 + i][c2] != 0) {
                podeColocar = 0;
                break;
            }
        }
    } else {
        podeColocar = 0;
    }

    if (podeColocar) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[l2 + i][c2] = 3;
        }
    } else {
        printf("Erro ao posicionar navio 2 (vertical).\n");
    }

    // ---- NAVIO 3 - Diagonal principal ----
    int l3 = 0, c3 = 0;
    podeColocar = 1;
    if (l3 + tamanhoNavio <= 10 && c3 + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[l3 + i][c3 + i] != 0) {
                podeColocar = 0;
                break;
            }
        }
    } else {
        podeColocar = 0;
    }

    if (podeColocar) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[l3 + i][c3 + i] = 3;
        }
    } else {
        printf("Erro ao posicionar navio 3 (diagonal principal).\n");
    }

    // ---- NAVIO 4 - Diagonal secundária ----
    int l4 = 0, c4 = 9;
    podeColocar = 1;
    if (l4 + tamanhoNavio <= 10 && c4 - (tamanhoNavio - 1) >= 0) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[l4 + i][c4 - i] != 0) {
                podeColocar = 0;
                break;
            }
        }
    } else {
        podeColocar = 0;
    }

    if (podeColocar) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[l4 + i][c4 - i] = 3;
        }
    } else {
        printf("Erro ao posicionar navio 4 (diagonal secundária).\n");
    }

    // ---- Exibição do Tabuleiro ----
    printf("\nTabuleiro Final (0 = água, 3 = navio):\n\n");

    printf("    ");
    for (coluna = 0; coluna < 10; coluna++) {
        printf("%d ", coluna);
    }
    printf("\n   ---------------------\n");

    for (linha = 0; linha < 10; linha++) {
        printf("%d | ", linha);
        for (coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}

