#include <stdio.h>  // biblioteca padrao de entrada/saida
#include <stdlib.h> // biblioteca padrao do sistema

/* funcao para exibir o menu conforme o tipo de usuario*/
char menu(int);

/* funcao principal*/
int main()
{
    int tam = 2;                            // variavel que define o tamanho dos vetores e as repeticoes no loop
    int login_admin = 123;                  // o login do admin
    int senha_admin = 123;                  // a senha do admin
    int is_admin = 0;                       // identificar se o admin realizou login con sucesso

    char nome_funci[tam][100];              // vetor para o nome dos funcionarios
    char matricula_funci[tam][10];          // vetor para a matricula dos funcionarios 
    char cargo_funci[tam][20];              // vetor para o cargo dos funcionarios
    int funci_qtd = 0;                      // conta a quantidade de funcionarios cadastrados

    char animal_nome[tam][80];              // vetor para o nome dos animais
    char animal_raca[tam][36];              // vetor para a raca dos animais
    char animal_classificacao[tam][36];     // vetor para a classificacao dos animais
    char animal_nome_dono[tam][100];        // vetor para o nome do dono dos animais
    char animal_telefone_dono[tam][12];     // vetor para o telefone do dono dos animais
    char animal_endereco_dono[tam][100];    // vetor para o endereco do dono dos animais
    int animal_qtd = 0;                     // conta a quantidade de animais cadastrados

    char prod_nome[tam][100];               // vetor para o nome dos produtos
    char prod_validade[tam][12];            // vetor para a validade dos produtos
    float prod_quantidade[tam];             // vetor para a quantidade dos produtos
    float prod_valor[tam];                  // vetor para o valor dos produtos
    int prod_qtd = 0;                       // conta a quantidade de produtos cadastrados

    char servico_nome[tam][100];            // vetor para no nome dos servicos
    float servico_tempo[tam];               // vetor para o tempo dos servicos
    float servico_valor[tam];               // vetor para o valor dos servicos
    int servico_qtd = 0;                    // conta a quantidade de servicos cadastrados

    char agenda_servico_dia[tam][2];        // vetor para o dia do servico agendado
    float tempo_total = 0;                  // conta o tempo total dos servicos realizados
    float valor_total = 0;                  // conta o valor total dos servicos realizados
    char agenda_servico_horario[tam][20];   // vetor para o horario do servico agendado
    int total_servicos_agendados = 0;       // conta a quantidade total de servicos agendados

    int i;          // usado nos loops for
    char opt;       // guarda a opcao do usuario para realizar ou nao login
    char temp;      // guarda valor nao utilizado ao pressionar o "enter"

    system("clear");    // chama o comando 'cls' para limpar o console <Windows>

    /* obtem a opcao de entrar como admin ou funcionario*/
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

        // verifica login e senha do admin
        if(login == login_admin && senha == senha_admin) {
            is_admin = 1;   // autentica o admin
            system("clear");
            printf("_____________________________________________________\n");
            printf(">>>>>>>>>>>>>>>>>>>> Ola' ADMIN! <<<<<<<<<<<<<<<<<<<<\n");
            printf("_____________________________________________________\n");
            printf("pressione <enter>...");
            getchar(); // espera um <enter> do usuário
        }
        else {
            printf("login ou senha invalidos!!!\n\npressione <enter>...");
            getchar();
            main(); // reinicia o programa
        }
    }
    else {  // usuario entra com funcionalidades de funcionario apenas
        int matricula;
        printf("digite sua matricula: ");
        scanf("%d", &matricula);
        scanf("%c", &temp); // le valor nulo no buffer
        system("clear");
        printf("_______________________________________________________________\n");
        printf(">>>>>>>>>>>>>>>>>>>> Ola' funcinario [%d]! <<<<<<<<<<<<<<<<<<<<\n", matricula);
        printf("_______________________________________________________________\npressione <enter>...");
        getchar();
    }

    // loop do programa, exibindo o menu
    for(;;) {

        // a funcao menu retorna a opcao escolhida para a variavel opt
        opt = menu(is_admin);

        // as opcoes '1', '3', '4' e '6' sao exclusivas do admin
        // realiza o cadastro de funcionarios
        if(opt == '1' && is_admin) {
            printf("\n<<<<<<<<<<<<<<<<<<<< Cadastrar funcionarios >>>>>>>>>>>>>>>>>>>>\n");
            printf("Nome do funcionario: ");
            gets(nome_funci[funci_qtd]);
            printf("Matricula do funcionario: ");
            gets(matricula_funci[funci_qtd]);
            printf("Cargo do funcionario: ");
            gets(cargo_funci[funci_qtd]);
            funci_qtd += 1;
            printf("<<<<<<<<<<<<<<<<<<<< Fim do cadastro >>>>>>>>>>>>>>>>>>>>\npressione <enter>...");
            getchar();
        }
        // realiza o cadastro de animais
        else if(opt == '2') {
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
            printf("<<<<<<<<<<<<<<<<<<<< Fim do cadastro >>>>>>>>>>>>>>>>>>>>\npressione <enter>...");
            getchar();
        }
        // cadastra produtos
        else if(opt == '3' && is_admin) {
            printf("\n<<<<<<<<<<<<<<<<<<<< Cadastrar produtos >>>>>>>>>>>>>>>>>>>>\n");
            printf("Nome do produto: ");
            gets(prod_nome[prod_qtd]);
            printf("Quantidade do produto: ");
            scanf("%f", &prod_quantidade[prod_qtd]);
            scanf("%c", &temp);
            printf("Validade do produto: ");
            gets(prod_validade[prod_qtd]);
            printf("Valor do produto[R$]: ");
            scanf("%f", &prod_valor[prod_qtd]);
            scanf("%c", &temp);
            prod_qtd += 1;
            printf("<<<<<<<<<<<<<<<<<<<< Fim do cadastro >>>>>>>>>>>>>>>>>>>>\npressione <enter>...");
            getchar();
        }
        // cadastra servicos
        else if(opt == '4' && is_admin) {
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
            printf("<<<<<<<<<<<<<<<<<<<< Fim do cadastro >>>>>>>>>>>>>>>>>>>>\npressione <enter>...");
            getchar();
        }
        // agenda servicos cadastrados
        else if(opt == '5') {
            // e' preciso ter pelo menos 1 animal e 1 servico cadastrado para efetuar agendamento
            if(animal_qtd > 0 && servico_qtd > 0) {
                int id_animal, id_servico;
                printf("\n<<<<<<<<<<<<<<<<<<<< Agendar servico >>>>>>>>>>>>>>>>>>>>\n");
                printf("Selecione o ID do animal abaixo\n");    // exibe os animais cadastrados
                for(i=0; i<animal_qtd; i++) {
                    printf(">>> ID[%d], [animal: %s], [dono: %s] <<<\n", i+1, animal_nome[i], animal_nome_dono[i]);
                }
                scanf("%d", &id_animal);
                scanf("%c", &temp);

                printf("Selecione o ID do servico abaixo\n");   // exibe os servicos cadastrados
                for(i=0; i<servico_qtd; i++) {
                    printf(">>> ID[%d], [servico: %s], [valor: R$ %.2f] <<<\n", i+1, servico_nome[i], servico_valor[i]);
                }
                scanf("%d", &id_servico);
                scanf("%c", &temp);

                tempo_total += servico_tempo[id_servico - 1];   // soma o tempo do servico agendado
                valor_total += servico_valor[id_servico - 1];   // soma o valor do servico agendado

                printf("Informe o dia em que o servico sera' realizado [padrao dia/mes/ano]: ");
                gets(agenda_servico_dia[total_servicos_agendados]);

                printf("Informe o horario em que o servico sera' realizado [padrao 24hs]: ");
                gets(agenda_servico_horario[total_servicos_agendados]);

                total_servicos_agendados += 1;
                printf("<<<<<<<<<<<<<<<<<<<< Fim do agendamento >>>>>>>>>>>>>>>>>>>>\npressione <enter>...");
                getchar();
            }
            else {
                printf("E' preciso cadastrar animais e servicos para efetuar agendamentos!\npressione <enter>...");
                getchar();
                continue;   // retorna ao loop
            }
        }
        // exibe o relatorio mensal
        else if(opt == '6' && is_admin) {
            printf("\n<<<<<<<<<<<<<<<<<<<< Gerar relatorio mensal >>>>>>>>>>>>>>>>>>>>\n");
            printf("\t* Quantidade de servicos realizados: %d\n", total_servicos_agendados);
            printf("\t* Tempo total dos servicos[em minutos]: %.2f\n", tempo_total);
            printf("\t* Valor total dos servicos[R$]: %.2f\n", valor_total);
            printf("<<<<<<<<<<<<<<<<<<<< Fim relatorio mensal >>>>>>>>>>>>>>>>>>>>\npressione <enter>...");
            getchar();
        }
        // sai do programa
        else if(opt == '0') {
            printf("fechando o programa...\n\n");
            exit(0);
        }
        else {
            printf("!!!!!!!!!!!!!!!!!!!! Opcao invalida !!!!!!!!!!!!!!!!!!!!\npressione <enter>...");
            getchar();
        }
    }   // for
}   // main


