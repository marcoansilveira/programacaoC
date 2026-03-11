#include <stdio.h>
#include <string.h>

/* Desafio Super Trunfo - Países:  Desafio Mestre
   Tema 3 - Comparação de Cartas com Dois Atributos
*/

int main() {
    
    // Variáveis para armazenar as cartas
    char  codigoCarta_carta1[4], codigoCarta_carta2[4]; 
    char  nomePais_carta1[50], nomePais_carta2[50];
    unsigned long int populacao_carta1, populacao_carta2;
    float areaKm_carta1, areaKm_carta2;
    float pib_carta1, pib_carta2;
    int   numPontosTuristicos_carta1, numPontosTuristicos_carta2;
    float densidade_carta1, densidade_carta2;
    float pibPerCapta_carta1, pibPerCapta_carta2; 
    double superPoder_carta1, superPoder_carta2;

    float valor1_carta1 = 0, valor1_carta2 = 0;  
    float valor2_carta1 = 0, valor2_carta2 = 0;
    float soma_carta1 = 0, soma_carta2 = 0;

    int opcao1, opcao2; 

    /*
    Cadastrar Carta 1
    */
    printf("Informe os dados da CARTA 1 (País 1)\n");
    printf("Código da Carta: ");
    scanf("%3s", codigoCarta_carta1);

    printf("Nome do País: ");
    getchar(); 
    fgets(nomePais_carta1, sizeof(nomePais_carta1), stdin);
    nomePais_carta1[strcspn(nomePais_carta1, "\n")] = 0;   

    printf("População: "); 
    scanf("%lu", &populacao_carta1);

    printf("Área (em km²): ");
    scanf("%f", &areaKm_carta1);

    printf("PIB: "); 
    scanf("%f", &pib_carta1);

    printf("Número de Pontos Turísticos: "); 
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
    Cadastrar Carta 2
    */
    printf("\n");
    printf("Informe os dados da CARTA 2 (País 2)\n");
    printf("Código da Carta: "); 
    scanf("%3s", codigoCarta_carta2);

    printf("Nome do País: ");
    getchar(); 
    fgets(nomePais_carta2, sizeof(nomePais_carta2), stdin);
    nomePais_carta2[strcspn(nomePais_carta2, "\n")] = 0;

    printf("População: "); 
    scanf("%lu", &populacao_carta2);

    printf("Área (em km²): ");
    scanf("%f", &areaKm_carta2);

    printf("PIB: "); 
    scanf("%f", &pib_carta2);

    printf("Número de Pontos Turísticos: "); 
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
     Menu Interativo - Escolha de DOIS atributos
    */
    printf("\n\n");
    printf("=== MENU DE COMPARAÇÃO ===\n");
    printf("Escolha o PRIMEIRO atributo:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (menor vence)\n");
    printf("6 - PIB per Capita\n");
    printf("7 - Super Poder\n");
    printf("Escolha o PRIMEIRO atributo: ");
    scanf("%d", &opcao1);

    printf("\n");
    printf("Escolha o SEGUNDO atributo (diferente do primeiro):\n");
    if (opcao1 != 1) printf("1 - População\n");
    if (opcao1 != 2) printf("2 - Área\n");
    if (opcao1 != 3) printf("3 - PIB\n");
    if (opcao1 != 4) printf("4 - Número de Pontos Turísticos\n");
    if (opcao1 != 5) printf("5 - Densidade Demográfica\n");
    if (opcao1 != 6) printf("6 - PIB per Capita\n");
    if (opcao1 != 7) printf("7 - Super Poder\n");
    printf("Opção: ");
    scanf("%d", &opcao2);

    /*
     Comparação dos dois atributos (sem for)
    */
    // PRIMEIRO atributo
    switch (opcao1) {
        case 1: valor1_carta1 = populacao_carta1; valor1_carta2 = populacao_carta2; break;
        case 2: valor1_carta1 = areaKm_carta1;    valor1_carta2 = areaKm_carta2; break;
        case 3: valor1_carta1 = pib_carta1;       valor1_carta2 = pib_carta2; break;
        case 4: valor1_carta1 = numPontosTuristicos_carta1; valor1_carta2 = numPontosTuristicos_carta2; break;
        case 5: valor1_carta1 = densidade_carta1; valor1_carta2 = densidade_carta2; break;
        case 6: valor1_carta1 = pibPerCapta_carta1; valor1_carta2 = pibPerCapta_carta2; break;
        case 7: valor1_carta1 = superPoder_carta1; valor1_carta2 = superPoder_carta2; break;
        default: printf("Opção inválida!\n");
            return 1;
    }

    // SEGUNDO atributo
    switch (opcao2) {
        case 1: valor2_carta1 = populacao_carta1; valor2_carta2 = populacao_carta2; break;
        case 2: valor2_carta1 = areaKm_carta1;    valor2_carta2 = areaKm_carta2; break;
        case 3: valor2_carta1 = pib_carta1;       valor2_carta2 = pib_carta2; break;
        case 4: valor2_carta1 = numPontosTuristicos_carta1; valor2_carta2 = numPontosTuristicos_carta2; break;
        case 5: valor2_carta1 = densidade_carta1; valor2_carta2 = densidade_carta2; break;
        case 6: valor2_carta1 = pibPerCapta_carta1; valor2_carta2 = pibPerCapta_carta2; break;
        case 7: valor2_carta1 = superPoder_carta1; valor2_carta2 = superPoder_carta2; break;
        default: printf("Opção inválida!\n"); 
            return 1;
    }

    /*
     Ajuste: densidade demográfica (menor vence → invertido)
    */
    valor1_carta1 = (opcao1 == 5) ? -valor1_carta1 : valor1_carta1;
    valor1_carta2 = (opcao1 == 5) ? -valor1_carta2 : valor1_carta2;
    valor2_carta1 = (opcao2 == 5) ? -valor2_carta1 : valor2_carta1;
    valor2_carta2 = (opcao2 == 5) ? -valor2_carta2 : valor2_carta2;

    soma_carta1 = valor1_carta1 + valor2_carta1;
    soma_carta2 = valor1_carta2 + valor2_carta2;

    /*
     Resultado Final
    */
    printf("\n--- RESULTADO ---\n");
    //printf("%s: %.2f + %.2f = %.2f\n", nomePais_carta1, valor1_carta1, valor2_carta1, soma_carta1);
    //printf("%s: %.2f + %.2f = %.2f\n", nomePais_carta2, valor1_carta2, valor2_carta2, soma_carta2);

    /* CARTA 1 */
    printf("%s: %.2f ", nomePais_carta1, valor1_carta1);
    if (opcao1 == 1)       printf("(População) ");
    else if (opcao1 == 2)  printf("(Área) ");
    else if (opcao1 == 3)  printf("(PIB) ");
    else if (opcao1 == 4)  printf("(Número de Pontos Turísticos) ");
    else if (opcao1 == 5)  printf("(Densidade Demográfica) ");
    else if (opcao1 == 6)  printf("(PIB per Capita) ");
    else                   printf("(Super Poder) ");

    printf("+ %.2f ", valor2_carta1);
    if (opcao2 == 1)       printf("(População) ");
    else if (opcao2 == 2)  printf("(Área) ");
    else if (opcao2 == 3)  printf("(PIB) ");
    else if (opcao2 == 4)  printf("(Número de Pontos Turísticos) ");
    else if (opcao2 == 5)  printf("(Densidade Demográfica) ");
    else if (opcao2 == 6)  printf("(PIB per Capita) ");
    else                   printf("(Super Poder) ");

    printf("= %.2f\n", soma_carta1);

    /* CARTA 2 */
    printf("%s: %.2f ", nomePais_carta2, valor1_carta2);
    if (opcao1 == 1)       printf("(População) ");
    else if (opcao1 == 2)  printf("(Área) ");
    else if (opcao1 == 3)  printf("(PIB) ");
    else if (opcao1 == 4)  printf("(Número de Pontos Turísticos) ");
    else if (opcao1 == 5)  printf("(Densidade Demográfica) ");
    else if (opcao1 == 6)  printf("(PIB per Capita) ");
    else                   printf("(Super Poder) ");

    printf("+ %.2f ", valor2_carta2);
    if (opcao2 == 1)       printf("(População) ");
    else if (opcao2 == 2)  printf("(Área) ");
    else if (opcao2 == 3)  printf("(PIB) ");
    else if (opcao2 == 4)  printf("(Número de Pontos Turísticos) ");
    else if (opcao2 == 5)  printf("(Densidade Demográfica) ");
    else if (opcao2 == 6)  printf("(PIB per Capita) ");
    else                   printf("(Super Poder) ");

    printf("= %.2f\n", soma_carta2);

    /* VENCEDOR */
    (soma_carta1 > soma_carta2) ?
        printf(">>> Vencedor: %s <<<\n", nomePais_carta1) :
        (soma_carta2 > soma_carta1) ?
            printf(">>> Vencedor: %s <<<\n", nomePais_carta2) :
            printf(">>> Empate! <<<\n");

    return 0;
}
