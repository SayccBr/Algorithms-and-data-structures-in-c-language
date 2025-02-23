#include <stdio.h>
#include <string.h>

int main() {
    char vogais[11] = "aeiouAEIOU";
    char teste[100];
    int i, j, total = 0;
    int tam1, tam2;

    printf("Digite uma string: ");
    fgets(teste, 100, stdin);

    tam1 = strlen(teste) - 1; // Subtrai 1 para remover o caractere '\n' inserido pelo fgets
    tam2 = strlen(vogais);

    for (i = 0; i < tam1; i++) {
        for (j = 0; j < tam2; j++) {
            if (teste[i] == vogais[j]) {
                total++;
                break;
            }
        }
    }

    printf("O numero de vogais na string e: %d\n", total);

    return 0;
}