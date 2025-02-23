#include <stdio.h>

int main() {
    char string[100];

    printf("Digite uma string: ");
    fgets(string, 100, stdin);

    printf("A string digitada foi: %s\n", string);

    return 0;
}