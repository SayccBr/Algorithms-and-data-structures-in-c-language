#include <stdio.h>
#include <math.h>

typedef struct {
    float raio;
    float argumento;
} Polar;

typedef struct {
    float x;
    float y;
} Cartesiana;

int main() {
    Polar polar;
    Cartesiana cartesiana;

    printf("Digite o raio em coordenadas polares: ");
    scanf("%f", &polar.raio);

    printf("Digite o argumento em radianos: ");
    scanf("%f", &polar.argumento);

    cartesiana.x = polar.raio * cos(polar.argumento);
    cartesiana.y = polar.raio * sin(polar.argumento);

    printf("Coordenadas cartesianas: (%.2f, %.2f)\n", cartesiana.x, cartesiana.y);

    return 0;
}