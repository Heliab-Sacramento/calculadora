#include <stdio.h>                                           
#include <stdlib.h>

int main() {
    int opcao;
    float saldo = 1000, emprestimo = 0, valor;

    do {
        printf("\n=== BANCO ===\n");
        printf("1 - Ver saldo\n");
        printf("2 - Depositar\n");
        printf("3 - Sacar\n");
        printf("4 - Pedir emprestimo\n");
        printf("5 - Pagar emprestimo\n");
        printf("6 - Consultar emprestimo\n");
        printf("7 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Saldo: R$ %.2f\n", saldo);
                break;

            case 2:
                printf("Valor do deposito: ");
                scanf("%f", &valor);

                if (valor > 0) {
                    saldo += valor;
                    printf("Deposito realizado!\n");
                } else {
                    printf("Valor invalido!\n");
                }
                break;

            case 3:
                printf("Valor do saque: ");
                scanf("%f", &valor);

                if (valor > 0 && valor <= saldo) {
                    saldo -= valor;
                    printf("Saque realizado!\n");
                } else {
                    printf("Saldo insuficiente ou valor invalido!\n");
                }
                break;

            case 4:
                printf("Valor do emprestimo: ");
                scanf("%f", &valor);

                if (valor > 0) {
                    saldo += valor;
                    emprestimo += valor;
                    printf("Emprestimo aprovado!\n");
                } else {
                    printf("Valor invalido!\n");
                }
                break;

            case 5:
                if (emprestimo == 0) {
                    printf("Sem dividas.\n");
                } else {
                    printf("Divida atual: R$ %.2f\n", emprestimo);
                    printf("Valor para pagar: ");
                    scanf("%f", &valor);

                    if (valor > 0 && valor <= saldo && valor <= emprestimo) {
                        saldo -= valor;
                        emprestimo -= valor;
                        printf("Pagamento realizado!\n");
                    } else {
                        printf("Pagamento invalido!\n");
                    }
                }
                break;

            case 6:
                printf("Emprestimo atual: R$ %.2f\n", emprestimo);
                break;

            case 7:
                printf("Ate breve!\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 7);

    return 0;
}
```