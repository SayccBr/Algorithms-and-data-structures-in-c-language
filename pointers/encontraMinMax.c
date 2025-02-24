#include <stdio.h>

void encontraMinMax(int *vetor, int tamanho, int *min, int *max) {
if (tamanho <= 0) {
return;
}

*min = *max = vetor[0];

for (int i = 1; i < tamanho; i++) {
if (vetor[i] < *min) {
*min = vetor[i];
}
if (vetor[i] > *max) {
*max = vetor[i];
}
}
}

int main() {
int vetor[] = {10, 5, 3, 8, 15, 2};
int tamanho = sizeof(vetor) / sizeof(vetor[0]);
int minimo, maximo;

encontraMinMax(vetor, tamanho, &minimo, &maximo);

printf("Menor valor: %d\n", minimo);
printf("Maior valor: %d\n", maximo);

return 0;
}