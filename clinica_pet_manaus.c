#include <stdio.h>
#include <stdlib.h>


int menu(int);


int main()
{
    int tam = 2;
    int login_admin = 123;
    int senha_admin = 123;
    int is_admin = 0;       // identificar se o admin fez login

    char nome_funci[tam][100];
    char matricula_funci[tam][10];
    char cargo_funci[tam][20];
    int funci_qtd = 0;

    char animal_nome[tam][80];
    char animal_raca[tam][36];
    char animal_classificacao[tam][36];
    char animal_nome_dono[tam][100];
    char animal_telefone_dono[tam][12];
    char animal_endereco_dono[tam][100];
    int animal_qtd = 0;

    char prod_nome[tam][100];
    char prod_validade[tam][12];
    float prod_quantidade[tam];
    float prod_valor[tam];
    int prod_qtd = 0;

    char servico_nome[tam][100];
    float servico_tempo[tam];
    float servico_valor[tam];
    int servico_qtd = 0;

    char agenda_servico_dia[tam][2];
    float tempo_total = 0;
    float valor_total = 0;
    char agenda_servico_horario[tam][20];
    char descricao_servicos_agendados[tam][150];
    int total_servicos_agendados = 0;

    int i;
    char opt;
    char temp;

    system("clear");
    printf("________________________________________________________________\n");
    printf("-----------------BEM-VINDO A CLINICA PET MANAUS-----------------\n");
    printf("________________________________________________________________\n");
    printf("Digite [1] para realizar login ou outro valor para entrar com a [matricula]: ");
    scanf("%c", &opt);

    if(opt == '1') {
        int login;
        int senha;
        printf("digite o login: ");
        scanf("%d", &login);
        printf("digite a senha: ");
        scanf("%d", &senha);
        scanf("%c", &temp);

        if(login == login_admin && senha == senha_admin) {
            is_admin = 1;
            system("clear");
            printf("_____________________________________________________\n");
            printf(">>>>>>>>>>>>>>>>>>>> Ola' ADMIN! <<<<<<<<<<<<<<<<<<<<\n");
            printf("_____________________________________________________\n");
            getchar();
        }
        else {
            printf("login ou senha invalidos!!!\n\n");
            main();
        }
    }
    else {
        int matricula;
        printf("digite sua matricula: ");
        scanf("%d", &matricula);
        scanf("%c", &temp);
        system("clear");
        printf("_______________________________________________________________\n");
        printf(">>>>>>>>>>>>>>>>>>>> Ola' funcinario [%d]! <<<<<<<<<<<<<<<<<<<<\n", matricula);
        printf("_______________________________________________________________\n");
        getchar();
    }
    for(;;) {

        opt = menu(is_admin);
        if(opt == 1) {
            printf("\n<<<<<<<<<<<<<<<<<<<< Cadastrar funcionarios >>>>>>>>>>>>>>>>>>>>\n");
            printf("Nome do funcionario: ");
            gets(nome_funci[funci_qtd]);
            printf("Matricula do funcionario: ");
            gets(matricula_funci[funci_qtd]);
            printf("Cargo do funcionario: ");
            gets(cargo_funci[funci_qtd]);
            funci_qtd += 1;
            printf("<<<<<<<<<<<<<<<<<<<< Fim do cadastro >>>>>>>>>>>>>>>>>>>>\n");
            getchar();
        }
        else if(opt == 2) {
            printf("\n<<<<<<<<<<<<<<<<<<<< Cadastrar animais >>>>>>>>>>>>>>>>>>>>\n");
            printf("Nome do animal: ");
            gets(animal_nome[animal_qtd]);
            printf("Raca do animal: ");
            gets(animal_raca[animal_qtd]);
            printf("Classificacao do animal: ");
            gets(animal_raca[animal_qtd]);
            printf("Nome do dono do animal: ");
            gets(animal_nome_dono[animal_qtd]);
            printf("Telefone do dono do animal: ");
            gets(animal_telefone_dono[animal_qtd]);
            printf("Endereco do dono do animal: ");
            gets(animal_endereco_dono[animal_qtd]);
            animal_qtd += 1;
            printf("<<<<<<<<<<<<<<<<<<<< Fim do cadastro >>>>>>>>>>>>>>>>>>>>\n");
            getchar();
        }
        else if(opt == 3) {
            printf("\n<<<<<<<<<<<<<<<<<<<< Cadastrar produtos >>>>>>>>>>>>>>>>>>>>\n");
            printf("Nome do produto: ");
            gets(prod_nome[prod_qtd]);
            printf("Quantidade do produto: ");
            gets(prod_quantidade[prod_qtd]);
            printf("Validade do produto: ");
            gets(prod_validade[prod_qtd]);
            printf("Valor do produto[R$]: ");
            scanf("%f", &prod_valor[prod_qtd]);
            scanf("%c", &temp);
            prod_qtd += 1;
            printf("<<<<<<<<<<<<<<<<<<<< Fim do cadastro >>>>>>>>>>>>>>>>>>>>\n");
            getchar();
        }
        else if(opt == 4) {
            printf("\n<<<<<<<<<<<<<<<<<<<< Cadastrar servicos >>>>>>>>>>>>>>>>>>>>\n");
            printf("Nome do servico: ");
            gets(servico_nome[servico_qtd]);
            printf("Tempo do servico[em minutos]: ");
            scanf("%f", &servico_tempo[servico_qtd]);
            scanf("%c", &temp);
            printf("Valor do servico[R$]: ");
            scanf("%f", &servico_valor[servico_qtd]);
            scanf("%c", &temp);
            servico_qtd += 1;
            printf("<<<<<<<<<<<<<<<<<<<< Fim do cadastro >>>>>>>>>>>>>>>>>>>>\n");
            getchar();
        }
        else if(opt == 5) {
            if(animal_qtd > 0 && servico_qtd > 0) {
                int id_animal, id_servico;
                printf("\n<<<<<<<<<<<<<<<<<<<< Agendar servico >>>>>>>>>>>>>>>>>>>>\n");
                printf("Selecione o ID do animal abaixo\n");
                for(i=0; i<animal_qtd; i++) {
                    printf(">>> ID[%d], [animal: %s], [dono: %s] <<<\n", i+1, animal_nome[i], animal_nome_dono[i]);
                }
                scanf("%d", &id_animal);
                scanf("%c", &temp);

                printf("Selecione o ID do servico abaixo\n");
                for(i=0; i<servico_qtd; i++) {
                    printf(">>> ID[%d], [servico: %s], [valor: R$ %.2f] <<<\n", i+1, servico_nome[i], servico_valor[i]);
                }
                scanf("%d", &id_servico);
                scanf("%c", &temp);

                tempo_total += servico_tempo[id_servico - 1];
                valor_total += servico_valor[id_servico - 1];

                printf("Informe o dia em que o servico sera' realizado [padrao dia/mes/ano]: ");
                gets(agenda_servico_dia[total_servicos_agendados]);

                printf("Informe o horario em que o servico sera' realizado [padrao 24hs]: ");
                gets(agenda_servico_horario[total_servicos_agendados]);

                total_servicos_agendados += 1;

                printf("<<<<<<<<<<<<<<<<<<<< Fim do agendamento >>>>>>>>>>>>>>>>>>>>\n");
                getchar();
            }
            else {
                printf("E' preciso cadastrar animais e servicos para efetuar agendamentos!\n");
                getchar();
                continue;
            }
        }
        else if(opt == 6) {
            printf("\n<<<<<<<<<<<<<<<<<<<< Gerar relatorio mensal >>>>>>>>>>>>>>>>>>>>\n");
            printf("\t* Quantidade de servicos realizados: %d\n", total_servicos_agendados);
            printf("\t* Tempo total dos servicos[em minutos]: %.2f\n", tempo_total);
            printf("\t* Valor total dos servicos[R$]: %.2f\n", valor_total);
            printf("<<<<<<<<<<<<<<<<<<<< Fim relatorio mensal >>>>>>>>>>>>>>>>>>>>\n");
            getchar();
        }
        else if(opt == 0) {
            printf("fechando o programa...\n\n");
            exit(0);
        }
        else {
            printf("!!!!!!!!!!!!!!!!!!!! Opcao invalida !!!!!!!!!!!!!!!!!!!!\n");
            getchar();
        }
    }   // for infinito
}   // main


int menu(int is_admin) {
    int opt;
    char temp;

    if(is_admin) {
        system("clear");
        printf("\n<<<<<<<<<<<<<<<<<<<< menu principal >>>>>>>>>>>>>>>>>>>>\n");
        printf("Digite um numero referente a funcao desejada:\n");
        printf("[1] cadastrar funcinario\n");
        printf("[2] cadastrar animal\n");
        printf("[3] cadastrar produto\n");
        printf("[4] cadastrar servico\n");
        printf("[5] agendar servico\n");
        printf("[6] gerar relatorio mensal\n");
        printf("[0] sair do programa\n");
        printf(">> ");
        scanf("%d", &opt);
        scanf("%c", &temp);
    }
    else {
        system("clear");
        printf("\n<<<<<<<<<<<<<<<<<<<< menu principal >>>>>>>>>>>>>>>>>>>>\n");
        printf("Digite um numero referente a funcao desejada:\n");
        printf("[2] cadastrar animal\n");
        printf("[5] agendar servico\n");
        printf("[0] sair do programa\n");
        printf(">> ");
        scanf("%d", &opt);
        scanf("%c", &temp);
    }
    return opt;
}
