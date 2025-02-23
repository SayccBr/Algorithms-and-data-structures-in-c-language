#include <stdio.h>

int main() {
    char nome[100]; 

    printf("Digite um nome: ");
    scanf("%s", nome); 

    printf("As quatro primeiras letras do nome são: ");

    for (int i = 0; i < 4 && nome[i] != '\0'; i++) {
        printf("%c", nome[i]);
    }

    printf("\n");

    return 0;
}