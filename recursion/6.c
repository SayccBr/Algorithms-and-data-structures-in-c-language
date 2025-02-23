#include <stdio.h>

int multi(int n1, int n2) {
    if (n2 == 0) {
        return 0;
    } else if (n2 > 0) {
        return n1 + multi(n1, n2 - 1);
    } else {
        return -multi(n1, -n2);
    }
}

int main() {
    int num1, num2;
    
    printf("N1: ");
    scanf("%d", &num1);
    
    printf("N2: ");
    scanf("%d", &num2);
    
    int resultado = multi(num1, num2);
    
    printf("Resultado: %d\n", resultado);
    
    return 0;
}