#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char letra;
    struct no *filhos[26];
    int palavra;
} No;

No* criarNo(char data) {
    No* novoNo = (No*)malloc(sizeof(No));

    for (int i = 0; i < 26; i++) {
        novoNo->filhos[i] = NULL;
    }

    novoNo->palavra = 0;
    novoNo->letra = data;

    return novoNo;
}

// libear memória
void liberarMemoriaDoNo(No* no) {
    for (int i = 0; i < 26; i++) {
        if (no->filhos[i] != NULL)
            liberarMemoriaDoNo(no->filhos[i]);
    }

    free(no);
}

// Função para inserir um nome na tríe
No* insert(No* raiz, char* palavra) {
    No* auxiliar = raiz;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int posicaoNoAlfabeto = (int)palavra[i] - 'a';

        if (auxiliar->filhos[posicaoNoAlfabeto] == NULL) {
            auxiliar->filhos[posicaoNoAlfabeto] = criarNo(palavra[i]);
        }
        auxiliar = auxiliar->filhos[posicaoNoAlfabeto];
    }

    auxiliar->palavra = 1;

    return raiz;
}

// Função para buscar um nome
int buscar(No* raiz, char* palavra) {
    No* auxiliar = raiz;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int posicaoNoAlfabeto = (int)palavra[i] - 'a';

        if (auxiliar->filhos[posicaoNoAlfabeto] == NULL) {
            return 0;
        }
        auxiliar = auxiliar->filhos[posicaoNoAlfabeto];
    }

    return auxiliar != NULL && auxiliar->palavra == 1;
}

// Função para exibir todos os nomes armazenados na tríe
void exibirTries(No* no, char* prefixo, int profundidade) {
    if (no == NULL) return;

    if (no->palavra) {
        prefixo[profundidade] = '\0';
        printf("%s\n", prefixo);
    }

    for (int i = 0; i < 26; i++) {
        if (no->filhos[i] != NULL) {
            prefixo[profundidade] = no->filhos[i]->letra;
            exibirTries(no->filhos[i], prefixo, profundidade + 1);
        }
    }
}

int main() {
    No* raiz = criarNo('\0'); // Raiz da tríe
    char nome[50];

    // Inserir nomes de estudantes
    raiz = insert(raiz, "ana");
    raiz = insert(raiz, "bruno");
    raiz = insert(raiz, "carla");
    raiz = insert(raiz, "diego");

    // Exibir todos os nomes armazenados
    char prefixo[50];
    printf("Nomes armazenados na tríe:\n");
    exibirTries(raiz, prefixo, 0);

    liberarMemoriaDoNo(raiz);

    return 0;
}
