#include <stdio.h>
#include <string.h>

int main() {

    // Carta 1
    char  estado_carta1, estado_carta2;
    char  codigoCarta_carta1[4],codigoCarta_carta2[4]; // precisa de 4 posições: "A01" + '\0'
    char  nomeCidade_carta1[50], nomeCidade_carta2[50];
    int   populacao_carta1, populacao_carta2;
    float areaKm_carta1, areaKm_carta2;
    float pib_carta1, pib_carta2;
    int   numPontosTuristicos_carta1, numPontosTuristicos_carta2;

    /*
    INFORMANDO OS DADOS DA CARTA 1
    */
    printf("Informe os dados da CARTA 1\n");
    printf("---------------------------\n");

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
    scanf("%d", &populacao_carta1);
 
    printf("Área (em km²): ");
    scanf("%f", &areaKm_carta1);
 
    printf("PIB (O Produto Interno Bruto da cidade): "); 
    scanf("%f", &pib_carta1);
 
    printf("Número de Pontos Turísticos (A quantidade de pontos turísticos na cidade): "); 
    scanf("%d", &numPontosTuristicos_carta1);

    /*
    INFORMANDO OS DADOS DA CARTA 2
    */
    printf("\n");
    printf("Informe os dados da CARTA 2\n");
    printf("---------------------------\n");

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
    scanf("%d", &populacao_carta2);
 
    printf("Área (em km²): ");
    scanf("%f", &areaKm_carta2);
 
    printf("PIB (O Produto Interno Bruto da cidade): "); 
    scanf("%f", &pib_carta2);
 
    printf("Número de Pontos Turísticos (A quantidade de pontos turísticos na cidade): "); 
    scanf("%d", &numPontosTuristicos_carta2);

    /*
    IMPRIMINDO OS DADOS EM TELA
    */
    printf("\n==> RESULTADO <==\n");
    printf(" * A CARTA 1 é do estado [%c], código da carta [%s], cidade [%s], população [%d], área (km2) [%.2f], PIB [%.2f], número pontos turísticos [%d]\n", 
        estado_carta1, 
        codigoCarta_carta1,
        nomeCidade_carta1,
        populacao_carta1,
        areaKm_carta1,
        pib_carta1,
        numPontosTuristicos_carta1
    );

    printf(" * CARTA 2 é do estado [%c], código da carta [%s], cidade [%s], população [%d], área (km2) [%.2f], PIB [%.2f], número pontos turísticos [%d]\n", 
        estado_carta2, 
        codigoCarta_carta2,
        nomeCidade_carta2,
        populacao_carta2,
        areaKm_carta2,
        pib_carta2,
        numPontosTuristicos_carta2
    );
  
    return 0;
}

