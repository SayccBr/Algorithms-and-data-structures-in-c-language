#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Digite uma string: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '0') {
            str[i] = '1';
        }
    }

    printf("A string com '0's substituídos por '1's é: %s\n", str);

    return 0;
}