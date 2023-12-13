#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 200

struct dadosDoFuncionario
{
    char nome[250], cargo[250];
    float salario;
};

float mediaDoFuncionario(struct dadosDoFuncionario Funcionarios[])
{
    int i, j;
    float soma, resultado;

    for (j = 0; j < TAM; j++)
    {
        if (strcmp(Funcionarios[i].cargo, "Desenvolvedor") == 0)
        {
            j++;
            soma += Funcionarios[i].salario;
        }
    }
    resultado = soma / (float)j;
    return resultado;
}

void limpatela(){
  fflush(stdin);
  system("cls || clear");
}

int main()
{

    int opcao, i;
    
    struct dadosDoFuncionario funcionarios[TAM];

    do
    {
        printf("\n--------------Bem-Vindo--------------\n");
        printf(" 1 - Adicionar Informações do Funcionario\n");
        printf(" 2 - Exibir Informações do Funcionario\n");
        printf(" 3 - Sair programa\n");
        printf("\nSua Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            fflush(stdin);

            printf("Digite o nome do %dº funcionário: ", i + 1);
            gets(funcionarios[i].nome);

            printf("Digite o nome do cargo: ");
            gets(funcionarios[i].cargo);

            printf("Digite o valor do salario: ");
            scanf("%f", &funcionarios[i].salario);

            limpatela();

            break;
        case 2:
            printf("Média salarial: R$ %.2f\n", mediaDoFuncionario(funcionarios));
            break;
        }

    } while (opcao != 3);

    return 0;
}
