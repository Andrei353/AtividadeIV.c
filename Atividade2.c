#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define t 2
#define g 5

// Declarando Funções e Struct
struct dados_aluno
{
    char nome[200];
    char dataDeNascimento;
    float notas[t];
};

void limpatela()
{
    fflush(stdin);
    system("cls || clear");
}

float mediaTotal(float numero[])
{
    float soma = 0;
    int i;

    for (i = 0; i < t; i++)
    {
        soma += numero[i];
    }

    return soma / t;
}

char *situacao(float media)
{
    char resultado[250];
    media >= 7 ? strcpy(resultado, "Aprovado") : strcpy(resultado, "Reprovado");
    return resultado;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    // Declarando Variaveis
    int i, j;
    float media;
    struct dados_aluno aluno[g];

    // Solicitando Dados

    for (j = 0; j < g; j++)
    {
        printf("\nDigite o nome do Aluno: ");
        gets(aluno[j].nome);
        printf("\nDigite a Data de Nascimento: ");
        gets(aluno[j].dataDeNascimento);
        for (i = 0; i < t; i++)
        {
            printf("\n Digite a %iº Nota: ", i + 1);
            scanf("%f", &aluno[j].notas[i]);
        }

    }

    limpatela();

    // Resultados
    media = mediaTotal(aluno->notas);

    for (j = 0; j < g; j++)
    {

        printf("Nome: %s \n", aluno[j].nome);
        printf("Data de Nascimento: %i \n", aluno[j].dataDeNascimento);

        for (i = 0; i < t; i++)
        {
            printf("Notas: %f \n", aluno[j].notas[i]);
        }

        printf("Media: %f \n", media);
        printf("Situação: %s \n", situacao(media));
    }

    return 0;
}