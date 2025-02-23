#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    char numero_matricula[20];
    char curso[100];
} aluno;

int main() {
    aluno alunos[5];

    for(int i = 0; i<5; i++){
    printf("Nome:\n");
    fgets(alunos[i].nome, 50, stdin);

    printf("numero da matricula:\n");
    fgets(alunos[i].numero_matricula, 20, stdin);

    printf("curso:\n");
    fgets(alunos[i].curso, 100, stdin);
    
    system("cls");
    }

    system("cls");
    for(int i = 0; i < 5; i++){
        printf("%s", alunos[i].nome);
        printf("%s", alunos[i].numero_matricula);
        printf("%s", alunos[i].curso);
        printf("\n");
    }

    return 0;
}