#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define TAM 4

// Declarando funções
struct Funcionirios
{
    char nome[250];
    char cargo[250];
    float salario;
};

float calcularMediaSalarial(struct Funcionirios funcionirios[], char cargoBuscado[])
{
	int i;
    int contador = 0;
    float somaSalarial = 0;

    for ( i = 0; i < TAM; i++)
    {
        if (strcmp(funcionirios[i].cargo, cargoBuscado) == 0)
        {
            somaSalarial += funcionirios[i].salario;
            contador++;
        }
    }

    if (contador == 0)
    {
        return 0;
    }
    else
    {
        return somaSalarial / contador;
    }
}

void limpatela()
{
    system("cls || clear");
    printf("COREBRAS! Calculadora de Média Salárial\n\n");
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    // Declarando Variaveis

    int opcao;
    int i = 0;
    struct Funcionirios funcionirio[TAM];

    // Solicitindo dados

    do
    {
        titulo();
        printf("Código | Descrição\n");
        printf("   1   | Adicionar informação\n");
        printf("   2   | Sair e exibir\n\n");
        printf("Sua Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            setbuf(stdin, 0);
            printf("\nDigite o nome do %dº funcionário: ", i + 1);
            gets(funcionirio[i].nome);
            printf("Digite o nome do cargo: ");
            gets(funcionirio[i].cargo);
            printf("Digite o valor do salario: ");
            scanf("%f", &funcionirio[i].salario);
            i++;
            break;
        }

    } while (opcao != 2);

    // Resultados

    limpatela();
    float mediaSalarialProgramadores = (calcularMediaSalarial);
    printf("Média salarial dos programadores: R$ %.2f\n", mediaSalarialProgramadores);

    return 0;
}

