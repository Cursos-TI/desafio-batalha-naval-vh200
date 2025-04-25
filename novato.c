#include <stdio.h>

// Tamanho do tabuleiro
#define TAMANHO 10
// Valor que representa um navio no tabuleiro
#define NAVIO 3
// Tamanho dos navios
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa toda a matriz com 0 (água)

    // Coordenadas iniciais do navio horizontal (linha, coluna)
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    // Coordenadas iniciais do navio vertical (linha, coluna)
    int linha_vertical = 5;
    int coluna_vertical = 7;

    int i;

    // Validação de limites para o navio horizontal
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se há sobreposição
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0) {
                printf("Erro: sobreposição de navios na posição (%d, %d)\n", linha_horizontal, coluna_horizontal + i);
                return 1;
            }
            tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Validação de limites para o navio vertical
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se há sobreposição
            if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
                printf("Erro: sobreposição de navios na posição (%d, %d)\n", linha_vertical + i, coluna_vertical);
                return 1;
            }
            tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
        }
    } else {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro Batalha Naval:\n\n");
    for (int linha = 0; linha < TAMANHO; linha++) {
        for (int coluna = 0; coluna < TAMANHO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
