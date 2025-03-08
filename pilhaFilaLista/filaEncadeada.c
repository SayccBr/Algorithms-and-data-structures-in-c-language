#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct no No;

struct no {
    int valor;
    No *prox;
};

typedef struct fila {
    No *inicio;
    No *fim;
}Fila;

Fila* criarFila() {
    Fila *f = malloc(sizeof(Fila));

    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

bool estaVazia(Fila *f) {
    if(f->inicio == NULL && f->fim == NULL)
        return true;
    else
        return false;
}

bool inserir(Fila *f, int dado) {

    No *novoNo = (No*)malloc(sizeof(No));

    novoNo->valor = dado;
    novoNo->prox = NULL;

    if(estaVazia(f))
        f->inicio = novoNo;
    else
        f->fim->prox = novoNo;

    f->fim = novoNo;

    return true;
}

int remover(Fila *f) {
    if(estaVazia(f)) {
        printf("Fila Vazia\n");
        return -1; // Retorne um valor que indique que a fila est� vazia
    }

    int valorAux = f->inicio->valor;

    No *noAux = f->inicio;
    f->inicio = f->inicio->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(noAux);

    return valorAux;
}

void imprimeFila(Fila *f){
    while(!estaVazia(f)){
         printf("%d\n", remover(f));
    }
}

int main() {

    Fila *f = criarFila();

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

    printf("Inicio: %d\n", f->inicio->valor);
    printf("Fim: %d\n", f->fim->valor);
    printf("Esta vazia: %s\n", estaVazia(f) ? "sim" : "nao");


    printf("\nFila:\n");

    imprimeFila(f);

    printf("Esta vazia: %s\n", estaVazia(f) ? "sim" : "nao");

    return 0;
}