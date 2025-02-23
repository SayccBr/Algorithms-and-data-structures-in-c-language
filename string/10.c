#include <stdio.h>
#include <string.h>

int main() {
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int comprimento = strlen(palavra);

    printf("A palavra de trás para frente é: ");

    for (int i = comprimento - 1; i >= 0; i--) {
        printf("%c", palavra[i]);
    }

    printf("\n");

    return 0;
}