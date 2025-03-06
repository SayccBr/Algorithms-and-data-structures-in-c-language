#include <stdio.h>
#include <ctype.h>

int main() {
    char nomeArquivo[50];
    printf("Digite o nome do arquivo texto: ");
    scanf("%s", nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int numVogais = 0;
    int numConsoantes = 0;
    char caractere;

    while ((caractere = fgetc(arquivo)) != EOF) {
        caractere = tolower(caractere);

        if (caractere >= 'a' && caractere <= 'z') {
            if (caractere == 'a' || caractere == 'e' || caractere == 'i' ||
                caractere == 'o' || caractere == 'u') {
                numVogais++;
            } else {
                numConsoantes++;
            }
        }
    }

    fclose(arquivo);

    printf("O arquivo \"%s\" possui %d vogais e %d consoantes.\n",
           nomeArquivo, numVogais, numConsoantes);

    return 0;
}
