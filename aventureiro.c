#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3

// Função para verificar se é possível posicionar um navio
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao_linha, int direcao_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * direcao_linha;
        int c = coluna + i * direcao_coluna;
        if (l < 0 || l >= TAMANHO || c < 0 || c >= TAMANHO || tabuleiro[l][c] != 0) {
            return 0; // Fora dos limites ou sobreposição
        }
    }
    return 1; // Válido
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao_linha, int direcao_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * direcao_linha;
        int c = coluna + i * direcao_coluna;
        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa o tabuleiro com 0 (água)

    // === NAVIO 1: Horizontal ===
    int linha_h1 = 1, coluna_h1 = 2;
    if (podePosicionar(tabuleiro, linha_h1, coluna_h1, 0, 1)) {
        posicionarNavio(tabuleiro, linha_h1, coluna_h1, 0, 1);
    } else {
        printf("Erro ao posicionar navio horizontal 1\n");
        return 1;
    }

    // === NAVIO 2: Vertical ===
    int linha_v1 = 4, coluna_v1 = 5;
    if (podePosicionar(tabuleiro, linha_v1, coluna_v1, 1, 0)) {
        posicionarNavio(tabuleiro, linha_v1, coluna_v1, 1, 0);
    } else {
        printf("Erro ao posicionar navio vertical 2\n");
        return 1;
    }

    // === NAVIO 3: Diagonal ↘ (linha e coluna aumentam) ===
    int linha_d1 = 0, coluna_d1 = 0;
    if (podePosicionar(tabuleiro, linha_d1, coluna_d1, 1, 1)) {
        posicionarNavio(tabuleiro, linha_d1, coluna_d1, 1, 1);
    } else {
        printf("Erro ao posicionar navio diagonal ↘\n");
        return 1;
    }

    // === NAVIO 4: Diagonal ↙ (linha aumenta, coluna diminui) ===
    int linha_d2 = 0, coluna_d2 = 9;
    if (podePosicionar(tabuleiro, linha_d2, coluna_d2, 1, -1)) {
        posicionarNavio(tabuleiro, linha_d2, coluna_d2, 1, -1);
    } else {
        printf("Erro ao posicionar navio diagonal ↙\n");
        return 1;
    }

    // === Imprimir o tabuleiro ===
    printf("\nTabuleiro Batalha Naval:\n\n");
    for (int linha = 0; linha < TAMANHO; linha++) {
        for (int coluna = 0; coluna < TAMANHO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
