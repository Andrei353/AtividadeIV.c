#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define TAM 3

//Declarando funções

struct dadosDoContato {
    char nome[250];
    char telefone[22];
    char email[250];
};


void limpatela(){
  fflush(stdin);
  system("cls || clear");
}

char* buscarTelefonePorNome(struct dadosDoContato contatos[],char* contatoDesejado)
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        if (strcmp(contatos[i].nome, contatoDesejado) == 0)
        {
            printf("Número respectivo: %s",contatos[i].telefone);
            break;
        }
    }
    printf("\nContato não encontrado");
}

int main() {
    //Declarando Variaveis
    struct dadosDoContato contatos[TAM];
    int i;
    char contatoDesejado[200];
    
    for ( i = 0; i < TAM; i++) {
        printf("%dº Contato:\n", i + 1);
        printf("Digite o Nome: ");
        scanf("%s", contatos[i].nome);
        printf("Digite o Telefone: ");
        scanf("%s", contatos[i].telefone);
        printf("Digite o Email: ");
        scanf("%s", contatos[i].email);
    }

    limpatela();

    printf("Digite um nome para busca: ");
    gets(contatoDesejado);

    buscarTelefonePorNome(contatos,contatoDesejado);

    return 0;
}
