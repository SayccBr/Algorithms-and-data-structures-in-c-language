#include <stdio.h> // Inclui a biblioteca padrão de entrada/saída

// Função para realizar o algoritmo de ordenação Bubble Sort
void bubble_sort(int arr[], int n) {
    // Loop para percorrer o array várias vezes
    for (int i = 0; i < n; i++) {
        // Loop para comparar e trocar elementos adjacentes
        for (int j = 0; j < n - i - 1; j++) {
            // Se o elemento atual é maior que o próximo, troca-os
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j]; // Armazena o valor do elemento atual em temp
                arr[j] = arr[j + 1]; // Move o próximo elemento para a posição atual
                arr[j + 1] = temp; // Coloca temp (valor original do elemento atual) na posição do próximo elemento
            }
        }
    }
}

int main() {
    int vetor[] = {5, 2, 9, 1, 5, 6}; // Declara um array de inteiros
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); // Calcula o tamanho do array

    bubble_sort(vetor, tamanho); // Chama a função de ordenação Bubble Sort

    // Imprime o array ordenado
    printf("Bubble Sort: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]); // Imprime cada elemento do array
    }
    printf("\n"); // Imprime uma nova linha

    return 0;
}
