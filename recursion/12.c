#include <stdio.h>

int encontrarMenorElemento(int array[], int tamanho) {
    if (tamanho == 1) {
        return array[0];
    }
    
    int menorRestante = encontrarMenorElemento(array, tamanho - 1);
    
    int menorAtual = array[tamanho - 1];
    
    if (menorRestante < menorAtual) {
        return menorRestante;
    } else {
        return menorAtual;
    }
}

int main() {
    int tamanho;
    
    printf("Tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    if (tamanho <= 0) {
        printf("Tamanho do vetor deve ser maior que zero.\n");
        return 1;
    }
    
    int vetor[tamanho];
    
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
    
    int menor = encontrarMenorElemento(vetor, tamanho);
    
    printf("O menor elemento no vetor e: %d\n", menor);
    
    return 0;
}