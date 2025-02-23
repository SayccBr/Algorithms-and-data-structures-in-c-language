#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char endereco[100];
    char telefone[15];
} Pessoa;

int main() {
    int numPessoas = 5;
    Pessoa pessoas[numPessoas];

    for (int i = 0; i < numPessoas; i++) {
        printf("Dados da pessoa %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", pessoas[i].nome);
        printf("Endereco: ");
        scanf("%s", pessoas[i].endereco);
        printf("Telefone: ");
        scanf("%s", pessoas[i].telefone);
    }

    for (int i = 0; i < numPessoas - 1; i++) {
        for (int j = i + 1; j < numPessoas; j++) {
            if (strcmp(pessoas[i].nome, pessoas[j].nome) > 0) {
                Pessoa temp = pessoas[i];
                pessoas[i] = pessoas[j];
                pessoas[j] = temp;
            }
        }
    }

    printf("\nLista de pessoas em ordem alfabetica:\n");
    for (int i = 0; i < numPessoas; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Endereco: %s\n", pessoas[i].endereco);
        printf("Telefone: %s\n", pessoas[i].telefone);
        printf("\n");
    }

    return 0;
}