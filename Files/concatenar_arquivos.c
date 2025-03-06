#include <stdio.h>

int main() {
    char nomeArquivo1[50];
    char nomeArquivo2[50];
    char nomeArquivo3[50];
    char caractere;

    printf("Digite o nome do primeiro arquivo texto: ");
    scanf("%s", nomeArquivo1);

    printf("Digite o nome do segundo arquivo texto: ");
    scanf("%s", nomeArquivo2);

    printf("Digite o nome do terceiro arquivo texto de saída: ");
    scanf("%s", nomeArquivo3);

    FILE *arquivo1 = fopen(nomeArquivo1, "r");
    FILE *arquivo2 = fopen(nomeArquivo2, "r");
    FILE *arquivo3 = fopen(nomeArquivo3, "w");

    if (arquivo1 == NULL || arquivo2 == NULL || arquivo3 == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    // Copia conteúdo do primeiro arquivo
    while ((caractere = fgetc(arquivo1)) != EOF) {
        fputc(caractere, arquivo3);
    }

    // Copia conteúdo do segundo arquivo
    while ((caractere = fgetc(arquivo2)) != EOF) {
        fputc(caractere, arquivo3);
    }

    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);

    printf("Arquivo de saída criado com sucesso.\n");

    return 0;
}
