#include <stdio.h>
#include <ctype.h>

int main() {
    char nomeArquivoEntrada[50];
    char nomeArquivoSaida[50];
    char caractere;

    printf("Digite o nome do arquivo texto de entrada: ");
    scanf("%s", nomeArquivoEntrada);

    printf("Digite o nome do arquivo texto de saída: ");
    scanf("%s", nomeArquivoSaida);

    FILE *arquivoEntrada = fopen(nomeArquivoEntrada, "r");
    FILE *arquivoSaida = fopen(nomeArquivoSaida, "w");

    if (arquivoEntrada == NULL || arquivoSaida == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    while ((caractere = fgetc(arquivoEntrada)) != EOF) {
        // Converte para maiúscula antes de escrever
        fputc(toupper(caractere), arquivoSaida);
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    printf("Arquivo de saída criado com sucesso.\n");

    return 0;
}
