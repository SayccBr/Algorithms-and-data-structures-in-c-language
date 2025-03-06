#include <stdio.h>

int main() {
    char nomeArquivo[50];
    printf("Digite o nome do arquivo texto: ");
    scanf("%s", nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int numLinhas = 0;
    char caractere;

    while ((caractere = fgetc(arquivo)) != EOF) {
        if (caractere == '\n') {
            numLinhas++;
        }
    }

    // Se o arquivo tiver conteúdo e não terminar com '\n', conta a última linha
    if (numLinhas > 0 && caractere != '\n') {
        numLinhas++;
    }

    fclose(arquivo);

    printf("O arquivo \"%s\" possui %d linha(s).\n", nomeArquivo, numLinhas);

    return 0;
}
