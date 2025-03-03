#include <stdio.h>
#include <stdlib.h>

void lerElementos(int *vetor, int n) {
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Tamanho inválido\n");
        return 1;
    }

    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na alocação de memória\n");
        return 1;
    }

    lerElementos(vetor, n);

    printf("Elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
    return 0;
}
