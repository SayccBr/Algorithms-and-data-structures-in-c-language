#include <stdio.h> // Inclui a biblioteca padrão de entrada/saída

// Função para realizar o algoritmo de ordenação por inserção
void insertionSort(int arr[], int n) {
    int i, key, j;
    // Loop para percorrer o array começando do segundo elemento
    for (i = 1; i < n; i++) {
        key = arr[i]; // Armazena o valor atual em key
        j = i - 1;
        // Move os elementos do array que são maiores que key para uma posição à frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Insere key na posição correta
    }
}

// Função para imprimir os elementos do array
void printArray(int arr[], int n) {
    int i;
    // Loop para percorrer o array e imprimir cada elemento
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Imprime o elemento atual seguido de um espaço
    }
    printf("\n"); // Imprime uma nova linha
}

int main() {
    int arr[] = {12, 11, 13, 5, 6}; // Declara um array de inteiros
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do array

    printf("Array original:\n");
    printArray(arr, n); // Imprime o array original

    insertionSort(arr, n); // Chama a função de ordenação por inserção

    printf("Array ordenado:\n");
    printArray(arr, n); // Imprime o array ordenado

    return 0;
}
