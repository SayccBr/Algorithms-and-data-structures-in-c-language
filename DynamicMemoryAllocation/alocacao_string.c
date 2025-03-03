#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *alocaString(int n) {
    char *str = (char *)malloc(n * sizeof(char));
    if (str == NULL) {
        printf("Erro ao alocar memória. Encerrando o programa.\n");
        exit(1);
    }
    return str;
}

int main() {
    int tamanho;
    printf("Digite o tamanho da string: ");
    scanf("%d", &tamanho);
    if (tamanho <= 0) {
        printf("Tamanho da string inválido. Deve ser maior que 0.\n");
        return 1;
    }
    char *string = alocaString(tamanho);
    printf("Digite o conteúdo da string: ");
    scanf(" %s", string);
    printf("String original: %s\n", string);
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || 
            string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U') {
            string[i] = ' ';
        }
    }
    printf("String sem vogais: %s\n", string);
    free(string);
    return 0;
}
