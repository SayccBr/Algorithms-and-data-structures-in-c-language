#include <stdio.h>

int SomaSerie(int i, int j, int k) {
    if (i > j) {
        return 0;
    } else {
        return i + SomaSerie(i + k, j, k);
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

    int resultado = SomaSerie(i, j, k);

    printf("A soma da serie de valores no intervalo [%d, %d] com incremento %d e: %d\n", i, j, k, resultado);

    return 0;
}