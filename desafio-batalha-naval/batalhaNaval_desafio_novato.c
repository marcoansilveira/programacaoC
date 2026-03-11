#include <stdio.h>

//
// Desafio: Nível Novato
// Posicionando Navios no Tabuleiro - Batalha Naval
//
// Objetivo:
// Representar um tabuleiro 10x10 usando matriz
// Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
// Utilize `printf` para exibir as coordenadas de cada parte dos navios.
//
// Autor: Marco Silveira
//

int main() {
    // Constantes do jogo
    const int TAMANHO_TABULEIRO = 10;
    const int TAMANHO_NAVIO = 3;
    const int AGUA = 0;
    const int NAVIO = 3;

    // Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializar tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais dos navios: um navio no tabuleiro horizontalmente
    const int linhaNavioHorizontal = 2;  // começa na linha 2
    const int colunaNavioHorizontal = 4; // começa na coluna 4

    // Coordenadas iniciais dos navios: um navio no tabuleiro um verticalmente 
    const int linhaNavioVertical = 5;    // começa na linha 5
    const int colunaNavioVertical = 7;   // começa na coluna 7

    // Posicionando navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int coluna = colunaNavioHorizontal + i;
        if (coluna < TAMANHO_TABULEIRO) { // não deixa colocar navio FORA do tabuleiro (erro)
            tabuleiro[linhaNavioHorizontal][coluna] = NAVIO;
        }
    }

    // Posicionando navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linhaNavioVertical + i;
        if (linha < TAMANHO_TABULEIRO) { // não deixa colocar navio FORA do tabuleiro (erro
            if (tabuleiro[linha][colunaNavioVertical] == AGUA) {
                tabuleiro[linha][colunaNavioVertical] = NAVIO;
            }
        }
    }

    // Exibindo o tabuleiro com títulos
    printf("\n");
    printf("=== TABULEIRO BATALHA NAVAL (10x10) ===\n\n");

    // Cabeçalho das colunas
    printf("   "); // espaço para alinhar com os números das linhas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%c ", 'A' + j); // letras A, B, C, ...
    }
    printf("\n");

    // Linhas numeradas + conteúdo do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1); // imprime número da linha (1 a 10)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Legenda: 0 = Água | 3 = Navio\n");

    return 0;
}