#include <stdio.h>

void imprimirNumerosParesDecrescente(int n) {
    if (n < 0) {
        return; 
    }
    if (n % 2 == 0) {
        printf("%d ", n); 
    }
    if (n > 0) {
        imprimirNumerosParesDecrescente(n - 1);
    }
}

int main() {
    int N;

    printf("par N: ");
    scanf("%d", &N);

    if (N % 2 == 0 && N >= 0) {
        printf("Numeros pares de 0 a %d em ordem decrescente:\n", N);
        imprimirNumerosParesDecrescente(N);
        printf("\n");
    } else {
        printf("Nao e um numero inteiro positivo par.\n");
    }

    return 0;
}