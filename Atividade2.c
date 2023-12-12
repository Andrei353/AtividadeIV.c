#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

// Declarando funções

#define MAX 200
#define GRAN 2
#define TAM 5

struct Alunos {
    char dataDeNascimento[MAX];
    char nome[MAX];
    float nota[GRAN];
    float media;
};

float mediaTotal (float numero[]) {
    int i;
    float soma = 0, media;

    for (i = 0; i < GRAN; i++) {
        soma += numero[i];
    }
    return media = soma / (float) GRAN;
}
char* situacao (float mediaAlunos) {
    char boletim[MAX];

    if (mediaAlunos >= 7) {
        strcpy (boletim, "Aprovado");
    
    } else {
        strcpy (boletim, "Reprovado"); }
    
    return boletim;
}

void limpatela(){
  fflush(stdin);
  system("cls || clear");

}

int main ( ) {
    setlocale (LC_ALL, "portuguese");

    //Declarando variáveis
    int i, j;
    struct Alunos alunos[TAM];

    //Solicitando dados
    for (i = 0; i < TAM; i++) {
        printf ("Digite o nome do %dº alunos: ", i+1);
        gets (alunos[i].nome);
        printf ("Digite a data de nascimento do alunos: ");
        gets (alunos[i].dataDeNascimento);

        for (j = 0; j < GRAN; j++) {
            do {
                printf ("Digite a %dª nota: ", j+1);
                scanf ("%f", &alunos[i].nota[j]);

                if (alunos[i].nota[j] < 0 || alunos[i].nota[j] > 10) {
                    printf ("\nNota Inválida!!!\n\n"); }

            } while (alunos[i].nota[j] < 0 || alunos[i].nota[j] > 10);
        }
        fflush (stdin);
        printf ("\n");
    
        alunos[i].media = mediaTotal(alunos[i].nota);
    }

    //Resultado
  limpatela();
     
    for (i = 0; i < TAM; i++) {
        printf ("Nome do %dº alunos: %s\n\n", i+1, alunos[i].nome);
        printf ("Data de nascimento: %d\n", alunos[i].dataDeNascimento);

        for (j = 0; j < GRAN; j++) {
            printf ("%dª nota: %.2f\n", j+1, alunos[i].nota[j]);
        }
        printf ("Média: %.2f\n", alunos[i].media);
        printf ("Situação: %s\n\n", situacao (alunos[i].media));
    }

    return 0;
}
