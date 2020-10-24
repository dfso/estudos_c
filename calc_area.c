#include <stdio.h>
#include <math.h>   // necessario para calcular a potencia a^n
#include <stdlib.h>

int main()
{
    int opt;    // guarda a opcao do tipo de terreno
    float area;
    printf("-----------------------------------------------------------------\n");
    printf("Bem-vindo. Vamos Calcular a area do tipo de terreno especificado.\n");
    printf("-----------------------------------------------------------------\n");
    printf("Escolha um numero que representa o tipo de terreno abaixo >>\n");
    printf("[1] quadrado\n[2] circular\n[3] triangular\n[4] retangular\n:");
    scanf("%d", &opt);

    if(opt == 1) {
        float lado;
        printf("-----------------------------------------------------------------\n");
        printf("<<< Terreno Quadrado >>>\n");
        printf("Qual a medida do lado (em metros)? ");
        scanf("%f", &lado);

        area = lado * lado;

        printf("-----------------------------------------------------------------\n");
        printf("Area calculada: %.2fm2\n", area);
    }
    else if(opt == 2) {
        float pi = 3.14159;
        float raio;
        printf("-----------------------------------------------------------------\n");
        printf("<<< Terreno Circular >>>\n");
        printf("Informe o comprimento do raio (em metros): ");
        scanf("%f", &raio);

        area = pi * raio * raio;
        printf("-----------------------------------------------------------------\n");
        printf("Area calculada: %.2fm2\n", area);
    }
    else if(opt == 3) {
        float lado;
        printf("-----------------------------------------------------------------\n");
        printf("<<< Terreno Triangular >>>\n");
        printf("Qual a medida do lado do triangulo (em metros)? ");
        scanf("%f", &lado);

        area = (lado * lado * pow(3, 0.5))/4;
        printf("-----------------------------------------------------------------\n");
        printf("Area calculada: %.2fm2\n", area);
    }
    else if(opt == 4) {
        float comprimento, largura;
        printf("-----------------------------------------------------------------\n");
        printf("<<< Terreno Retangular >>>\n");
        printf("Qual a medida do comprimento do terreno (em metros)? ");
        scanf("%f", &comprimento);
        printf("Qual a medida da largura do terreno (em metros)? ");
        scanf("%f", &largura);

        area = comprimento * largura;
        printf("-----------------------------------------------------------------\n");
        printf("Area calculada: %.2fm2\n", area);
    }
    else {
        printf("-----------------------------------------------------------------\n");
        printf("Opcao invalida!\n");
    }
    printf("------------------------PROGRAMA TERMINADO-----------------------\n");
    return 0;
}
