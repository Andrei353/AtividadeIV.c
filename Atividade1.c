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

// Função para buscar o número de telefone pelo nome
char* buscarTelefonePorNome(struct dadosDoContato contatos[], int tamanho, char nome[]) {
	int i;
	
    for ( i = 0; i < TAM; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
         break;
        }
    }
    return "Contato não encontrado";
}

int main() {
    //Declarando Variaveis
    struct dadosDoContato contatos[TAM];
    int i;
    
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

    // Busca e impressão do número de telefone de um contato específico
    char nomeBusca[250];
    printf("Digite o nome do contato para buscar o número de telefone: ");
    scanf("%s", nomeBusca);

    char* telefoneEncontrado = buscarTelefonePorNome(contatos, 3, nomeBusca);
    printf("O número de telefone de %s é: %s\n", nomeBusca, telefoneEncontrado);

    return 0;
}
