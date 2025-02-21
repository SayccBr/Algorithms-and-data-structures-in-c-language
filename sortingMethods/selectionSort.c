#include <stdio.h> // Inclui a biblioteca padrão de entrada/saída

// Função para realizar o algoritmo de ordenação por seleção
void selection_sort(int arr[], int n) {
    // Loop para percorrer o array e encontrar o menor elemento
    for (int i = 0; i < n; i++) {
        int min_index = i; // Assume que o menor elemento está na posição i
        // Loop para encontrar o menor elemento no restante do array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) { // Se encontrar um elemento menor, atualiza min_index
                min_index = j;
            }
        }
        // Troca o elemento atual com o menor elemento encontrado
        int temp = arr[i]; // Armazena o valor do elemento atual em temp
        arr[i] = arr[min_index]; // Move o menor elemento para a posição atual
        arr[min_index] = temp; // Coloca temp (valor original do elemento atual) na posição do menor elemento encontrado
    }
}

int main() {
    int vetor[] = {5, 2, 9, 1, 5, 6}; // Declara um array de inteiros
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); // Calcula o tamanho do array

    selection_sort(vetor, tamanho); // Chama a função de ordenação por seleção

    // Imprime o array ordenado
    printf("Selection Sort: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]); // Imprime cada elemento do array
    }
    printf("\n"); // Imprime uma nova linha

    return 0;
}
