#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[5][80];
    int rg[5], ano_nascimento[5];
    float altura[5], peso[5], imc[5];
    int i;
    int cadastros = 0;
    int opcao;
    char tmp;

    for(;;) {
        printf("----------------------------------------------------------------------------\n");
        printf("Escolha uma opcao abaixo\n");
        printf("1 - Cadastrar\n");
        printf("2 - Imprimir\n");
        printf("3 - Calcular IMC\n");
        printf("0 - Sair\n>> ");
        scanf("%d", &opcao);
        scanf("%c", &tmp);
        printf("----------------------------------------------------------------------------\n");

        if(opcao == 0)
            exit(0);
        else if(opcao == 1) {
            if(cadastros < 5) {
                printf("*** Cadastro de Pessoas ***\n");
                printf("Digite o nome: ");
                gets(nome[cadastros]);
                printf("Digite o RG: ");
                scanf("%d", &rg[cadastros]);
                printf("Digite o ano de nascimento: ");
                scanf("%d", &ano_nascimento[cadastros]);
                printf("Digite a altura (m): ");
                scanf("%f", &altura[cadastros]);
                printf("Digite o peso (kg): ");
                scanf("%f", &peso[cadastros]);
                cadastros++; 
            }
            else {
                printf("Numero maximo de pessoas cadastradas atingido\n"); 
                continue;
            }
        }
        else if(opcao == 2) {
            printf("*** Listar pessoas ***\n");
            if(cadastros == 0) {
                printf("Nao ha pessoas cadastradas.\n");
                continue;
            }
            else {
                for(i=0; i<cadastros; i++) {
                    printf("----------------------------------------------------------------------------\n");
                    printf("Nome: %s\nRG: %d\nAno de Nascimento: %d\nAltura: %.2f m\nPeso: %.2f kg\n",
                            nome[i], rg[i], ano_nascimento[i], altura[i], peso[i]);
                    printf("----------------------------------------------------------------------------\n");
                }
            }
        }
        else if(opcao == 3) {
            printf("*** Calcular IMC ***\n");
            if(cadastros == 0) {
                printf("Nao ha pessoas cadastradas.\n");
                continue;
            }
            else {
                int id;
                int posicao = -1;
                printf("Informe o RG: ");
                scanf("%d", &id);
                for(i=0; i<cadastros; i++) {
                    if(id == rg[i]) {
                        posicao = i;
                        continue;
                    }

                }
                if(posicao == -1) {
                    printf("Pessoa nao localizada\n");
                    continue;
                }
                else {
                    imc[posicao] = peso[posicao] / (altura[posicao]*altura[posicao]);
                    printf("----------------------------------------------------------------------------\n");
                    printf("IMC para <%s>: %.2f\n", nome[posicao], imc[posicao]);
                    printf("----------------------------------------------------------------------------\n");
                }
            }
        }
    }
    return 0;
}
