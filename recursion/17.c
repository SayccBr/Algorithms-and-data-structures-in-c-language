#include <stdio.h>

int calcularFatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * calcularFatorial(n - 1);
    }
}

int fatorialQuadruplo(int N) {
    if (N <= 0) {
        return 1; 
    } else {
 
        int fatorial2N = calcularFatorial(2 * N);
        int fatorialN = calcularFatorial(N);
        return fatorial2N / fatorialN;
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

    int resultado = fatorialQuadruplo(N);

    printf("O fatorial quadruplo de %d e: %d\n", N, resultado);

    return 0;
}