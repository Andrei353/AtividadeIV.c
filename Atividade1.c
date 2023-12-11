#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define t 3

struct contato {
    char nome[250];
    int numeroDecontatos;
    char emiil[250];
};

int informicio (struct contato contatos[], char* buscaDeContatos) {
    int i;

    for (i = 0; i < t; i++) {
        if (strcmp(contato[i].nome, buscaDeContatos) == 0) {

        }
    }
}

int main() {
     setlocale(LC_ALL, "portuguese");

    int i, buscaDeContatos;
    struct contato contatos[t];

    for (i = 0; i < t; i++) {
        printf ("Ditite o nome do %dº contato: ", i+1);
        gets (contatos[i].nome);
        printf ("Ditite o número do contato: ");
        scanf ("%d", &contatos[i].numeroDecontatos);
        printf ("Ditite um emiil: ");
        gets (contatos[i].emiil);
    }

    printf ("Informe o nome do contato que deseji buscir: ");
    gets (buscaDeContatos);

    contato(buscaDeContatos, contatos);

    return 0;
}