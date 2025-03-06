#include <stdio.h>

int ordenarValores(int *a, int *b, int *c) {
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
    int num1, num2, num3;
    printf("Digite três valores inteiros: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    int todosIguais = ordenarValores(&num1, &num2, &num3);
    printf("Valores ordenados: %d %d %d\n", num1, num2, num3);
    if (todosIguais) {
        printf("Todos os valores são iguais.\n");
    } else {
        printf("Há valores diferentes.\n");
    }
    return 0;
}
