#include <stdio.h>

void heapsort(int *vetor, int tamanho){
    int i, auxiliar;

    for (i = (tamanho-1)/2; i>=0; i--){//calcula com a posição da metade do vetor e regredindo até o inicio, até chegar na posição 0
        criarHeap(vetor, i, tamanho-1);//função de criar a heap, com parãmetros do vetor, i e o tamanho decrescendo
    }

    for (i = tamanho - 1; i>=1; i--){ //o laço começa com i valendo o ultimo elemento do array, sendo percorrido do final ao inicio, ele move o maior elemento(que está no topo da heap, ou seja o maior elemento) para o final do vetor
        auxiliar = vetor[0]; //a raiz do heap, o maior valor, é salvo na auxiliar
        vetor[0] = vetor [i];//depois, o ultimo elemento do heap é colocado no lugar da raiz
        vetor[i] = auxiliar; //esse valor é então colocado na variavel auxiliar: o maior valor do heap foi movido para o final do array, ou seja, o maior valor está no final do vetor, estando agora ordenado

        criarHeap(vetor, 0, i-1);
    }
}


void criarHeap(int *vetor, int raiz, int fim) { //a função organmiza uma subarvore; raiz é o indice da raiz da subarvore que está sendo ajustada; fim é o ultimo elemeto desssa subarvore
    int valorRaiz = vetor[raiz]; //armazena o valor dessa raiz em uma variavel auxiliar

    int filhoEsquerdo = raiz * 2 + 1;  //calcula o indice do filho esquerdo, seguindo a propriedade de heapsort, ele é o dobro+1 do indice da raiz ou vetor

    
    while (filhoEsquerdo <= fim) { //o loop fica até o indice do filho esquerdo ser menor ou se igualar ao indice do fim do vetor
        if (filhoEsquerdo < fim) { //verifica se existe um filho a direita, e depois, na linha de baixo, verifica qual dos dois é maior
            if (vetor[filhoEsquerdo] < vetor[filhoEsquerdo + 1]) {
                filhoEsquerdo = filhoEsquerdo + 1; //se o filho a direita for maior, o filho a esquerda recebe o valor do da direita
            }
        }

        
        if (valorRaiz < vetor[filhoEsquerdo]) { //se o valor da raiz(o auxiliar salvo com o valor original da raiz),, se essa raiz for menor que o maior filho(o da esquerda) ocorre uma 'rotação', em que esse filho maior vira a raiz
            vetor[raiz] = vetor[filhoEsquerdo]; //se a condição for verdadeiro, a raiz passa a apontar pra esse filho
            raiz = filhoEsquerdo;  //a raiz é autualizada para o indice desse filho que foi movido, ocupando seu lugar
            filhoEsquerdo = 2 * raiz + 1; //o filho a esquerda é novamente calculado
        }
        else {
            filhoEsquerdo = fim + 1; //se a raiz(valorRaiz) for maior ou igual ao maior filho, o heap já está ajustado e o heap encerra
        }
    }

    vetor[raiz] = valorRaiz;  //o valor original da raiz é colocado na posição correta no heap, assim a subarvore esta organizada
}





int main() {
    int vetor[] = {12, 11, 13, 5, 6, 7};  // vetor
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);  // calcula o tamanho do vetor

    printf("Vetor original: \n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]); 
    }
    printf("\n");

    heapsort(vetor, tamanho);  // função Heap Sort

    printf("Vetor ordenado: \n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);  //vetor ordenado
    }
    printf("\n");

    return 0;
}