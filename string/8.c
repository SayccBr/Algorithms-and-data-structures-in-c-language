#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int count = 0;

    printf("Digite uma string contendo 1's: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '1') {
            count++;
        }
    }

    printf("O número de '1's na string é: %d\n", count);

    return 0;
}