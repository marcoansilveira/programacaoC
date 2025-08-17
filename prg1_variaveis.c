#include <stdio.h>
#include <string.h>

int main() {

    char nome[50];
    char nome2[50];

    // printf("Ola mundo !\n");

    printf("Entre com o seu nome simples : ");

    // Entrando somentge com nome simples, pois espaços é final de string
    scanf("%s", nome); 
    getchar(); // descarta o /n no final do scanf , mas se tiver espaço bança
    printf("Seu nome é: %s\n", nome);

    // entrebaod com nome composto, mas fgets coloca /n no final da string
    printf("Entre com o seu nome composto : ");
    fgets(nome2, 50, stdin); 

    nome2[strcspn(nome2, "\n")] = 0;  // retira caracter final de linha
    printf("Seu nome é (sem enter final): %s\n", nome2);

    return 0;
}
