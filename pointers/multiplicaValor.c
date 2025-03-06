#include <stdio.h>

void troca(int *x, int *y) {
    int a;
    a = *x;
    *x = *y;
    *y = a;
}

int main() {
    int a = 50, b = 100;
    int *p = &a, *y = &b;
    troca(p, y);
    printf("Valor a: %d.  Valor b: %d.", a, b);
    return 0;
}
