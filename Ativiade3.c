#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>


//Declarando funções

struct dadosDoProduto {
    char nome[250];
    float preco;
    int quantidade;
};

float calcularTotal(struct dadosDoProduto produto) {
    return produto.preco * produto.quantidade;
}

void realizarCompra(struct dadosDoProduto *produto, int quantidadeComprada) {
    produto->quantidade -= quantidadeComprada;
}

int main() {
     setlocale(LC_ALL,"portuguese");
 //Declarando Variaveis       
    struct dadosDoProduto produtos = {"Camisa", 25.99, 50};  
    int opcao;
    int quantidadeComprada;

    //Solicitando Dados

    do {
        printf("-------Bem-Vindo--------");    
        printf("\nEscolha uma opcao:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        printf("\nSua Escolha:");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a quantidade que deseja comprar: ");
                scanf("%d", &quantidadeComprada);
                if (quantidadeComprada > produtos.quantidade) {
                    printf("Quantidade insuficiente em estoque.\n");
                } else {
                    realizarCompra(&produtos, quantidadeComprada);
                    printf("Compra realizada com sucesso.\n");
                }
                break;
            case 2:
                printf("O valor total em estoque do produto e: R$%.2f\n", calcularTotal(produtos));
                printf("Produto: %s\n", produtos.nome);
                printf("Preço: R$%.2f\n", produtos.preco);
                printf("Quantidade em estoque: %i\n", produtos.quantidade);
                break;
            case 3:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Escolha novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
