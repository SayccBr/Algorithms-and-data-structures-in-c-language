#include <stdio.h>

double hiperfatorial(int N) {
    if (N == 1) {
        return 1.0;
    } else {
        double resultado = 1.0;
        for (int i = 1; i <= N; i++) {
            resultado *= pow(i, i); // Multi por i^i
        }
        return resultado;
    }
}

int main() {
    int N;

    printf("Numero inteiro positivo N: ");
    scanf("%d", &N);

    if (N < 1) {
        printf("N deve ser um numero inteiro positivo.\n");
        return 1;
    }

    double resultado = hiperfatorial(N);

    printf("O hiperfatorial de %d e: %.0lf\n", N, resultado);

    return 0;
}