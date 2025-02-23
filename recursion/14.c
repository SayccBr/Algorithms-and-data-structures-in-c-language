#include <stdio.h>

void ImprimeSerie(int i, int j, int k) {
    if (i > j) {
        return;
    } else {
        printf("%d ", i); 
        ImprimeSerie(i + k, j, k); 
    }
}

int main() {
    int i, j, k;

    printf("Digite o valor inicial (i): ");
    scanf("%d", &i);

    printf("Digite o valor final (j): ");
    scanf("%d", &j);

    printf("Digite o incremento (k): ");
    scanf("%d", &k);

    printf("A serie de valores no intervalo [%d, %d] com incremento %d e:\n", i, j, k);
    ImprimeSerie(i, j, k);

    return 0;
}