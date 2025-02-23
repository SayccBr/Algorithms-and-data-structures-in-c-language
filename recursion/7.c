#include <stdio.h>

void imprimir(int n) {
    if (n < 0) {
        return;
    }
    
    if (n > 0) {
        imprimir(n - 1);
    }
    
    printf("%d ", n); 
}

int main() {
    int N;
    
    printf("N: ");
    scanf("%d", &N);
    
    printf("Numeros de 0 a %d em ordem crescente:\n", N);
    imprimir(N);
    printf("\n");
    
    return 0;
}