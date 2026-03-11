#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ----------------------------------------------------
// Struct que representa um território do jogo
// ----------------------------------------------------
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// ----------------------------------------------------
// Função para cadastrar territórios
// Recebe ponteiro para o vetor de territórios
// ----------------------------------------------------
void cadastrarTerritorios(Territorio *mapa, int quantidade) {

    for (int i = 0; i < quantidade; i++) {

        printf("\n=== Cadastro do Territorio %d ===\n", i + 1);

        printf("Nome do territorio: ");
        scanf("%s", mapa[i].nome);

        printf("Cor do exercito: ");
        scanf("%s", mapa[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

// ----------------------------------------------------
// Função para exibir territórios cadastrados
// ----------------------------------------------------
void exibirTerritorios(Territorio *mapa, int quantidade) {

    printf("\n=== TERRITORIOS CADASTRADOS ===\n");

    for (int i = 0; i < quantidade; i++) {

        printf("\n%d. Territorio (", i + 1);
        printf("Nome: %s", mapa[i].nome);
        printf(", Cor: %s", mapa[i].cor);
        printf(", Tropas: %d)", mapa[i].tropas);
    }
}

// ----------------------------------------------------
// Função que simula um ataque entre territórios
// ----------------------------------------------------
void atacar(Territorio *atacante, Territorio *defensor) {

    int dadoAtaque = rand() % 6 + 1;
    int dadoDefesa = rand() % 6 + 1;

    printf("\n=== FASE DE ATAQUE ===\n");

    printf("O Atacante: %s (%s) rolou um dado e tirou %d\n", atacante->nome, atacante->cor, dadoAtaque);
    printf("O Defensor: %s (%s) rolou um dado e tirou %d \n", defensor->nome, defensor->cor, dadoDefesa);

    printf("\n=== RESULTADO DA BATALHA ===\n");
    if (dadoAtaque > dadoDefesa) {

        printf("\n>>> VITORIA DO ATAQUE ! O defensor perdeu 1 tropa \n");

        if (defensor->tropas > 0) {
            defensor->tropas--;

            if (defensor->tropas == 0) {
                strcpy(defensor->cor, atacante->cor);

                defensor->tropas = atacante->tropas / 2;

                printf("\nCONQUISTA: O território %s foi dominado pelo exército %s\n", defensor->cor, atacante->cor);
            }    
        }

    } else {

        printf("\n>>> DEFENSOR RESISTIU ! O atacante perdeu 1 tropa !\n");

        if (atacante->tropas > 0) {
            atacante->tropas--;
        }
    }
}

// ----------------------------------------------------
// Função para liberar memória alocada
// ----------------------------------------------------
void liberarMemoria(Territorio *mapa) {

    free(mapa);

    printf("\nMemoria liberada com sucesso.\n");
}

// ----------------------------------------------------
// Função principal
// ----------------------------------------------------
int main() {

    int quantidadeTerritorios;

    srand(time(NULL));

    printf("=== SISTEMA WAR ESTRUTURADO ===\n");

    printf("\nQuantos territorios deseja cadastrar? ");
    scanf("%d", &quantidadeTerritorios);

    // ------------------------------------------------
    // Alocação dinâmica de memória
    // ------------------------------------------------
    Territorio *mapa = calloc(quantidadeTerritorios, sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Cadastro
    cadastrarTerritorios(mapa, quantidadeTerritorios);

    // Exibição
    exibirTerritorios(mapa, quantidadeTerritorios);

    // ------------------------------------------------
    // Seleção de ataque
    // ------------------------------------------------
    int atacanteIndex;
    int defensorIndex;

    while (1) {

        printf("\n=====================================\n");
        printf("Escolha o territorio atacante (1 a %d) ou 0 para sair: ", quantidadeTerritorios);
        scanf("%d", &atacanteIndex);

        // Se digitar 0 encerra o jogo
        if (atacanteIndex == 0) {
            printf("\nEncerrando o jogo...\n");
            break;
        }

        printf("Escolha o territorio defensor (1 a %d): ", quantidadeTerritorios);
        scanf("%d", &defensorIndex);

        // Ajustar índices (vetor começa em 0)
        atacanteIndex--;
        defensorIndex--;

        // Validação básica de limites
        if (atacanteIndex < 0 || atacanteIndex >= quantidadeTerritorios ||
            defensorIndex < 0 || defensorIndex >= quantidadeTerritorios) {
            printf("\nTerritorio invalido! Tente novamente.\n");
            continue;
        }

        // Não permitir ataque entre territórios da mesma cor
        if (strcmp(mapa[atacanteIndex].cor, mapa[defensorIndex].cor) == 0) {
            printf("\nNao e possivel atacar um territorio da mesma cor!\n");
            continue;
        }

        // Não permitir ataque entre territórios da mesma cor
        if (mapa[atacanteIndex].tropas == 0) {
            printf("\nNao e possivel atacar um territorio sem tropas!\n");
            continue;
        }

        // Executar ataque
        atacar(&mapa[atacanteIndex], &mapa[defensorIndex]);

        // Mostrar estado do mapa após ataque
        exibirTerritorios(mapa, quantidadeTerritorios);
    }

    // Liberar memória
    liberarMemoria(mapa);

    return 0;
}