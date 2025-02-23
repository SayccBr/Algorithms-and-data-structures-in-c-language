#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    char sexo;
    char cpf[12];
    char dataNascimento[11];
    int codigoSetor;
    char cargo[30];
    float salario;
} Funcionario;

int main() {
    Funcionario funcionario;

    printf("Digite o nome do funcionario: ");
    fgets(funcionario.nome, 50, stdin);

    printf("Digite a idade do funcionario: ");
    scanf("%d", &funcionario.idade);

    printf("Digite o sexo do funcionario (M/F): ");
    scanf(" %c", &funcionario.sexo);

    printf("Digite o CPF do funcionario: ");
    scanf(" %s", funcionario.cpf);

    printf("Digite a data de nascimento do funcionario (dd/mm/aaaa): ");
    scanf(" %s", funcionario.dataNascimento);

    printf("Digite o codigo do setor (0-99) do funcionario: ");
    scanf("%d", &funcionario.codigoSetor);

    printf("Digite o cargo do funcionario: ");
    fgets(funcionario.cargo, 30, stdin);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario.salario);

    printf("\nDados do funcionario:\n");
    printf("Nome: %s\n", funcionario.nome);
    printf("Idade: %d\n", funcionario.idade);
    printf("Sexo: %c\n", funcionario.sexo);
    printf("CPF: %s\n", funcionario.cpf);
    printf("Data de Nascimento: %s\n", funcionario.dataNascimento);
    printf("Codigo do Setor: %d\n", funcionario.codigoSetor);
    printf("Cargo: %s\n", funcionario.cargo);
    printf("salario: %.2f\n", funcionario.salario);

    return 0;
}