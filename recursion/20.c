#include <stdio.h>

double fatorialExponencial(int N) {
    if (N <= 0) {
        return 1.0;
    } else {
        return N * fatorialExponencial(N - 1);
    }
}

int main() {
    int N;

    printf("Numero inteiro positivo N: ");
    scanf("%d", &N);

    if (N < 0) {
        printf("N deve ser um numero inteiro positivo ou zero.\n");
        return 1; // Saída de erro
    }

    double resultado = fatorialExponencial(N);

    printf("O fatorial exponencial de %d e: %.0lf\n", N, resultado);

    return 0;
}