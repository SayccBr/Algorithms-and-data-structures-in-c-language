#include <stdio.h>

unsigned long long calcularFatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * calcularFatorial(n - 1);
    }
}

unsigned long long superfatorial(int N) {
    if (N <= 0) {
        return 1;
    } else {
 
        unsigned long long resultado = 1;
        for (int i = 1; i <= N; i++) {
            resultado *= calcularFatorial(i);
        }
        return resultado;
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

    unsigned long long resultado = superfatorial(N);

    printf("O superfatorial de %d e: %llu\n", N, resultado);

    return 0;
}