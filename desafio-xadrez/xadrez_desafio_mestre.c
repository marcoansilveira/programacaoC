#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Objetivo: utilizar recursividade e loops complexos para simular
// a movimentação das peças no tabuleiro de xadrez.
//
// Autor: Marco Silveira
// Versão: Nível Mestre

/* 
 Nível Novato - Torre, Bispo e Rainha (com loops simples)
 Nível Aventureiro - Cavalo (com loops aninhados)
 Nível Mestre - Recursividade e Loops Complexos
*/

// Função recursiva para movimentação da Torre
void moverTorre(int casas, int atual) {
    if (atual > casas) return; // condição de parada
    printf("Casa %d: Direita\n", atual);
    moverTorre(casas, atual + 1);
}

// Função recursiva para movimentação da Rainha
void moverRainha(int casas, int atual) {
    if (atual > casas) return;
    printf("Casa %d: Esquerda\n", atual);
    moverRainha(casas, atual + 1);
}

// Função recursiva para movimentação do Bispo
// (com loops aninhados para representar diagonal: cima + direita)
void moverBispo(int casas, int vertical, int horizontal) {
    if (vertical > casas) return;

    for (int i = 1; i <= horizontal; i++) {
        printf("Casa %d: Cima, Direita\n", vertical);
    }

    moverBispo(casas, vertical + 1, horizontal);
}

int main() {
    int opcao;

    // Variáveis constantes para representar o número de casas
    const int TORRE_CASAS = 5;
    const int BISPO_CASAS = 5;
    const int RAINHA_CASAS = 8;

    const int CAVALO_CIMA = 2;     // duas casas para cima
    const int CAVALO_DIREITA = 1;  // uma casa para a direita

    // loop principal com do/while para exibir o menu
    do {
        printf("\n");
        printf("=== MENU PEÇAS DE XADREZ - NÍVEL MESTRE ===\n");
        printf("1 - Torre (recursividade: %d casas para a direita)\n", TORRE_CASAS);
        printf("2 - Bispo (recursividade + loops aninhados: %d casas na diagonal cima-direita)\n", BISPO_CASAS);
        printf("3 - Rainha (recursividade: %d casas para a esquerda)\n", RAINHA_CASAS);
        printf("4 - Cavalo (loops complexos: %d casas para cima, %d para a direita)\n", CAVALO_CIMA, CAVALO_DIREITA);
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        printf("\n");

        if (opcao == 1) {
            // TORRE → recursividade
            printf("Movimento da Torre:\n");
            moverTorre(TORRE_CASAS, 1);

        } else if (opcao == 2) {
            // BISPO → recursividade + loops aninhados
            printf("Movimento do Bispo:\n");
            moverBispo(BISPO_CASAS, 1, 1);

        } else if (opcao == 3) {
            // RAINHA → recursividade
            printf("Movimento da Rainha:\n");
            moverRainha(RAINHA_CASAS, 1);

        } else if (opcao == 4) {
            // CAVALO → loops complexos (for + while + break/continue)
            printf("Movimento do Cavalo:\n");

            int movCima = 0, movDireita = 0;

            for (int i = 1; i <= CAVALO_CIMA + CAVALO_DIREITA; i++) {
                if (movCima < CAVALO_CIMA) {
                    printf("Casa %d: Cima\n", i);
                    movCima++;
                    continue; // volta para o próximo movimento
                }

                while (movDireita < CAVALO_DIREITA) {
                    printf("Casa %d: Direita\n", i);
                    movDireita++;
                    break; // finaliza o movimento do Cavalo
                }
            }

        } else if (opcao != 5) {
            printf("Opção inválida, tente novamente.\n");
        }

    } while (opcao != 5);

    printf("\n");
    printf("Encerrando programa !\n");

    return 0;
}
