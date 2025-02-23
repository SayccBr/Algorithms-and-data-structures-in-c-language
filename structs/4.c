#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char numero_matricula[20];
    float nota1;
    float nota2;
    float nota3;
} aluno;

int main() {
    int maior = 0;
    float media_maior = 0;
    float media_menor = 10;
    char nome_maior[50], nome_menor[50];

    aluno alunos[5];

    for (int i = 0; i < 5; i++) {
        printf("Nome:\n");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        printf("Numero da matricula:\n");
        fgets(alunos[i].numero_matricula, sizeof(alunos[i].numero_matricula), stdin);

        printf("Nota da primeira prova:\n");
        scanf("%f", &alunos[i].nota1);

        if (alunos[i].nota1 > maior) {
            maior = alunos[i].nota1;
            strcpy(nome_maior, alunos[i].nome);
        }

        printf("Nota da segunda prova:\n");
        scanf("%f", &alunos[i].nota2);

        printf("Nota da terceira prova:\n");
        scanf("%f", &alunos[i].nota3);
        
        float media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;

        if (media > media_maior) {
            media_maior = media;
            strcpy(nome_maior, alunos[i].nome);
        }

        if (media < media_menor) {
            media_menor = media;
            strcpy(nome_menor, alunos[i].nome);
        }

        getchar();
        system("cls");
    }

    system("cls");

    for (int i = 0; i < 5; i++) {
        float media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
        printf("Aluno: %s", alunos[i].nome);
        printf("Media: %.2f\n", media);
        printf("Status: %s\n\n", media >= 6.0 ? "Aprovado" : "Reprovado");
    }

    printf("Aluno com maior nota na primeira prova: %s\n", nome_maior);
    printf("Aluno com maior media geral: %s\n", nome_maior);
    printf("Aluno com menor media geral: %s\n", nome_menor);

    return 0;
}