#include <stdio.h>
#include <string.h>

int main() {
    char frase[1000];
    int espacosEmBranco = 0;

    printf("Digite uma frase: ");
    fgets(frase, 1000, stdin);

    int comprimento = strlen(frase);

    for (int i = 0; i < comprimento; i++) {
        if (frase[i] == ' ') {
            espacosEmBranco++;
        }
    }

    printf("A frase digitada tem %d caracteres em branco.\n", espacosEmBranco);

    return 0;
}