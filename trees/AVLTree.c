#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore AVL
struct AVLNode {
    double key;
    int height; // Altura do nó
    struct AVLNode* left;
    struct AVLNode* right;
};

// Função para criar um novo nó
struct AVLNode* createNode(double key) {
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->key = key;
    newNode->height = 1; // Inicialmente, a altura é 1 (nó folha)
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para calcular a altura de um nó
int getHeight(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Função para atualizar a altura de um nó
void updateHeight(struct AVLNode* node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Função para realizar a rotação simples à direita
struct AVLNode* rotateRight(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    // Realiza a rotação
    x->right = y;
    y->left = T2;

    // Atualiza as alturas
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Função para realizar a rotação simples à esquerda
struct AVLNode* rotateLeft(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    // Realiza a rotação
    y->left = x;
    x->right = T2;

    // Atualiza as alturas
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Função para inserir uma chave na árvore AVL
struct AVLNode* insert(struct AVLNode* root, double key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    // Atualiza a altura e verifica o balanceamento
    updateHeight(root);
    int balance = getHeight(root->left) - getHeight(root->right);

    // Casos de balanceamento
    if (balance > 1 && key < root->left->key)
        return rotateRight(root);
    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Função para encontrar a menor chave
double findMin(struct AVLNode* root) {
    if (root->left == NULL)
        return root->key;
    return findMin(root->left);
}

// Função para encontrar a maior chave
double findMax(struct AVLNode* root) {
    if (root->right == NULL)
        return root->key;
    return findMax(root->right);
}

int main() {
    struct AVLNode* root = NULL;
    int choice;
    double key;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir chave\n");
        printf("2. Menor chave\n");
        printf("3. Maior chave\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite a chave: ");
                scanf("%lf", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Menor chave: %.2lf\n", findMin(root));
                break;
            case 3:
                printf("Maior chave: %.2lf\n", findMax(root));
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }while(choice != 0);
    return 0;
}