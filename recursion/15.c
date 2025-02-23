#include <stdio.h>

double calcularSerie(int n) {
    if (n == 0) {
        return 0.0;
    } else {
        double termo = (double)(2 * n) / (n * n);
        return termo + calcularSerie(n - 1);
    }
}

int main() {
    int n;

    printf("Digite um valor inteiro positivo n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O valor de n deve ser maior que zero.\n");
        return 1; // Saída de erro
    }

    double resultado = calcularSerie(n);

    printf("O valor da serie para n = %d e: %.6lf\n", n, resultado);

    return 0;
}