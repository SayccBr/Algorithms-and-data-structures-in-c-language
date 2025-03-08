#include<stdio.h>
#include<stdlib.h>

typedef struct no No;

struct no {
    char valor;
    No *prox;
};

typedef struct lista {
    No *inicio;
    No *fim;
    int qtd;
}Lista;

Lista* criarLista() {
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    l->qtd = 0;
    l->fim = NULL;

    return l;
}

int size(Lista *l) {
    int qtd = 0;
    No *aux = l->inicio;

    while(aux != NULL) {
        ++qtd;
        aux = aux->prox;
    }

    return qtd;
}

int isEmpty(Lista *l) {
    return (l->inicio == NULL);
}

char consultar(Lista *l, int pos) {

    if(pos < size(l)) {
        No *aux = l->inicio;

        for(int i = 0; i < pos; ++i) {
            aux = aux->prox;
        }

        return aux->valor;
    }
    else
        return NULL;
}

void inserirPosicao(Lista *l, char valor, int pos) {
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if(isEmpty(l) && pos == 0) {
        l->inicio = novo;
    }
    else if(pos == 0) {
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    else if(pos <= size(l)) {

        No *aux = l->inicio;

        for(int i = 0; i < pos-1; ++i) {
            aux = aux->prox;
        }

        novo->prox = aux->prox;
        aux->prox = novo;
    }
    else
        return NULL;
}

void inserir(Lista *l, char valor) {
    inserirPosicao(l, valor, size(l));
}

void mostrarLista(Lista *l) {
    No *aux = l->inicio;

    if(isEmpty(l))
        printf("Lista vazia\n");
    else {
        for(int i = 0; aux != NULL; ++i, aux = aux->prox) {
            printf("Lista pos %d = %c\n", i, aux->valor);
        }
    }
}

int main() {

    Lista *l = criarLista();
    mostrarLista(l);


    inserirPosicao(l, 'a', 0);
    inserirPosicao(l, '2', 1);
    inserirPosicao(l, '3', 0);
    inserirPosicao(l, 't', 1);
    inserir(l, 'v');



    printf("\n\nValores inseridos\n\n");

    mostrarLista(l);


    return 0;
}