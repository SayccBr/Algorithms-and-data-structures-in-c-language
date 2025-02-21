#include <stdio.h> // Inclui a biblioteca padrão de entrada/saída
#include <stdlib.h> // Inclui a biblioteca padrão para alocação de memória, controle de processos, conversões e outras operações
#include <time.h> // Inclui a biblioteca para manipulação do tempo, útil para gerar números aleatórios

// Função para mesclar dois subarrays de arr[]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; // Tamanho do primeiro subarray
    int n2 = r - m; // Tamanho do segundo subarray

    int L[n1], R[n2]; // Arrays temporários para armazenar os elementos dos subarrays

    // Copia os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = l; // Índice inicial do array mesclado

    // Mescla os arrays temporários de volta em arr[l..r]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função para realizar o algoritmo de ordenação Merge Sort
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Calcula o ponto médio para dividir o array
        merge_sort(arr, l, m); // Ordena a primeira metade
        merge_sort(arr, m + 1, r); // Ordena a segunda metade
        merge(arr, l, m, r); // Mescla as duas metades ordenadas
    }
}

int main() {
    int n = 10; // Tamanho do array
    int arr[n]; // Declara um array de inteiros

    srand(time(0)); // Inicializa o gerador de números aleatórios com o tempo atual
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Preenche o array com números aleatórios de 0 a 99
    }

    // Imprime o array original
    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    merge_sort(arr, 0, n - 1); // Chama a função de ordenação Merge Sort

    // Imprime o array ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
