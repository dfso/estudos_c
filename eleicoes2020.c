#include <stdio.h>
#include <stdlib.h>

// biblioteca usada para manipular strings
#include <string.h>

// usa a funcao sleep() dessa biblioteca para pausar o programa
#include <windows.h>

int main()
{
    // voto lido do eleitor
    int voto;

    // votos que nao sao nulos ou em branco
    int votos_validos;

    // candidatos cadastrados no sistema
    char candidatos[5][80];

    // candidato primeiro_colocado
    char primeiro_colocado[80];

    // nome do candidato em 2° lugar
    char segundo_colocado[80];

    // copia o nome dos candidatos para o vetor de candidatos
    strcpy(candidatos[0], "Tiririca");
    strcpy(candidatos[1], "Tirulipa");
    strcpy(candidatos[2], "Didi");
    strcpy(candidatos[3], "NULO");
    strcpy(candidatos[4], "EM BRANCO");

    // contagem de votos de cada candidato
    int qtd_votos[5];

    // necessario para calcular quem obteve mais votos
    int maior_voto = 0;

    // calcula o segundo lugar
    int segundo_lugar = 0;

    // percentual de votos do candidato
    float percentual;

    //numero de eleitores. float para calcular o percentual 
    float eleitores = 10;

    // usado nas iteracoes do loop for
    int i, j;

    // confirma o voto do eleitor
    int confirma;

    // zera a contagem de votos para cada candidato
    for(i=0; i<5; i++)
        qtd_votos[i] = 0;

    // loop para a leitura de votos dos eleitores
    for(i=0; i<eleitores; i++) {
        // limpa a tela do console
        system("cls");
        printf("---------------JUSTICA ELEITORAL - VOTA MANAUS---------------\n\n");
        printf("Insira o numero do seu candidato ou [1]NULO [2]EM BRANCO\n>> ");
        scanf("%d", &voto);

        if(voto == 1) {
            // voto NULO
            qtd_votos[3] += 1;
            printf("VOTO COMPUTADO\n");
            printf(">>>FIM<<<\n");
            // pausa por 1 segundo
            sleep(1);
        }
        else if(voto == 2) {
            // voto EM BRANCO
            qtd_votos[4] += 1;
            printf("VOTO COMPUTADO\n");
            printf(">>>FIM<<<\n");
            sleep(1);
        }
        else if(voto == 1212) {
            printf("Voce esta votando:\n\n");
            printf("\tCandidato: << Tiririca >>\n\tPartido: Palhacos Unidos do Brasil\n\n");
            printf("\tConfirma? [1]SIM\t[2]Corrige\n>> ");
            scanf("%d", &confirma);

            if(confirma == 1) {
                qtd_votos[0] += 1;
                printf("VOTO COMPUTADO\n");
                printf(">>>FIM<<<\n");
                sleep(1);
            }
            // decrementa o iterador e retorna ao loop
            else {
                i-=1;
                continue;
            }
        }
        else if(voto == 1313) {
            printf("Voce esta votando:\n\n");
            printf("\tCandidato: << Tirulipa >>\n\tPartido: Totol Zorra\n\n");
            printf("\tConfirma? [1]SIM\t[2]Corrige\n>> ");
            scanf("%d", &confirma);

            if(confirma == 1) {
                qtd_votos[1] += 1;
                printf("VOTO COMPUTADO\n");
                printf(">>>FIM<<<\n");
                sleep(1);
            }
            else {
                i-=1;
                continue;
            }
        }
        else if(voto == 2424) {
            printf("Voce esta votando:\n\n");
            printf("\tCandidato: << DIDI >>\n\tPartido: Trapalheiros nacionais\n\n");
            printf("Confirma? [1]SIM\t[2]CORRIGE\n>> ");
            scanf("%d", &confirma);

            if(confirma == 1) {
                qtd_votos[2] += 1;
                printf("VOTO COMPUTADO\n");
                printf(">>>FIM<<<\n");
                sleep(1);
            }
            else {
                i-=1;
                continue;
            }
        }
        else {
            printf("Numero Invalido!\n");
            printf("ANULAR voto? [1]SIM\t[2]CORRIGE\n>> ");
            scanf("%d", &confirma);

            if(confirma == 1) {
                // voto NULO
                qtd_votos[3] +=1;
                printf("VOTO COMPULADO\n");
                printf(">>>FIM<<<\n");
                sleep(1);
            }
            else {
                i-=1;
                continue;
            }
        }
    }

    // calcula os votos validos
    votos_validos = 10 - qtd_votos[3] - qtd_votos[4];

    // verifica o primeiro_colocado
    for(i=0; i<3; i++)
        if(qtd_votos[i] > maior_voto) {
            maior_voto = qtd_votos[i];
            // edita o nome do 1o colocado
            strcpy(primeiro_colocado, candidatos[i]);
        }


    // verifica o 2º colocado
    for(i=0; i<3; i++) {
        if(strcmp(primeiro_colocado, candidatos[i]) == 0)
            continue;
        else if(qtd_votos[i] <= maior_voto && qtd_votos[i] > segundo_lugar){
            segundo_lugar = qtd_votos[i];
            // edita o nome do 2o colocado
            strcpy(segundo_colocado, candidatos[i]);
        }
    }
    
    system("cls");
    printf("---------------RESULTADO DAS ELEICAO---------------\n");
    // se o 1° colocado nao tem 50% + 1 do total de votos validos
    if(maior_voto < ((float)votos_validos/2)+1)
        printf("Havera 2o turno entre os candidatos <<%s>> e <<%s>>\n\n", primeiro_colocado, segundo_colocado);

    else
        printf("\n\nCandidato eleito: >>>>>%s<<<<<\n\n", primeiro_colocado);

    for(i=0; i<3; i++) {
        percentual = qtd_votos[i] / (float)votos_validos * 100;
        printf("Votos para %10s:\t%2d \t%% dos votos validos [%4.2f%%]\n", candidatos[i], qtd_votos[i], percentual);
    }
    printf("Total de votos NULOS:.....%4d, [%4.2f%%]\n", qtd_votos[3], qtd_votos[3]/eleitores*100);
    printf("Total de votos EM BRANCO:.%4d, [%4.2f%%]\n", qtd_votos[4], qtd_votos[4]/eleitores*100);
    printf("---------------RESULTADO DAS ELEICAO---------------\n");
    return 0;
}
