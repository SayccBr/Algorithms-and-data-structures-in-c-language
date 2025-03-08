#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila {
    int inicio, fim, max, tam;
    int *dados;
} Fila;

Fila* criarFila(int max) {
    Fila *f = malloc(sizeof(Fila));

    f->inicio = 0;
    f->fim = -1;
    f->tam = 0;
    f->max = max;
    f->dados = malloc(max * sizeof(int));

    return f;
}

bool estaVazia(Fila *f) {
    if(f->tam == 0)
        return true;
    else
        return false;
}

bool estaCheia(Fila *f) {
    if(f->max == f->tam){
        return true;
    }else{
        return false;
    }
}

bool inserir(Fila *f, int dado) {
    if(estaCheia(f))
        return false;

    f->fim = (f->fim+1) % f->max;
    f->dados[f->fim] = dado;
    f->tam++;

    return true;
}

int remover(Fila *f) {
    if(estaVazia(f) == false){
        int aux = f->dados[f->inicio];
        f->inicio = (f->inicio+1) % f->max;
        f->tam--;
        return aux;
    }
}

void imprimeFila(Fila *f){
    while(!estaVazia(f)){
        printf("%d\n", remover(f));
    }
}

int main() {

    Fila *f = criarFila(8);

    inserir(f, 10);
    inserir(f, 20);
    inserir(f, 50);
    inserir(f, 80);
    inserir(f, 90);
    inserir(f, 200);
    inserir(f, 40);
    inserir(f, 400);
    remover(f);
    remover(f);
    remover(f);
    inserir(f, 500);

    printf("Inicio: %d\n", f->inicio);
    printf("Fim: %d\n", f->fim);
    printf("Max: %d\n", f->max);
    printf("Tam: %d\n", f->tam);
    printf("Esta vazia: %s\n", estaVazia(f) ? "sim" : "nao");
    printf("Esta cheia: %s\n", estaCheia(f) ? "sim" : "nao");


    printf("\nFila:\n");

    imprimeFila(f);

    return 0;
}