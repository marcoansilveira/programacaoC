#include <stdio.h>
#include <string.h>

/* Desafio Super Trunfo - Países
 Tema 2 - Super Trunfo em c: Fundamentos e Técnicas Avançadas - Desafio Mestre (Mestre + Aventureiro + Novato)

*/ 

int main() {
    
    // Definição das variáveis separadas para cada atributo da cidade.
    char  estado_carta1, estado_carta2;
    char  codigoCarta_carta1[4],codigoCarta_carta2[4]; // precisa de 4 posições: "A01" + '\0'
    char  nomeCidade_carta1[50], nomeCidade_carta2[50];
    unsigned long int populacao_carta1, populacao_carta2;
    float areaKm_carta1, areaKm_carta2;
    float pib_carta1, pib_carta2;
    int   numPontosTuristicos_carta1, numPontosTuristicos_carta2;
    float densidade_carta1, densidade_carta2;
    float pibPerCapta_carta1, pibPerCapta_carta2; 
    double superPoder_carta1, superPoder_carta2;
   
    /*
    Cadastrar Cartas - Cidade 1:
    */
    printf("--------------------------------------\n");
    printf("Informe os dados da CARTA 1 (Cidade 1)\n");
    printf("--------------------------------------\n");

    printf("Estado: (Uma letra de 'A' a 'H'): ");
    scanf(" %c", &estado_carta1);   // espaço antes do "%c" para ignora o enter, tabs e espaços

    printf("Código da Carta: A letra do estado seguida de um número de 01 a 04 (ex: A01, B03): "); 
    scanf("%3s", codigoCarta_carta1);
 
    printf("Nome da Cidade: ");
    //scanf("%s", nomeCidade_carta1);
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

    // Cálculo do PIB per capita
    pibPerCapta_carta1 = (float) pib_carta1 / populacao_carta1;
    
    // Cálculo do Super Poder
    superPoder_carta1 = (double) populacao_carta1 + areaKm_carta1 + pib_carta1 + 
                                numPontosTuristicos_carta1 + pibPerCapta_carta1 + 
                                (1.0f / densidade_carta1);

    // Exibição dos Dados da Carta 1
    printf("\n");
    printf("==> CARTA 1 \n");
    printf("Estado: %c\n", estado_carta1);
    printf("Código: %s \n", codigoCarta_carta1);
    printf("Nome da cidade: %s \n", nomeCidade_carta1);
    printf("População: %lu \n", populacao_carta1);
    printf("Área: %.2f km² \n", areaKm_carta1);
    printf("PIB: %.2f bilhões de reais \n", pib_carta1);
    printf("Número de pontos turísticos: %d \n", numPontosTuristicos_carta1);
    printf("Densidade Populacional: %.2f hab/km² \n", densidade_carta1);
    printf("PIB per Capita: %.2f reais \n", pibPerCapta_carta1);
    printf("Super Poder: %.2f \n", superPoder_carta1);

    /*
    Cadastrar Cartas - Cidade 2:
    */
    printf("\n");
    printf("--------------------------------------\n");
    printf("Informe os dados da CARTA 2 (Cidade 2)\n");
    printf("--------------------------------------\n");

    printf("Estado: (Uma letra de 'A' a 'H'): ");
    scanf(" %c", &estado_carta2);   // espaço antes do "%c" para ignora o enter, tabs e espaços

    printf("Código da Carta: A letra do estado seguida de um número de 01 a 04 (ex: A01, B03): "); 
    scanf("%3s", codigoCarta_carta2);
 
    printf("Nome da Cidade: ");
    //scanf("%s", nomeCidade_carta2);
    getchar(); // limpa o ENTER que sobrou
    fgets(nomeCidade_carta2, sizeof(nomeCidade_carta2), stdin);
    nomeCidade_carta2[strcspn(nomeCidade_carta2, "\n")] = 0; // remove \n    

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

    // Cálculo do PIB per capita
    pibPerCapta_carta2 = (float) pib_carta2 / populacao_carta2;

    // Cálculo do Super Poder
    superPoder_carta2 = (double) populacao_carta2 + areaKm_carta2 + pib_carta2 + 
                                numPontosTuristicos_carta2 + pibPerCapta_carta2 + 
                                (1.0f / densidade_carta2);

    // Exibição dos Dados da Carta 2
    printf("\n");
    printf("==> CARTA 2 \n");
    printf("Estado: %c\n", estado_carta2);
    printf("Código: %s \n", codigoCarta_carta2);
    printf("Nome da cidade: %s \n", nomeCidade_carta2);
    printf("População: %lu \n", populacao_carta2);
    printf("Área: %.2f km² \n", areaKm_carta2);
    printf("PIB: %.2f bilhões de reais \n", pib_carta2);
    printf("Número de pontos turísticos: %d \n", numPontosTuristicos_carta2);
    printf("Densidade Populacional: %.2f hab/km² \n", densidade_carta2);
    printf("PIB per Capita: %.2f reais \n", pibPerCapta_carta2);
    printf("Super Poder: %.2f \n", superPoder_carta2);

    return 0;
}
