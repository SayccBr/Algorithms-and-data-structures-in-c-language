#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numeros = (int *)malloc(5 * sizeof(int));
    if (numeros == NULL) {
        printf("Erro ao alocar memoria. Encerrando o programa.\n");
        return 1;
    }
    printf("Digite 5 numeros inteiros:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &numeros[i]);
    }
    printf("Os numeros digitados sao: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    free(numeros);
    return 0;
}
