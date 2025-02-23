#include <stdio.h>

void imprimirParesCrescente(int n) {
    if (n < 0) {
        return;
    }
    
    if (n % 2 == 0) {
        imprimirParesCrescente(n - 2);
    } else if (n > 0) {
        imprimirParesCrescente(n - 1);
    }
    
    printf("%d ", n);
}

int main() {
    int N;
    
    printf("par N: ");
    scanf("%d", &N);
    
    if (N % 2 == 0 && N >= 0) {
        printf("Numeros pares de 0 a %d em ordem crescente:\n", N);
        imprimirParesCrescente(N);
        printf("\n");
    } else {
        printf("Nao e um numero inteiro positivo par.\n");
    }
    
    return 0;
}