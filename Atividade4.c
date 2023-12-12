#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

// Declarando funções

struct ContaBancaria
{
    char numeroConta[250];
    char nomeTitular[250];
    float saldo;
    char tipoConta[250];
};

void depositar(struct ContaBancaria *conta, float valor)
{
    conta->saldo += valor;
    printf("Deposito de R$%.2f realizado com sucesso.\n", valor);
}

void sacar(struct ContaBancaria *conta, float valor)
{
    if (valor > conta->saldo)
    {
        printf("Saldo insuficiente para realizar o saque.\n");
    }
    else
    {
        conta->saldo -= valor;
        printf("Saque de R$%.2f realizado com sucesso.\n", valor);
    }
}

void imprimirSaldo(struct ContaBancaria conta)
{
    printf("Saldo atual: R$%.2f\n", conta.saldo);
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    // Declarando Variaveis

    struct ContaBancaria contas;
    int opcao;
    float valor;

    do
    {
        printf("--------Bem-vindo--------");
        printf("\nEscolha uma operacao:\n");
        printf("1 - Registrar Conta\n");
        printf("2 - Depositar dinheiro\n");
        printf("3 - Sacar dinheiro\n");
        printf("4 - Imprimir saldo\n");
        printf("5 - Sair do programa\n");
        printf("\nDigite sua Escolha:");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            fflush(stdin);

            printf("Nome do titular: ");
            gets(contas.nomeTitular);

            printf("Número da conta: ");
            gets(contas.numeroConta);

            printf("Tipo de conta desejada: ");
            gets(contas.tipoConta);

            printf("Qual saldo terá na conta: ");
            scanf("%f", &contas.saldo);

            break;
        case 2:
            printf("Digite o valor a ser depositado: ");
            scanf("%f", &valor);
            depositar(&contas, valor);
            break;
        case 3:
            printf("Digite o valor a ser sacado: ");
            scanf("%f", &valor);
            sacar(&contas, valor);
            break;
        case 4:
            imprimirSaldo(contas);
            break;
        case 5:
            printf("Saindo da sua Conta Bancaria.\n");
            break;
        default:
            printf("Opcao invalida. Escolha novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
