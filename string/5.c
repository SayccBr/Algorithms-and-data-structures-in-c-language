#include <stdio.h>
#include <string.h>

int main() {
    char nome[100]; 

    printf("Digite um nome: ");
    scanf("%s", nome);

    int comprimento = strlen(nome);

    printf("O nome '%s' tem %d letras.\n", nome, comprimento);

    return 0;
}