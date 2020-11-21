#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Questao {
    char enunciado[100];
    char alternativas[4][100];
    int resposta;
} Questao;

int main()
{
    int i, j, resposta;
    int qtd_questoes = 4;
    int corretas = 0, incorretas = 0;
    Questao logica[5];
    strcpy(logica[0].enunciado, "Qual operador retorna o resto de uma divisao?\n");
    strcpy(logica[0].alternativas[0], "1) &\n");
    strcpy(logica[0].alternativas[1], "2) !\n");
    strcpy(logica[0].alternativas[2], "3) /\n");
    strcpy(logica[0].alternativas[3], "4) %\n");
    logica[0].resposta = 3;

    strcpy(logica[1].enunciado, "Exemplo VALIDO de nomeacao de variavel:\n");
    strcpy(logica[1].alternativas[0], "1) 2par\n");
    strcpy(logica[1].alternativas[1], "2) num1\n");
    strcpy(logica[1].alternativas[2], "3) nome funcionario\n");
    strcpy(logica[1].alternativas[3], "4) @email\n");
    logica[1].resposta = 1;

    strcpy(logica[2].enunciado, "Biblioteca padrao de entrada/saida:\n");
    strcpy(logica[2].alternativas[0], "1) <stdio.h>\n");
    strcpy(logica[2].alternativas[1], "2) <io.h>\n");
    strcpy(logica[2].alternativas[2], "3) <input.h>\n");
    strcpy(logica[2].alternativas[3], "4) <stdlib.h>\n");
    logica[2].resposta = 0;

    strcpy(logica[3].enunciado, "E' uma estrutura de repeticao:\n");
    strcpy(logica[3].alternativas[0], "1) for(;;)\n");
    strcpy(logica[3].alternativas[1], "2) if()\n");
    strcpy(logica[3].alternativas[2], "3) system()\n");
    strcpy(logica[3].alternativas[3], "4) fflush()\n");
    logica[3].resposta = 0;



    printf("--- LINGUAGEM DE PROGRAMACAO ---\n");
    for(i=0; i<4; i++) {
        printf("%s", logica[i].enunciado);
        for(j=0; j<4; j++)
            printf("%s", logica[i].alternativas[j]);
        printf(">> ");
        scanf("%d", &resposta);
        printf("--------------------\n");
        if(resposta-1 == logica[i].resposta) {
            printf("ACERTOU!\n");
            corretas++;
        }
        else {
            printf("ERROU!\n");
            incorretas++;
        }
        printf("--------------------\n");
    }

    printf("Total de respostas CORRETAS:   %d [%.2f%%]\n", corretas, (float)corretas/(float)qtd_questoes*100);
    printf("Total de respostas INCORRETAS: %d [%.2f%%]\n", incorretas, (float)incorretas/(float)qtd_questoes*100);

    return 0;
}
