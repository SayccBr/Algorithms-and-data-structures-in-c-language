#include <stdio.h>
#include <stdlib.h>

//Raiz é sempre preta
//Para cada nó, todos os caminhos desses nó para os nós folhas descentes contém o mesmo número de nós pretos
//Se um nó é vermenlho então seu filho é preto
//Todo nó folha (NULL) é preto

//AVL é mais rápida para busca e mais lenta para inserção e remoção
//AVL é mais balanceada


//rubro-negra caída para esquerda
//Se um nó é vermelho então ele é o filho esquerdo
//NÓ vermelho sempre é menor de um nó contendo dois valores e três sub-árvores, ar 2-3

#define RED 1
#define BLACK 0

struct no {
    int key;
    int cor;
    struct no* esq;
    struct no* dir;
};

// Função para criar um novo nó
struct no* criarNo(int key) {
    struct no* novo = malloc(sizeof(struct no));
    if (novo != NULL) {
        novo->key = key;
        novo->cor = RED;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

// Função para acessar a cor do nó
int cor(struct no* abc) {
    if (abc == NULL)
        return BLACK;
    else
        return abc->cor;
}

// Inverte a cor do pai e de seus filhos
void trocaCor(struct no* abc) {
    abc->cor = !abc->cor;
    if (abc->esq != NULL)
        abc->esq->cor = !abc->esq->cor;
    if (abc->dir != NULL)
        abc->dir->cor = !abc->dir->cor;
}

// Rotação à esquerda
struct no* rotaesq(struct no* a) {
    struct no* b = a->dir;
    a->dir = b->esq;
    b->esq = a;
    b->cor = a->cor;
    a->cor = RED;
    return b;
}

// Rotação à direita
struct no* rotadir(struct no* a) {
    struct no* b = a->esq;
    a->esq = b->dir;
    b->dir = a;
    b->cor = a->cor;
    a->cor = RED;
    return b;
}

// Função para balancear a árvore
struct no* balancear(struct no* H) {
    // Nó vermelho é sempre filho à esquerda
    if (cor(H->dir) == RED)
        H = rotaesq(H);

    // Filho da esquerda e neto da esquerda são vermelhos
    if (cor(H->esq) == RED && cor(H->esq->esq) == RED)
        H = rotadir(H);

    // 2 filhos vermelhos: troca cor!
    if (cor(H->esq) == RED && cor(H->dir) == RED)
        trocaCor(H);

    return H;
}

// Função para inserir um novo nó na árvore
struct no* inserir(struct no* raiz, int key, int *resp) {
    if (raiz == NULL)
        return criarNo(key);

    if (key < raiz->key)
        raiz->esq = inserir(raiz->esq, key, resp);
    else if (key > raiz->key)
        raiz->dir = inserir(raiz->dir, key, resp);
    else
        *resp = 0; // Valor duplicado

    if (cor(raiz->dir) == RED && cor(raiz->esq) == BLACK)
        raiz = rotaesq(raiz);

    if (cor(raiz->esq) == RED && cor(raiz->esq->esq) == RED)
        raiz = rotadir(raiz);

    if (cor(raiz->esq) == RED && cor(raiz->dir) == RED)
        trocaCor(raiz);

    return balancear(raiz);
}

// Função para percurso em ordem
void percursoEmOrdem(struct no* raiz) {
    if (raiz != NULL) {
        percursoEmOrdem(raiz->esq);
        printf("%d (%s) ", raiz->key, (raiz->cor == RED) ? "Vermelho" : "Preto");
        percursoEmOrdem(raiz->dir);
    }
}

// Função para percurso pré-ordem
void percursoPreOrdem(struct no* raiz) {
    if (raiz != NULL) {
        printf("%d (%s) ", raiz->key, (raiz->cor == RED) ? "Vermelho" : "Preto");
        percursoPreOrdem(raiz->esq);
        percursoPreOrdem(raiz->dir);
    }
}

// Função para percurso pós-ordem
void percursoPosOrdem(struct no* raiz) {
    if (raiz != NULL) {
        percursoPosOrdem(raiz->esq);
        percursoPosOrdem(raiz->dir);
        printf("%d (%s) ", raiz->key, (raiz->cor == RED) ? "Vermelho" : "Preto");
    }
}

// Função para mostrar valores pares de nós pretos
void mostrarParesPretos(struct no* raiz) {
    if (raiz != NULL) {
        mostrarParesPretos(raiz->esq);
        if (raiz->cor == BLACK && raiz->key % 2 == 0)
            printf("%d ", raiz->key);
        mostrarParesPretos(raiz->dir);
    }
}

// Função para contar nós vermelhos ímpares
int contarVermelhosImpares(struct no* raiz) {
    if (raiz == NULL)
        return 0;

    int contador = 0;

    if (raiz->cor == RED && raiz->key % 2 != 0)
        contador = 1;

    contador += contarVermelhosImpares(raiz->esq);
    contador += contarVermelhosImpares(raiz->dir);

    return contador;
}

int main() {
    struct no* raiz = NULL;
    int resp;

    raiz = inserir(raiz, 10, &resp);
    raiz = inserir(raiz, 20, &resp);
    raiz = inserir(raiz, 5, &resp);
    raiz = inserir(raiz, 15, &resp);
    raiz = inserir(raiz, 25, &resp);

    printf("Percurso em-ordem:\n");
    percursoEmOrdem(raiz);
    printf("\n");

    printf("Percurso pré-ordem:\n");
    percursoPreOrdem(raiz);
    printf("\n");

    printf("Percurso pós-ordem:\n");
    percursoPosOrdem(raiz);
    printf("\n");

    printf("Valores pares de nós pretos:\n");
    mostrarParesPretos(raiz);
    printf("\n");

    int contagem = contarVermelhosImpares(raiz);
    printf("Quantidade de nós vermelhos ímpares: %d\n", contagem);

    return 0;
}