/*
 * funcao que exibe o menu do programa
 * possui um parametro que identifica o tipo de usuario, admin ou nao
 * retorna um char, a opcao escolhida pelo usuario
 */
char menu(int is_admin) {
    char opt;
    char temp;

    // se o usuario e' o admin, exibe esse menu
    if(is_admin) {
        system("clear");
        printf("\n<<<<<<<<<<<<<<<<<<<< menu principal >>>>>>>>>>>>>>>>>>>>\n");
        printf("Digite um numero referente a funcao desejada:\n");
        printf("[1] cadastrar funcionario\n");
        printf("[2] cadastrar animal\n");
        printf("[3] cadastrar produto\n");
        printf("[4] cadastrar servico\n");
        printf("[5] agendar servico\n");
        printf("[6] gerar relatorio mensal\n");
        printf("[0] sair do programa\n");
        printf(">> ");
        scanf("%c", &opt);
        scanf("%c", &temp);
    }
    // menu para o funcionario nao admin
    else {
        system("clear");
        printf("\n<<<<<<<<<<<<<<<<<<<< menu principal >>>>>>>>>>>>>>>>>>>>\n");
        printf("Digite um numero referente a funcao desejada:\n");
        printf("[2] cadastrar animal\n");
        printf("[5] agendar servico\n");
        printf("[0] sair do programa\n");
        printf(">> ");
        scanf("%c", &opt);
        scanf("%c", &temp);
    }
    return opt;
}
