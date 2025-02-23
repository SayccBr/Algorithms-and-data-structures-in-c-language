#include <stdio.h>

void imprimirDecrescente(int n) {
    if (n < 0) {
        return;
    } 

    printf("%d ", n);
    
    if (n > 0) {
        imprimirDecrescente(n - 1);
    }
}

int main() {
    int N;
    
    printf("N: ");
    scanf("%d", &N);
    
    printf("Numeros de 0 a %d em ordem decrescente:\n", N);
    imprimirDecrescente(N);
    printf("\n");
    
    return 0;
}