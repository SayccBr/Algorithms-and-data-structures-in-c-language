#include <stdio.h>
#include <string.h>

int main() {
    char palavra[100];
    char substituto;
    int numVogais = 0;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    printf("Digite um caractere para substituir as vogais: ");
    scanf(" %c", &substituto); // Espaço antes de %c para consumir a quebra de linha anterior

    int comprimento = strlen(palavra);

    for (int i = 0; i < comprimento; i++) {
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u' ||
            palavra[i] == 'A' || palavra[i] == 'E' || palavra[i] == 'I' || palavra[i] == 'O' || palavra[i] == 'U') {
            palavra[i] = substituto;
            numVogais++;
        }
    }

    printf("A palavra modificada e: %s\n", palavra);
    printf("O numero de vogais na palavra original era: %d\n", numVogais);

    return 0;
}