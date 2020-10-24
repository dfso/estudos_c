#include <stdio.h>

int main()
{
    int a, b;
    int opt;

    printf("########## Calculadora ##########\n");
    printf("########## BEM-VINDO! ###########\n");
    printf("Que operacao deseja realizar? Digite uma opcao:\n");
    printf("[1] SOMA\n[2] SUBTRACAO\n[3] MULTIPLICACAO\n[4] DIVISAO: ");
    scanf("%d", &opt);

    if(opt == 1) {
        printf("*** SOMA ***\n");
        printf("Digite um numero: ");
        scanf("%d", &a);
        printf("Digite outro numero: ");
        scanf("%d", &b);
        printf("resultado-> %d + %d e': %d\n", a, b, (a+b));
    } else if(opt == 2) {
        printf("*** SUBTRACAO ***\n");
        printf("Digite um numero: ");
        scanf("%d", &a);
        printf("Digite outro numero: ");
        scanf("%d", &b);
        printf("resultado-> %d - %d e': %d\n", a, b, (a-b));
    } else if(opt == 3) {
        printf("*** MULTIPLICACAO ***\n");
        printf("Digite um numero: ");
        scanf("%d", &a);
        printf("Digite outro numero: ");
        scanf("%d", &b);
        printf("resultado-> %d x %d e': %d\n", a, b, (a*b));
    }else if(opt == 4) {
        float a, b;
        printf("*** DIVISAO ***\n");
        printf("Digite um numero: ");
        scanf("%f", &a);
        printf("Digite outro numero: ");
        scanf("%f", &b);
        if(b == 0)
            printf("Divisao por ZERO nao permitida!\n");
        else
            printf("resultado-> %.2f ÷ %.2f e': %.2f\n", a, b, (a/b));
    }
    else
        printf("Opcao invalida!\n");

    printf("######## FIM da EXECUCAO ########\n");
}
