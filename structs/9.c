#include <stdio.h>
#include <math.h>

typedef struct {
    float real;
    float imag;
} Complexo;

int main() {
    Complexo z, w;

    printf("Digite a parte real e a parte imaginaria do numero complexo z:\n");
    scanf("%f %f", &z.real, &z.imag);

    printf("Digite a parte real e a parte imaginaria do numero complexo w:\n");
    scanf("%f %f", &w.real, &w.imag);

    Complexo soma;
    soma.real = z.real + w.real;
    soma.imag = z.imag + w.imag;
    printf("Soma: %.2f + %.2fi\n", soma.real, soma.imag);

    Complexo subtracao;
    subtracao.real = z.real - w.real;
    subtracao.imag = z.imag - w.imag;
    printf("Subtracao: %.2f + %.2fi\n", subtracao.real, subtracao.imag);

    Complexo produto;
    produto.real = z.real * w.real - z.imag * w.imag;
    produto.imag = z.real * w.imag + z.imag * w.real;
    printf("Produto: %.2f + %.2fi\n", produto.real, produto.imag);

    float moduloZ = sqrt(z.real * z.real + z.imag * z.imag);
    float moduloW = sqrt(w.real * w.real + w.imag * w.imag);
    printf("Modulo de z: %.2f\n", moduloZ);
    printf("Modulo de w: %.2f\n", moduloW);

    return 0;
}