#include <stdio.h>

// Desafio de Xadrez - MateCheck
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int main() {
    /* 
     Nível Novato - Movimentação das Peças
    */

    int opcao;
    
    // Declare variáveis constantes para representar o número de casas que cada peça pode se mover.
    const int TORRE_CASAS = 5;
    const int BISPO_CASAS = 5;
    const int RAINHA_CASAS = 8;

    // loop principal com do/while para exibir o menu
    do {
        printf("\n");
        printf("=== MENU PEÇAS DE XADREZ ===\n");
        printf("1 - Torre (%d casas para a direita)\n", TORRE_CASAS);
        printf("2 - Bispo (%d casas na diagonal cima-direita)\n", BISPO_CASAS);
        printf("3 - Rainha (%d casas para a esquerda)\n", RAINHA_CASAS);
        printf("4 - Sair\n");
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
        } else if (opcao != 4) {
            // Opção inválida
            printf("Opção inválida, tente novamente.\n");
        }

    } while (opcao != 4);

    printf("\n");
    printf("Encerrando programa !\n");

    return 0;
}
