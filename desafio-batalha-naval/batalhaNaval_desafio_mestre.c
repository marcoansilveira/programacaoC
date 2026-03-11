#include <stdio.h>
#include <stdlib.h>

// -------------------------------------------------------------
// Desafio: Nível Mestre
// Tabuleiro + Habilidades (Cone, Cruz, Octaedro)
//
// Objetivo:
// - Manter tabuleiro 10x10 com navios posicionados.
// - Criar matrizes 5x5 representando habilidades especiais.
// - Sobrepor habilidades no tabuleiro (sem apagar navios).
// - Exibir 4 saídas: tabuleiro original + cone + cruz + octaedro.
//
// Autor: Marco Silveira
// -------------------------------------------------------------

int main() {
    // Constantes do jogo
    const int TAMANHO_TABULEIRO = 10;  // tamanho do tabuleiro
    const int TAMANHO_NAVIO = 3;       // tamanho fixo do navio
    const int AGUA = 0;
    const int NAVIO = 3;
    const int HABILIDADE = 5;          // marcação da área de habilidade
    const int TAMANHO_HABILIDADE = 5;  // matriz 5x5 para as habilidades

    // Tabuleiro principal
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
    // Função auxiliar para imprimir
    // -------------------------------
    void imprimirTabuleiro(int t[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], const char *titulo) {
        printf("\n=== %s ===\n\n", titulo);

        // Cabeçalho
        printf("   ");
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", 'A' + j);
        }
        printf("\n");

        for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
            printf("%2d ", i + 1);
            for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
                printf("%d ", t[i][j]);
            }
            printf("\n");
        }

        printf("\nLegenda: 0=Água | 3=Navio | 5=Área Habilidade\n\n");
    }

    // Exibir tabuleiro original
    imprimirTabuleiro(tabuleiro, "TABULEIRO ORIGINAL");

    // -------------------------------
    // Habilidades (matrizes 5x5)
    // -------------------------------

    // Inicializar tabuleiro com água (0) para habilidades
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // matrizes das habilidades
    int habilidade_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Cone
    int padrao_cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
     for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
         habilidade_cone[i][j] = padrao_cone[i][j];
     }
    }

    // Cruz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade_cruz[i][j] = (i == 2 || j == 2) ? 1 : 0;
        }
    }

    // Octaedro
    int padrao_octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade_octaedro[i][j] = padrao_octaedro[i][j];
        }
    }

    // -------------------------------
    // Aplicar habilidades
    // -------------------------------
    int tabuleiro_cone[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int tabuleiro_cruz[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int tabuleiro_octaedro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Copiar tabuleiro original para cada um
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro_cone[i][j] = tabuleiro[i][j];
            tabuleiro_cruz[i][j] = tabuleiro[i][j];
            tabuleiro_octaedro[i][j] = tabuleiro[i][j];
        }
    }

    // Origem das habilidades no tabuleiro (ajuste livre)
    int origem_linha = 4, origem_coluna = 4;

    // Aplicar Cone
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade_cone[i][j] == 1) {
                int linha = origem_linha + i;
                int coluna = origem_coluna + j;
                if (linha < TAMANHO_TABULEIRO && coluna < TAMANHO_TABULEIRO &&
                    tabuleiro_cone[linha][coluna] == AGUA) {
                    tabuleiro_cone[linha][coluna] = HABILIDADE;
                }
            }
        }
    }

    // Aplicar Cruz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade_cruz[i][j] == 1) {
                int linha = origem_linha + i;
                int coluna = origem_coluna + j;
                if (linha < TAMANHO_TABULEIRO && coluna < TAMANHO_TABULEIRO &&
                    tabuleiro_cruz[linha][coluna] == AGUA) {
                    tabuleiro_cruz[linha][coluna] = HABILIDADE;
                }
            }
        }
    }

    // Aplicar Octaedro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade_octaedro[i][j] == 1) {
                int linha = origem_linha + i;
                int coluna = origem_coluna + j;
                if (linha < TAMANHO_TABULEIRO && coluna < TAMANHO_TABULEIRO &&
                    tabuleiro_octaedro[linha][coluna] == AGUA) {
                    tabuleiro_octaedro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }

    // -------------------------------
    // Saídas
    // -------------------------------
    imprimirTabuleiro(tabuleiro_cone, "TABULEIRO + HABILIDADE CONE");
    imprimirTabuleiro(tabuleiro_cruz, "TABULEIRO + HABILIDADE CRUZ");
    imprimirTabuleiro(tabuleiro_octaedro, "TABULEIRO + HABILIDADE OCTAEDRO");

    return 0;
}