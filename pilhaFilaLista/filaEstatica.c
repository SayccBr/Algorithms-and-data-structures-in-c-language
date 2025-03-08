#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila {
    int inicio, fim, max;
    int *dados;
} Fila;

Fila* criarFila(int max) {
    Fila *f = malloc(sizeof(Fila));

    f->inicio = 0;
    f->fim = -1;
    f->max = max;
    f->dados = malloc(max * sizeof(int));

    return f;
}

bool estaVazia(Fila *f) {
    if(f->fim < f->inicio)
        return true;
    else
        return false;
}

bool estaCheia(Fila *f) {
    if(f->fim == f->max - 1){
        return true;
    }else{
        return false;
    }
}

bool inserir(Fila *f, int dado) {
    if(estaCheia(f))
        return false;

    f->fim = f->fim+1;
    f->dados[f->fim] = dado;

    return true;
}

int remover(Fila *f) {
    if(estaVazia(f) == false){
        int aux = f->dados[f->inicio];
        f->inicio = f->inicio + 1;
        return aux;
    }
}

void imprimeFila(Fila *f){
    while(!estaVazia(f)){
         printf("%d\n", remover(f));
    }
}

int main() {

    Fila *f = criarFila(5);

    inserir(f, 8);
    inserir(f, 10);
    remover(f);
    inserir(f, 20);
    remover(f);
    inserir(f, 30);
    inserir(f, 40);
    inserir(f, 50);
    inserir(f, 60);

    imprimeFila(f);

    return 0;
}