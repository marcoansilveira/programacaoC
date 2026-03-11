#include <stdio.h>
#include <string.h>

// ----------------------------------------------------
// Definição da estrutura Territorio
// Essa struct agrupa informações relacionadas a um
// território: nome, cor do exército e quantidade de tropas
// ----------------------------------------------------
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {

    // ----------------------------------------------------
    // Vetor para armazenar 5 territórios
    // Cada posição do vetor guarda uma struct Territorio
    // ----------------------------------------------------
    struct Territorio territorios[5];

    // ----------------------------------------------------
    // Entrada de dados dos territórios
    // O usuário irá cadastrar 5 territórios
    // ----------------------------------------------------
    printf("=== CADASTRO DE TERRITORIOS ===\n\n");

    for (int i = 0; i < 5; i++) {

        printf("Territorio %d\n", i + 1);

        printf("Nome do territorio: ");
        scanf("%s", territorios[i].nome);

        printf("Cor do exercito: ");
        scanf("%s", territorios[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");
    }

    // ----------------------------------------------------
    // Exibição dos territórios cadastrados
    // O sistema percorre o vetor e mostra os dados
    // ----------------------------------------------------
    printf("\n=== TERRITORIOS CADASTRADOS ===\n\n");

    for (int i = 0; i < 5; i++) {

        printf("Territorio %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exercito: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);

        printf("-----------------------------\n");
    }

    return 0;
}