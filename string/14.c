#include <stdio.h>
#include <string.h>

int main() {
    char palavra[51];

    printf("Digite uma palavra (maximo de 50 letras): ");
    scanf("%s", palavra);

    int comprimento = strlen(palavra);

    for (int i = 0; i < comprimento; i++) {
        palavra[i] = palavra[i] + 1;
    }

    printf("A palavra com 1 adicionado ao valor ASCII de cada caractere e: %s\n", palavra);

    return 0;
}