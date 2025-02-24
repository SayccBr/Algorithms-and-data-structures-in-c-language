#include <stdio.h>

int ordenaTresValores(int *a, int *b, int *c) {
int temp;

if (*a > *b) {
temp = *a;
*a = *b;
*b = temp;
}

if (*b > *c) {
temp = *b;
*b = *c;
*c = temp;
}

if (*a > *b) {
temp = *a;
*a = *b;
*b = temp;
}

if (*a == *b && *b == *c) {
return 1;
} else {
return 0;
}
}

int main() {
int valor1, valor2, valor3;

printf("Digite o primeiro valor inteiro: ");
scanf("%d", &valor1);

printf("Digite o segundo valor inteiro: ");
scanf("%d", &valor2);

printf("Digite o terceiro valor inteiro: ");
scanf("%d", &valor3);

int resultado = ordenaTresValores(&valor1, &valor2, &valor3);

printf("Valores ordenados: %d, %d, %d\n", valor1, valor2, valor3);

if (resultado == 1) {
printf("Todos os valores sao iguais.\n");
} else {
printf("Ha valores diferentes.\n");
}

return 0;
}