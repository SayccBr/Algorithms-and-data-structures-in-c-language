#include <stdio.h>
#include <stdlib.h>

int main() {
    int quantidade_estudantes;
    printf("Digite a quantidade de estudantes na turma: ");
    scanf("%d", &quantidade_estudantes);
    if (quantidade_estudantes <= 0) {
        printf("Quantidade de estudantes invalida. Deve ser maior que 0.\n");
        return 1;
    }
    float *notas = (float *)malloc(quantidade_estudantes * sizeof(float));
    if (notas == NULL) {
        printf("Erro ao alocar memoria. Encerrando o programa.\n");
        return 1;
    }
    printf("Digite as notas dos estudantes:\n");
    for (int i = 0; i < quantidade_estudantes; i++) {
        scanf("%f", &notas[i]);
    }
    float soma = 0.0;
    for (int i = 0; i < quantidade_estudantes; i++) {
        soma += notas[i];
    }
    float media = soma / quantidade_estudantes;
    printf("A media aritmetica das notas e: %.2f\n", media);
    free(notas);
    return 0;
}
