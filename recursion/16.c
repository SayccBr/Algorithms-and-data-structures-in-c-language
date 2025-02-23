#include <stdio.h>

int fatorialDuplo(int N) {
    if (N == 1) {
        return 1;
    } else {
        return N * fatorialDuplo(N - 2);
    }
}

int main() {
    int N;

    printf("Numero inteiro positivo impar: ");
    scanf("%d", &N);

    if (N <= 0 || N % 2 == 0) {
        printf("Deve ser um numero inteiro positivo impar.\n");
        return 1;
    }

    int resultado = fatorialDuplo(N);

    printf("O fatorial duplo de %d e: %d\n", N, resultado);

    return 0;
}