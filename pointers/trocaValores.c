#include <stdio.h>

void trocaValores(int *a, int *b) {
if (*a > *b) {
int temp = *a;
*a = *b;
*b = temp;
}
}

int main() {
int valor1, valor2;

printf("Digite o primeiro valor inteiro: ");
scanf("%d", &valor1);

printf("Digite o segundo valor inteiro: ");
scanf("%d", &valor2);

printf("Valores originais: valor1 = %d, valor2 = %d\n", valor1, valor2);

trocaValores(&valor1, &valor2);

printf("Valores apos a troca: valor1 = %d, valor2 = %d\n", valor1, valor2);

return 0;
}