#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

// Declarando funções

struct dadosDoProduto
{
    char nome[250];
    float preco;
    int quantidade;
};

void atualizacao(int estoque, float preco, int quantidadeProduto)
{
    int atualizar;
    float novoPreco;
    atualizar = estoque - quantidadeProduto;
    novoPreco = preco * atualizar;
    printf("Estoque Atualizado: %d \n", atualizar);
    printf("Preço total no estoque atualizado: %.1f \n", novoPreco);
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    // Declarando Variaveis
    int escolha, opcao, quantidade;
    float valor;
    char NomeDoProduto[250];
    struct dadosDoProduto produtos;

    printf("Deseja Cadastra novo Produto?\n");
    printf("1 - Sim.\n");
    printf("2 - Não.\n");
    printf("\nSua Escolha:");
    scanf("%i", &opcao);

    system("cls||clear");

    switch (opcao)
    {
    case 1:

        fflush(stdin);
        printf("\n------------Bem-Vindo-------------\n");
        printf("Registrando Novo Produto!.\n");
        printf("Nome: ");
        gets(produtos.nome);

        printf("Preço: ");
        scanf("%f", &produtos.preco);

        fflush(stdin);

        printf("Quantidade em estoque: ");
        scanf("%i", &produtos.quantidade);

        system("cls||clear");

        break;

    default:
        break;
    }

    do
    {
        printf("\n-----------Bem-Vindo-----------\n");
        printf("1 - Realizar compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa.\n");
        printf("\nSua Escolha: ");
        scanf("%i", &escolha);

        system("cls||clear");

        fflush(stdin);

        switch (escolha)
        {
        case 1:
            fflush(stdin);

            printf("Nome do produto: \n");
            gets(NomeDoProduto);

            printf("Digite o valor do produto: ");
            scanf("%f", &valor);

            printf("Quantidade desejada do produto: ");
            scanf("%d", &quantidade);

            if (quantidade <= produtos.quantidade)
            {
                printf("Compra realizada com sucesso!\n");
            }
            else
            {
                printf("Sem estoque no momento.\n");
            }

            break;

        case 2:

            printf("Produto em estoque.");
            printf("\n");
            printf("Nome: %s \n", produtos.nome);
            atualizacao(produtos.quantidade, produtos.preco, quantidade);

            break;
           
        case 3:
                printf("Finalizado sua Compra, Porfavor Volte Sempre.\n");
                break;   
           
        default:
        	printf("Opção inválida.\n");
            break;
        }

    } while (opcao != 3);

    return 0;
}
