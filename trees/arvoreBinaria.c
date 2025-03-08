#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó da árvore
struct TreeNode {
    int key;
    char name[50];
    struct TreeNode* left;
    struct TreeNode* right;
};

// Função para criar um novo nó
struct TreeNode* createNode(int key, const char* name) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode != NULL) {
        newNode->key = key;
        strncpy(newNode->name, name, sizeof(newNode->name));
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Função para inserir um nó na árvore
struct TreeNode* insertNode(struct TreeNode* root, int key, const char* name) {
    if (root == NULL) {
        return createNode(key, name);
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key, name);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key, name);
    }

    return root;
}

// Função para procurar uma chave e retornar o nome associado
const char* searchByKey(struct TreeNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key == root->key) {
        return root->name;
    } else if (key < root->key) {
        return searchByKey(root->left, key);
    } else {
        return searchByKey(root->right, key);
    }
}

// Funções para encontrar a menor chave e o nome correspondente
int findMinKey(struct TreeNode* root) {
    if (root->left == NULL) {
        return root->key;
    }
    return findMinKey(root->left);
}

const char* findMinName(struct TreeNode* root) {
    if (root->left == NULL) {
        return root->name;
    }
    return findMinName(root->left);
}

// Funções para encontrar a maior chave e o nome correspondente
int findMaxKey(struct TreeNode* root) {
    if (root->right == NULL) {
        return root->key;
    }
    return findMaxKey(root->right);
}

const char* findMaxName(struct TreeNode* root) {
    if (root->right == NULL) {
        return root->name;
    }
    return findMaxName(root->right);
}

// Funções para percorrer a árvore em pré-ordem, em-ordem e pós-ordem
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d (%s)\n", root->key, root->name);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d (%s)\n", root->key, root->name);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d (%s)\n", root->key, root->name);
    }
}

// Função para exibir o menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Inserir no\n");
    printf("2. Procurar por chave\n");
    printf("3. Menor chave e nome\n");
    printf("4. Maior chave e nome\n");
    printf("5. Exibir arvore (pre-ordem, em-ordem, pos-ordem)\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    struct TreeNode* root = NULL;

    // Exemplo de inserção de nós
    root = insertNode(root, 10, "Alice");
    root = insertNode(root, 5, "Bob");
    root = insertNode(root, 15, "Charlie");

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int key;
                char name[50]; 
                printf("Digite a chave: ");
                scanf("%d", &key);
                printf("Digite o nome: ");
                scanf("%s", name);
                root = insertNode(root, key, name);
                break;
            }
            case 2: {
                int searchKey;
                printf("Digite a chave a ser procurada: ");
                scanf("%d", &searchKey);
                const char* result = searchByKey(root, searchKey);
                if (result != NULL) {
                    printf("Nome associado a chave %d: %s\n", searchKey, result);
                } else {
                    printf("Chave %d nao encontrada.\n", searchKey);
                }
                break;
            }
            case 3:
                printf("Menor chave: %d (%s)\n", findMinKey(root), findMinName(root));
                break;
            case 4:
                printf("Maior chave: %d (%s)\n", findMaxKey(root), findMaxName(root));
                break;
            case 5:
                printf("Percursos pre-ordem:\n");
                preorderTraversal(root);
                printf("Percursos em-ordem:\n");
                inorderTraversal(root);
                printf("Percursos pos-ordem:\n");
                postorderTraversal(root);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (choice != 0);


    return 0;
}