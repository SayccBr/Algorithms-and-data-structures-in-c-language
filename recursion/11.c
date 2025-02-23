#include <stdio.h>

void exibirArray(int array[], int tamanho, int indice) {
    if (indice == tamanho) {
        return;
    }
    
    printf("%d ", array[indice]);
    
    exibirArray(array, tamanho, indice + 1);
}

int main() {
    int tamanho;
    
    printf("Tamanho do array: ");
    scanf("%d", &tamanho);
    
    if (tamanho <= 0) {
        printf("Tamanho do array deve ser maior que zero.\n");
        return 1;
    }
    
    int array[tamanho];
    
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("Elementos do array:\n");
    exibirArray(array, tamanho, 0);
    printf("\n");
    
    return 0;
}