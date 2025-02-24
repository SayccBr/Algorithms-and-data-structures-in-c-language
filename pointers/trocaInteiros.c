#include <stdio.h>

void trocaInteiros(int *x, int *y) {
int temp = *x;
*x = *y;
*y = temp;
}

int main() {
int a = 5;
int b = 10;

printf("Valores originais: a = %d, b = %d\n", a, b);

trocaInteiros(&a, &b);

printf("Valores trocados: a = %d, b = %d\n", a, b);

return 0;
}