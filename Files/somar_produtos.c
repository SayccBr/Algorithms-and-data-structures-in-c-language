#include <stdio.h>

int main() {
    FILE *arquivo = fopen("produtos.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char nome[50];
    float preco, total = 0;

    // Formato esperado em "produtos.txt": "<nome> <preco>"
    while (fscanf(arquivo, "%s %f", nome, &preco) == 2) {
        printf("Produto: %s, Preço: R$ %.2f\n", nome, preco);
        total += preco;
    }

    fclose(arquivo);

    printf("\nTotal da compra: R$ %.2f\n", total);

    return 0;
}
