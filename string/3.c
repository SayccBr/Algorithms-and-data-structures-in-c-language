#include <stdio.h>
#include <string.h>

int main() {
    char nome[100]; 

    printf("Digite um nome: ");
    fgets(nome, 100, stdin);

    nome[strcspn(nome, "\n")] = '\0';

    if (nome[0] == 'a' || nome[0] == 'A') {
        printf("O nome digitado e: %s\n", nome); 
    } else {
        printf("A primeira letra do nome não e 'a' (maiuscula ou minuscula).\n");
    }

    return 0;
}