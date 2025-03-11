#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar navios no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 0) { // Horizontal
            tabuleiro[linha][coluna + i] = NAVIO;
        } else { // Vertical
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais e orientações fixas para os navios
    int linhaNavio1 = 2, colunaNavio1 = 3; // Horizontal
    int linhaNavio2 = 6, colunaNavio2 = 5; // Vertical

    // Validação simples para evitar sobreposição e limites
    if (colunaNavio1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && linhaNavio2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, 0); // Horizontal
        posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, 1); // Vertical
    }

    exibirTabuleiro(tabuleiro);
    return 0;
}
