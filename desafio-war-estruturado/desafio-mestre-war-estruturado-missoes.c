#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ----------------------------------------------------
// Struct do território
// ----------------------------------------------------
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// ----------------------------------------------------
// Prototipando as funções 
// ----------------------------------------------------
void cadastrarTerritorios(Territorio *mapa, int qtd);
void exibirTerritorios(Territorio *mapa, int qtd);
void exibirMissao(char *corJogador, char *corMissao);
int menuAcoes();
void atacar(Territorio *atacante, Territorio *defensor);;
void executarAtaque(Territorio *mapa, int qtd);
void verificarMissao(char *corMissao, Territorio *mapa, int qtd);
void liberarMemoria(Territorio *mapa);

// ----------------------------------------------------
// MAIN
// ----------------------------------------------------
int main() {

    srand(time(NULL));

    int qtdTerritorios;

    printf("=== SISTEMA WAR ===\n");

    printf("\nQuantos territorios deseja cadastrar? ");
    scanf("%d", &qtdTerritorios);


    Territorio *mapa = calloc(qtdTerritorios, sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    cadastrarTerritorios(mapa, qtdTerritorios);

    char corJogador[10];
    char corMissao[10];

    strcpy(corJogador, mapa[0].cor);
    strcpy(corMissao, mapa[1].cor);


    int opcao;

    do {

        exibirTerritorios(mapa, qtdTerritorios);

        exibirMissao(corJogador, corMissao);

        opcao = menuAcoes();

        switch (opcao) {

            case 1:
                executarAtaque(mapa, qtdTerritorios);
                break;

            case 2:
                verificarMissao(corMissao, mapa, qtdTerritorios);
                break;

        }

    } while (opcao != 0);


    printf("\nEncerrando jogo...\n");

    liberarMemoria(mapa);

    return 0;
}

// ----------------------------------------------------
// Cadastro de territórios
// ----------------------------------------------------
void cadastrarTerritorios(Territorio *mapa, int qtd) {

    for (int i = 0; i < qtd; i++) {

        printf("\n=== Cadastro do Territorio %d ===\n", i + 1);

        printf("Nome: ");
        scanf("%s", mapa[i].nome);

        printf("Cor do exercito: ");
        scanf("%s", mapa[i].cor);

        printf("Tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}


// ----------------------------------------------------
// Mostrar mapa
// ----------------------------------------------------
void exibirTerritorios(Territorio *mapa, int qtd) {

    printf("\n============= MAPA DO MUNDO =============\n");

    for (int i = 0; i < qtd; i++) {

        printf("%d. %s (Exercito: %s , Tropas: %d)\n",
               i + 1,
               mapa[i].nome,
               mapa[i].cor,
               mapa[i].tropas);
    }

    printf("=========================================\n");
}


// ----------------------------------------------------
// Mostrar missão
// ----------------------------------------------------
void exibirMissao(char *corJogador, char *corMissao) {

    printf("\n--- SUA MISSAO (Exercito %s) ---\n", corJogador);
    printf("Destruir o exercito %s.\n", corMissao);
}


// ----------------------------------------------------
// Mostrar menu
// ----------------------------------------------------
int menuAcoes() {

    int opcao;

    printf("\n--- MENU DE ACOES ---\n");
    printf("1 - Atacar\n");
    printf("2 - Verificar Missao\n");
    printf("0 - Sair\n");

    printf("Escolha sua acao: ");
    scanf("%d", &opcao);

    return opcao;
}


// ----------------------------------------------------
// Sistema de batalha
// ----------------------------------------------------
void atacar(Territorio *atacante, Territorio *defensor) {

    int dadoAtaque = rand() % 6 + 1;
    int dadoDefesa = rand() % 6 + 1;

    printf("\n--- RESULTADO DA BATALHA ---\n");

    printf("Ataque (%s): %d | Defesa (%s): %d\n",
           atacante->nome, dadoAtaque,
           defensor->nome, dadoDefesa);

    if (dadoAtaque > dadoDefesa) {

        printf("VITORIA DO ATAQUE! O defensor perdeu 1 tropa.\n");

        if (defensor->tropas > 0)
            defensor->tropas--;

        if (defensor->tropas == 0) {

            strcpy(defensor->cor, atacante->cor);

            defensor->tropas = atacante->tropas / 2;

            printf("CONQUISTA: %s agora pertence ao exercito %s\n",
                   defensor->nome,
                   defensor->cor);
        }

    } else {

        printf("VITORIA DA DEFESA! O atacante perdeu 1 tropa.\n");

        if (atacante->tropas > 0)
            atacante->tropas--;
    }
}


// ----------------------------------------------------
// Executar ataque (fluxo completo)
// ----------------------------------------------------
void executarAtaque(Territorio *mapa, int qtd) {

    int atacanteIndex;
    int defensorIndex;

    printf("\n--- FASE DE ATAQUE ---\n");

    printf("Escolha o territorio atacante (1 a %d): ", qtd);
    scanf("%d", &atacanteIndex);

    printf("Escolha o territorio defensor (1 a %d): ", qtd);
    scanf("%d", &defensorIndex);

    atacanteIndex--;
    defensorIndex--;

    if (atacanteIndex < 0 || atacanteIndex >= qtd ||
        defensorIndex < 0 || defensorIndex >= qtd) {

        printf("\nTerritorio invalido!\n");
        return;
    }

    if (strcmp(mapa[atacanteIndex].cor, mapa[defensorIndex].cor) == 0) {

        printf("\nNao e possivel atacar territorios da mesma cor!\n");
        return;
    }

    if (mapa[atacanteIndex].tropas == 0) {

        printf("\nTerritorio sem tropas nao pode atacar!\n");
        return;
    }

    atacar(&mapa[atacanteIndex], &mapa[defensorIndex]);

    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}


// ----------------------------------------------------
// Verificar missão
// ----------------------------------------------------
void verificarMissao(char *corMissao, Territorio *mapa, int qtd) {

    for (int i = 0; i < qtd; i++) {

        if (strcmp(mapa[i].cor, corMissao) == 0) {

            printf("\nVoce ainda nao cumpriu sua missao. Continue a lutar!\n");
            return;
        }
    }

    printf("\nPARABENS! VOCE CUMPRIU SUA MISSAO!\n");
}


// ----------------------------------------------------
// Liberar memória
// ----------------------------------------------------
void liberarMemoria(Territorio *mapa) {

    free(mapa);

    printf("\nMemoria liberada com sucesso.\n");
}
