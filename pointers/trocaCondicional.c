#include <stdio.h>

void a(int *x, int *y) {
    if (*y > *x) {
        int a = *x;
        *x = *y;
        *y = a;
    }
}

int main() {
    int maior, menor;
    scanf("%d", &maior);
    scanf("%d", &menor);
    int *p = &maior, *p2 = &menor;
    a(p, p2);
    printf("Maior valor: %d. Menor valor: %d.", maior, menor);
    return 0;
}
