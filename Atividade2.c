#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define TAM 5

struct Alunos
{
    char nome[200];
    char dataDeNascimento[11];
};

float calcularMedia(float nota[])
{
    int i;
    float soma, media;
    for (i = 0; i < 2; i++)
    {
        soma += nota[i];
    }

    return media = soma / 2;
}

char *situacao(float media)
{
    char situacao[200];

    if (media > 7)
    {
        strcpy(situacao, "Aprovado");
    }
    else
    {
        strcpy(situacao, "Reprovado");
    }

    return situacao;
}

void limpatela(){
  fflush(stdin);
  system("cls || clear");
}

int main()
{
    float nota[2], mediaTotal;
    int i, j;

    struct Alunos alunos[TAM];

    for (i = 0; i < TAM; i++)
    {
        printf("\nDigite o seu nome: ");
        gets(alunos[i].nome);

        printf("\nDigite a sua data de nascimento: ");
        gets(alunos[i].dataDeNascimento);

        for (j = 0; j < 2; j++)
        {
            printf("\nSua %dª nota: ", i + 1);
            scanf("%f", &nota[j]);
        }

         limpatela();

        mediaTotal = calcularMedia(nota);
        for ( i = 0; i < TAM; i++)
        {
            printf("Aluno: %s, Média: %.2f, Situação: %s\n", alunos[i].nome, mediaTotal, situacao(mediaTotal) ? "Aprovado" : "Reprovado");
        }
    }

    return 0;
}
