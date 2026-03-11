#include <stdio.h>
#include <string.h>

/* Desafio Super Trunfo - Países
   Tema 2 - Comparação das Cartas com Menu Interativo
*/

int main() {
    
    // Definição das variáveis para armazenar as propriedades das cidades
    char  codigoCarta_carta1[4], codigoCarta_carta2[4]; // precisa de 4 posições: "A01" + '\0'
    char  nomeCidade_carta1[50], nomeCidade_carta2[50];
    unsigned long int populacao_carta1, populacao_carta2;
    float areaKm_carta1, areaKm_carta2;
    float pib_carta1, pib_carta2;
    int   numPontosTuristicos_carta1, numPontosTuristicos_carta2;
    float densidade_carta1, densidade_carta2;
    float pibPerCapta_carta1, pibPerCapta_carta2; 
    double superPoder_carta1, superPoder_carta2;
    int opcao; // Para o menu

    /*
    Cadastrar Cartas - Cidade 1:
    */
    printf("--------------------------------------\n");
    printf("Informe os dados da CARTA 1 (País 1)\n");
    printf("--------------------------------------\n");

    printf("Código da Carta: A letra do estado seguida de um número de 01 a 04 (ex: A01, B03): "); 
    scanf("%3s", codigoCarta_carta1);
 
    printf("Nome do País: ");
    getchar(); // limpa o ENTER que sobrou
    fgets(nomeCidade_carta1, sizeof(nomeCidade_carta1), stdin);
    nomeCidade_carta1[strcspn(nomeCidade_carta1, "\n")] = 0; // remove \n    

    printf("População (O número de habitantes da cidade): "); 
    scanf("%lu", &populacao_carta1);
 
    printf("Área (em km²): ");
    scanf("%f", &areaKm_carta1);
 
    printf("PIB (O Produto Interno Bruto da cidade): "); 
    scanf("%f", &pib_carta1);
 
    printf("Número de Pontos Turísticos (A quantidade de pontos turísticos na cidade): "); 
    scanf("%d", &numPontosTuristicos_carta1);

    // Cálculo da Densidade Populacional 
    densidade_carta1 = (float) populacao_carta1 / areaKm_carta1; 
    printf("Densidade Populacional: %.2f hab/km² \n", densidade_carta1);

    // Cálculo do PIB per capita
    pibPerCapta_carta1 = (float) pib_carta1 / populacao_carta1;
    printf("PIB per Capita: %.2f reais \n", pibPerCapta_carta1);
    
    // Cálculo do Super Poder
    superPoder_carta1 = (double) populacao_carta1 + areaKm_carta1 + pib_carta1 + 
                                numPontosTuristicos_carta1 + pibPerCapta_carta1 + 
                                (1.0f / densidade_carta1);
    printf("Super Poder: %.2f \n", superPoder_carta1);

    /*
    Cadastrar Cartas - Cidade 2:
    */
    printf("\n");
    printf("--------------------------------------\n");
    printf("Informe os dados da CARTA 2 (País 2)\n");
    printf("--------------------------------------\n");

    printf("Código da Carta: A letra do estado seguida de um número de 01 a 04 (ex: A01, B03): "); 
    scanf("%3s", codigoCarta_carta2);
 
    printf("Nome do País: ");
    getchar(); // limpa o ENTER que sobrou
    fgets(nomeCidade_carta2, sizeof(nomeCidade_carta2), stdin);
    nomeCidade_carta2[strcspn(nomeCidade_carta2, "\n")] = 0;

    printf("População (O número de habitantes da cidade): "); 
    scanf("%lu", &populacao_carta2);
 
    printf("Área (em km²): ");
    scanf("%f", &areaKm_carta2);
 
    printf("PIB (O Produto Interno Bruto da cidade): "); 
    scanf("%f", &pib_carta2);
 
    printf("Número de Pontos Turísticos (A quantidade de pontos turísticos na cidade): "); 
    scanf("%d", &numPontosTuristicos_carta2);
    
    // Cálculo da Densidade Populacional 
    densidade_carta2 = (float) populacao_carta2 / areaKm_carta2; 
    printf("Densidade Populacional: %.2f hab/km² \n", densidade_carta2);

    // Cálculo do PIB per capita
    pibPerCapta_carta2 = (float) pib_carta2 / populacao_carta2;
    printf("PIB per Capita: %.2f reais \n", pibPerCapta_carta2);

    // Cálculo do Super Poder
    superPoder_carta2 = (double) populacao_carta2 + areaKm_carta2 + pib_carta2 + 
                                numPontosTuristicos_carta2 + pibPerCapta_carta2 + 
                                (1.0f / densidade_carta2);
    printf("Super Poder: %.2f \n", superPoder_carta2);

    /*
     Menu Interativo
    */
    printf("\n\n=== MENU DE COMPARAÇÃO ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per Capita\n");
    printf("7 - Super Poder\n");
    printf("Escolha o atributo para comparar: ");
    scanf("%d", &opcao);

    printf("\n--- RESULTADO DA COMPARAÇÃO ---\n");

    switch (opcao) {
        case 1: // População
            printf("População:\n");
            printf("%s: %lu habitantes\n", nomeCidade_carta1, populacao_carta1);
            printf("%s: %lu habitantes\n", nomeCidade_carta2, populacao_carta2);
            if (populacao_carta1 > populacao_carta2) {
                printf("Vencedor: %s\n", nomeCidade_carta1);
            } else if (populacao_carta2 > populacao_carta1) {
                printf("Vencedor: %s\n", nomeCidade_carta2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2: // Área
            printf("Área:\n");
            printf("%s: %.2f km²\n", nomeCidade_carta1, areaKm_carta1);
            printf("%s: %.2f km²\n", nomeCidade_carta2, areaKm_carta2);
            if (areaKm_carta1 > areaKm_carta2) {
                printf("Vencedor: %s\n", nomeCidade_carta1);
            } else if (areaKm_carta2 > areaKm_carta1) {
                printf("Vencedor: %s\n", nomeCidade_carta2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: // PIB
            printf("PIB:\n");
            printf("%s: %.2f bilhões\n", nomeCidade_carta1, pib_carta1);
            printf("%s: %.2f bilhões\n", nomeCidade_carta2, pib_carta2);
            if (pib_carta1 > pib_carta2) {
                printf("Vencedor: %s\n", nomeCidade_carta1);
            } else if (pib_carta2 > pib_carta1) {
                printf("Vencedor: %s\n", nomeCidade_carta2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("Pontos Turísticos:\n");
            printf("%s: %d\n", nomeCidade_carta1, numPontosTuristicos_carta1);
            printf("%s: %d\n", nomeCidade_carta2, numPontosTuristicos_carta2);
            if (numPontosTuristicos_carta1 > numPontosTuristicos_carta2) {
                printf("Vencedor: %s\n", nomeCidade_carta1);
            } else if (numPontosTuristicos_carta2 > numPontosTuristicos_carta1) {
                printf("Vencedor: %s\n", nomeCidade_carta2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: // Densidade Demográfica (MENOR vence)
            printf("Densidade Demográfica:\n");
            printf("%s: %.2f hab/km²\n", nomeCidade_carta1, densidade_carta1);
            printf("%s: %.2f hab/km²\n", nomeCidade_carta2, densidade_carta2);
            if (densidade_carta1 < densidade_carta2) {
                printf("Vencedor: %s (menor densidade)\n", nomeCidade_carta1);
            } else if (densidade_carta2 < densidade_carta1) {
                printf("Vencedor: %s (menor densidade)\n", nomeCidade_carta2);
            } else {
                printf("Empate!\n");
            }
            break;

       case 6: // PIB per Capita
            printf("PIB per Capita:\n");
            printf("%s: %.2f reais\n", nomeCidade_carta1, pibPerCapta_carta1);
            printf("%s: %.2f reais\n", nomeCidade_carta2, pibPerCapta_carta2);
            if (pibPerCapta_carta1 > pibPerCapta_carta2) {
                printf("Vencedor: %s\n", nomeCidade_carta1);
            } else if (pibPerCapta_carta2 > pibPerCapta_carta1) {
                printf("Vencedor: %s\n", nomeCidade_carta2);
            } else {
                printf("Empate!\n");
            }
            break;

        case 7: // Super Poder
            printf("Super Poder:\n");
            printf("%s: %.2f\n", nomeCidade_carta1, superPoder_carta1);
            printf("%s: %.2f\n", nomeCidade_carta2, superPoder_carta2);
            if (superPoder_carta1 > superPoder_carta2) {
                printf("Vencedor: %s\n", nomeCidade_carta1);
            } else if (superPoder_carta2 > superPoder_carta1) {
                printf("Vencedor: %s\n", nomeCidade_carta2);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
    }

    return 0;
}
