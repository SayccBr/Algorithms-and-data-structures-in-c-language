#include <stdio.h>

int main() {
    float x, y;
    float *p;
    float **pd;
    printf("Digite dois valores do tipo float (x e y): ");
    scanf("%f %f", &x, &y);
    p = &x;
    pd = &p;
    **pd *= 4;
    (*pd)++;
    **pd *= 4;
    printf("Valores alterados:\n");
    printf("x = %.2f\n", x);
    printf("y = %.2f\n", y);
    return 0;
}
