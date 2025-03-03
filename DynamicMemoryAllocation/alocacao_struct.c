#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} PONTO;

PONTO *aloca(int x, int y) {
    PONTO *ponto = (PONTO *)malloc(sizeof(PONTO));
    if (ponto != NULL) {
        ponto->x = x;
        ponto->y = y;
    }
    return ponto;
}

void libera(PONTO *a) {
    free(a);
}

float distancia(PONTO *a, PONTO *b) {
    int dx = a->x - b->x;
    int dy = a->y - b->y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int x1, y1, x2, y2;
    printf("Digite as coordenadas do ponto A (x y): ");
    scanf("%d %d", &x1, &y1);
    printf("Digite as coordenadas do ponto B (x y): ");
    scanf("%d %d", &x2, &y2);
    PONTO *pontoA = aloca(x1, y1);
    PONTO *pontoB = aloca(x2, y2);
    if (pontoA == NULL || pontoB == NULL) {
        printf("Erro na alocacao de memoria. Encerrando o programa.\n");
        return 1;
    }
    float dist = distancia(pontoA, pontoB);
    printf("A distancia entre os pontos A e B e: %.2f\n", dist);
    libera(pontoA);
    libera(pontoB);
    return 0;
}
