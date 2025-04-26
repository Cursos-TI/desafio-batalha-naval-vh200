#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAMANHO 10
#define TAMANHO_HABILIDADE 5
#define NAVIO 3
#define HABILIDADE 5
#define AGUA 0

// Gera matriz Cone (em forma de triângulo apontando para baixo)
void gerarCone(int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i >= j - 2 && i >= 2 - j) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Gera matriz Cruz (linha e coluna centrais)
void gerarCruz(int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            cruz[i][j] = (i == 2 || j == 2) ? 1 : 0;
        }
    }
}

// Gera matriz Octaedro (losango)
void gerarOctaedro(int oct[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                oct[i][j] = 1;
            } else {
                oct[i][j] = 0;
            }
        }
    }
}

// Aplica matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int l = origemLinha - 2 + i;
                int c = origemColuna - 2 + j;
                if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO && tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }
        }
    }
}

// Exibe o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nLegenda: 0=Água | 3=Navio | 5=Habilidade\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Posiciona dois navios
    for (int i = 0; i < 3; i++) tabuleiro[2][4 + i] = NAVIO; // Horizontal
    for (int i = 0; i < 3; i++) tabuleiro[5 + i][7] = NAVIO; // Vertical

    // Matrizes de habilidades
    int cone[5][5], cruz[5][5], oct[5][5];

    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(oct);

    // Aplica habilidades com pontos de origem fixos
    aplicarHabilidade(tabuleiro, cone, 2, 5);   // Cone na linha 2, coluna 5
    aplicarHabilidade(tabuleiro, cruz, 7, 7);   // Cruz na linha 7, coluna 7
    aplicarHabilidade(tabuleiro, oct, 5, 2);    // Octaedro na linha 5, coluna 2

    imprimirTabuleiro(tabuleiro);

    return 0;
}
