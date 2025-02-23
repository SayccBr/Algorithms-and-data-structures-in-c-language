#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    char endereco[200];
} Dado;

int main() {
    Dado pessoa;

    printf("Nome:\n");
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);

    printf("Idade:\n");
    scanf("%d", &pessoa.idade);

    getchar();

    printf("Endereco:\n");
    fgets(pessoa.endereco, sizeof(pessoa.endereco), stdin);

    return 0;
}