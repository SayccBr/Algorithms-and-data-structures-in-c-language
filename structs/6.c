#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char nome[50];
    int codigoDisciplina;
    float nota1;
    float nota2;
} Aluno;

float calcularMedia(float nota1, float nota2) {
    return (nota1 + 2.0 * nota2) / 3.0;
}

int main() {
    Aluno alunos[10];
    int numAlunos;

    printf("Digite o numero de alunos (ate 10): ");
    scanf("%d", &numAlunos);

    if (numAlunos > 10) {
        printf("Numero de alunos excedeu o limite.\n");
        return 1;
    }

    for (int i = 0; i < numAlunos; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Nome: ");

        getchar(); 

        fgets(alunos[i].nome, 50, stdin); 
        printf("Codigo da Disciplina: ");
        scanf("%d", &alunos[i].codigoDisciplina);
        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);
        printf("\n");
    }

    system("cls");

    printf("Listagem final dos alunos:\n");
    for (int i = 0; i < numAlunos; i++) {
        float media = calcularMedia(alunos[i].nota1, alunos[i].nota2);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Codigo da Disciplina: %d\n", alunos[i].codigoDisciplina);
        printf("Media final: %.2f\n", media);
        printf("\n");
    }

    return 0;
}