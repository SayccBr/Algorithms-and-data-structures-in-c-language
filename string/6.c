#include <stdio.h>
#include <string.h>

int main() {
    char nome[100];
    char sexo;
    int idade;

    printf("Digite o nome: ");
    fgets(nome, 100, stdin);
    
    printf("Digite o sexo (M/F): ");
    scanf(" %c", &sexo); // Espaço antes de %c para consumir a quebra de linha anterior
    
    printf("Digite a idade: ");
    scanf("%d", &idade);

    nome[strcspn(nome, "\n")] = '\0';

    if (sexo == 'F' || sexo == 'f') {
        if (idade < 25) {
            printf("%s ACEITA\n", nome);
        } else {
            printf("%s NAO ACEITA\n", nome);
        }
    } else {
        printf("%s NAO ACEITA\n", nome);
    }

    return 0;
}