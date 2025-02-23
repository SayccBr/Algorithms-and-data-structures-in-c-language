#include <stdio.h>
#include <string.h>

int main() {
    char cadeia[1000];

    printf("Digite uma cadeia de caracteres em maiúsculas: ");
    fgets(cadeia, 1000, stdin);

    int comprimento = strlen(cadeia);

    for (int i = 0; i < comprimento; i++) {
        if (cadeia[i] >= 'A' && cadeia[i] <= 'Z') {
            cadeia[i] = cadeia[i] + 32;
        }
    }

    printf("A cadeia de caracteres convertida para minusculas e: %s", cadeia);

    return 0;
}