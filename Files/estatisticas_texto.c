#include <stdio.h>
#include <ctype.h>

int main() {
    char nomeArquivo[50];
    FILE *arquivo;
    char caractere;
    int numCaracteres = 0, numLinhas = 0, numPalavras = 0;
    int contagemLetras[26] = {0}; // Uma posição para cada letra do alfabeto

    printf("Digite o nome do arquivo texto: ");
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int dentroDePalavra = 0;

    while ((caractere = fgetc(arquivo)) != EOF) {
        numCaracteres++;

        if (caractere == '\n') {
            numLinhas++;
        }

        if (isspace(caractere)) {
            dentroDePalavra = 0;
        } else if (!dentroDePalavra) {
            dentroDePalavra = 1;
            numPalavras++;
        }

        if (isalpha(caractere)) {
            caractere = tolower(caractere);
            contagemLetras[caractere - 'a']++;
        }
    }

    fclose(arquivo);

    printf("Número de caracteres: %d\n", numCaracteres);
    printf("Número de linhas: %d\n", numLinhas);
    printf("Número de palavras: %d\n", numPalavras);

    for (int i = 0; i < 26; i++) {
        printf("A letra '%c' aparece %d vezes no arquivo.\n", 'a' + i, contagemLetras[i]);
    }

    return 0;
}
