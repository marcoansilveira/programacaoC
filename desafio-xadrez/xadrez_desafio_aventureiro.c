#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Objetivo: utilizar estruturas de repetição e funções para determinar
// a movimentação das peças no tabuleiro de xadrez.

// Autor: Marco Silveira
// Versão: Nível Novato + Nível Aventureiro

int main() {
    /* 
     Nível Novato - Movimentação das Peças
     Torre, Bispo e Rainha
    
     Nível Aventureiro - Movimentação do Cavalo
     O Cavalo se move em "L": 2 casas em uma direção + 1 casa perpendicular
    */

    int opcao;
    
    // Variáveis constantes para representar o número de casas que cada peça pode se mover
    const int TORRE_CASAS = 5;
    const int BISPO_CASAS = 5;
    const int RAINHA_CASAS = 8;

    const int CAVALO_BAIXO = 2;     // duas casas para baixo
    const int CAVALO_ESQUERDA = 1;  // uma casa para a esquerda

    // loop principal com do/while para exibir o menu
    do {
        printf("\n");
        printf("=== MENU PEÇAS DE XADREZ ===\n");
        printf("1 - Torre (%d casas para a direita)\n", TORRE_CASAS);
        printf("2 - Bispo (%d casas na diagonal cima-direita)\n", BISPO_CASAS);
        printf("3 - Rainha (%d casas para a esquerda)\n", RAINHA_CASAS);
        printf("4 - Cavalo (%d casas para baixo, %d para a esquerda)\n", CAVALO_BAIXO, CAVALO_ESQUERDA);
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        printf("\n");

        if (opcao == 1) {
            // TORRE → usar FOR
            printf("Movimento da Torre:\n");
            for (int i = 1; i <= TORRE_CASAS; i++) {
                printf("Casa %d: Direita\n", i);
            }

        } else if (opcao == 2) {
            // BISPO → usar WHILE
            printf("Movimento do Bispo:\n");
            int i = 1;
            while (i <= BISPO_CASAS) {
                printf("Casa %d: Cima, Direita\n", i);
                i++;
            }

        } else if (opcao == 3) {
            // RAINHA → usar DO-WHILE
            printf("Movimento da Rainha:\n");
            int i = 1;
            do {
                printf("Casa %d: Esquerda\n", i);
                i++;
            } while (i <= RAINHA_CASAS);

        } else if (opcao == 4) {
            // CAVALO → usar loops aninhados (for + while)
            printf("Movimento do Cavalo:\n");

            // Primeiro loop FOR para as duas casas para baixo
            for (int i = 1; i <= CAVALO_BAIXO; i++) {
                printf("Casa %d: Baixo\n", i);
            }

            // Segundo movimento: uma casa para a esquerda (usando WHILE aninhado)
            int j = 1;
            while (j <= CAVALO_ESQUERDA) {
                printf("Casa %d: Esquerda\n", CAVALO_BAIXO + j);
                j++;
            }

        } else if (opcao != 5) {
            // Opção inválida
            printf("Opção inválida, tente novamente.\n");
        }

    } while (opcao != 5);

    printf("\n");
    printf("Encerrando programa !\n");

    return 0;
}
