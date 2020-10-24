#include <stdio.h>
#include <ncurses.h>

int main()
{
    initscr();
    refresh();
    char login_admin[] = "admin";
    char pass_admin[] = "admin";

    struct Funcionario {
        char nome[100];
        char matricula[10];
        char cargo[20];
    };

    struct Animal {
        char nome[80];
        char raca[36];
        char classificacao[36];
        char nome_dono[100];
        char telefone_dono[12];
        char endereco_dono[100];
    };

    struct Produto {
        char nome[100];
        char validade[12];
        float quantidade;
        float valor;
    };

    struct Servico {
        char nome[100];
        float tempo_sevico;
        float valor;
    };

    struct Agenda_servico {
        struct Servico servico;
        char dia[2];
        char horario[20];
        float valor_total;
    };


    struct Funcionario funcionario;
    struct Animal animal;
    struct Produto produto;
    struct Servico service;
    struct Agenda_servico agenda;

    printw("Cadastro de funcionarios\n");
    printw("Nome do funconario: ");
    scanw("%[^\n]s", funcionario.nome);
    printw("Matricula do funconario: ");
    scanw("%[^\n]s", funcionario.matricula);
    printw("Cargo do funconario: ");
    scanw("%[^\n]s", funcionario.cargo);
    getch();
    endwin();
    return 0;
}
