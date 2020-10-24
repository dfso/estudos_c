//*******************************************
//alunos:
//Elias Cardoso / Matricula 2028488
//Denison Fabio / Matricula 2022430
//*******************************************

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int loop = 10;               // numero de cadastros
    char marca[loop][20];
    char modelo[loop][20];
    char placa[loop][8];
    char cor[loop][20];
    char temp;                  // necessario para limpar o buffer
    int ano_fabricacao[loop];
    int i;

    printf("............................................................\n");
    printf("\t\t*** Bem-vindo a xpt veiculos ***\n");
    printf("\t\t\tCadastro de carros\n");
    printf("............................................................\n");
    for(i=0; i<loop; i++)
    {
        printf("Informe a *marca* do veiculo #%d: ", i+1);
        fflush(stdin);
        gets(marca[i]);
        
        printf("Informe o *modelo* do veiculo #%d: ", i+1);
        fflush(stdin);
        gets(modelo[i]);

        printf("Informe a *placa* do veiculo #%d: ", i+1);
        fflush(stdin);
        gets(placa[i]);

        printf("Informe a *cor* do veiculo #%d: ", i+1);
        fflush(stdin);
        gets(cor[i]);

        printf("Informe o *ano de fabricacao* do veiculo #%d: ", i+1);
        fflush(stdin);
        scanf("%d", &ano_fabricacao[i]);
        scanf("%c", &temp);    // limpa o buffer
        printf("............................................................\n");
    }

    printf("\n\n");

    printf("____________________________________________________________\n");
    printf("Relatorios\n");
    printf("____________________________________________________________\n");
    printf("............................................................\n");
    printf("carros novos [ano 2020]\n");
    printf("............................................................\n");
    for(i=0; i<loop; i++)
    {
        if(ano_fabricacao[i] == 2020)
        {
            printf("marca: %s\n", marca[i]);
            printf("modelo: %s\n", modelo[i]);
            printf("placa: %s\n", placa[i]);
            printf("cor: %s\n", cor[i]);
            printf("ano de fabricacao: %d\n", ano_fabricacao[i]);
            printf("____________________________________________________________\n");
        }
    }

    printf("\n\n");

    printf("............................................................\n");
    printf("carros seminovos [ultimos 5 anos]\n");
    printf("............................................................\n");
    for(i=0; i<loop; i++)
    {
        if(2020 - ano_fabricacao[i] <= 5 && 2020 - ano_fabricacao[i] > 0)
        {
            printf("marca: %s\n", marca[i]);
            printf("modelo: %s\n", modelo[i]);
            printf("placa: %s\n", placa[i]);
            printf("cor: %s\n", cor[i]);
            printf("ano de fabricacao: %d\n", ano_fabricacao[i]);
            printf("____________________________________________________________\n");
        }
    }

    printf("\n\n");

    printf("............................................................\n");
    printf("carros antigos [entre 2000 ate 2014]\n");
    printf("............................................................\n");
    for(i=0; i<loop; i++)
    {
        if(ano_fabricacao[i] > 2000 && ano_fabricacao[i] < 2015)
        {
            printf("marca: %s\n", marca[i]);
            printf("modelo: %s\n", modelo[i]);
            printf("placa: %s\n", placa[i]);
            printf("cor: %s\n", cor[i]);
            printf("ano defabricacao: %d\n", ano_fabricacao[i]);
            printf("____________________________________________________________\n");
        }
    }

    return 0;
}
