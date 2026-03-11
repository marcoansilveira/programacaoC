#include <stdio.h>

//
// Desafio: Nível Aventureiro
// Tabuleiro Completo e Navios Diagonais
//
// Objetivo:
// - Criar um tabuleiro 10x10 representado por uma matriz.
// - Posicionar 4 navios de tamanho 3:
//     * 2 navios horizontais ou verticais.
//     * 2 navios diagonais (↘ e ↙).
// - Validar limites do tabuleiro e evitar sobreposição de navios.
// - Exibir o tabuleiro no console (0 = água, 3 = navio).
//
// Autor: Marco Silveira
//

int main() {
    // Constantes do jogo
    const int TAMANHO_TABULEIRO = 10;
    const int TAMANHO_NAVIO = 3;
    const int AGUA = 0;
    const int NAVIO = 3;

    // Matriz para representar o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializar tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais dos navios: um navio no tabuleiro horizontalmente
    const int linhaNavioHorizontal = 2;
    const int colunaNavioHorizontal = 4;

    // Coordenadas iniciais dos navios: um navio no tabuleiro verticalmente
    const int linhaNavioVertical = 5;
    const int colunaNavioVertical = 7;

    // Coordenadas iniciais dos navios: Navio diagonal ↘ (linha e coluna aumentam simultaneamente)
    const int linhaNavioDiagonal1 = 0;
    const int colunaNavioDiagonal1 = 0;

    // Coordenadas iniciais dos navios: Navio diagonal ↙ (linha aumenta, coluna diminui)
    const int linhaNavioDiagonal2 = 0;
    const int colunaNavioDiagonal2 = 9;

    // Posicionamento Navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int coluna = colunaNavioHorizontal + i;
        if (coluna < TAMANHO_TABULEIRO && tabuleiro[linhaNavioHorizontal][coluna] == AGUA) {
            tabuleiro[linhaNavioHorizontal][coluna] = NAVIO;
        }
    }

    // Posicionamento Navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linhaNavioVertical + i;
        if (linha < TAMANHO_TABULEIRO && tabuleiro[linha][colunaNavioVertical] == AGUA) {
            tabuleiro[linha][colunaNavioVertical] = NAVIO;
        }
    }

    // Posicionamento Navio diagonal ↘
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linhaNavioDiagonal1 + i;
        int coluna = colunaNavioDiagonal1 + i;
        if (linha < TAMANHO_TABULEIRO && coluna < TAMANHO_TABULEIRO && tabuleiro[linha][coluna] == AGUA) {
            tabuleiro[linha][coluna] = NAVIO; // não deixa colocar navio FORA do tabuleiro (erro)
        }
    }

    // Posicionamento Navio diagonal ↙
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linhaNavioDiagonal2 + i;
        int coluna = colunaNavioDiagonal2 - i;
        if (linha < TAMANHO_TABULEIRO && coluna >= 0 && tabuleiro[linha][coluna] == AGUA) { 
            tabuleiro[linha][coluna] = NAVIO; // não deixa colocar navio FORA do tabuleiro (erro)
        }
    }

    // -------------------------------
    // Exibir tabuleiro
    // -------------------------------

    printf("\n");
    printf("=== TABULEIRO BATALHA NAVAL (10x10) ===\n\n");

    // Cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Linhas numeradas + conteúdo do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Legenda: 0 = Água | 3 = Navio\n");

    return 0;
}