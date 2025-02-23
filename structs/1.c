#include <stdio.h>

typedef struct {
    float hora;
    float minuto;
    float segundo;
} Horario;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    Horario horario2;
    Data data2;
    char texto[200];
} Compromisso;

typedef struct {
    Compromisso compromisso;
} Alarme;

int main() {
    Alarme config;

    printf("Insira a data (dia mes ano): ");
    scanf("%d %d %d", &config.compromisso.data2.dia, &config.compromisso.data2.mes, &config.compromisso.data2.ano);

    printf("Insira o horário (hora minuto segundo): ");
    scanf("%f %f %f", &config.compromisso.horario2.hora, &config.compromisso.horario2.minuto, &config.compromisso.horario2.segundo);
    
    getchar();

    printf("Insira o texto do compromisso: ");
    fgets(config.compromisso.texto, 200, stdin); 



    return 0;
}