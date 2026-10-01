#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define MED 50
#define MIN 15

// CADASTRO DO LIVRO
typedef struct CadastroLivro {
    int id;
    char NomeLivro[MED];
    char autor[MED];
    char genero[30];
    int dia;
    int mes;
    int ano;
    int quantidade;
} CadastroLivro;

// ACERVO
typedef struct Acervo {
    CadastroLivro livros[MAX];
    int totalLivros;
} Acervo;

// PESQUISA
typedef struct Pesquisa {
    char cliente[MAX];
    char NomeLivro[MED];
    char autor[MED];
} Pesquisa;

// ALUGUEIS
typedef struct Alugueis {
    char cliente[MAX];
    char NomeLivro[MED];
    int prazo;
} Alugueis;

// REMOÇÃO
typedef struct Remocao {
    char cliente[MAX];
    char NomeLivro[MED];
    char genero[30];
    char autor[MED];
} Remocao;

// CADASTRO DE ALUGUEL
typedef struct CadastroAluguel {
    char cliente[MAX];
    char telefone[15];
    char cpf[15];
    char cep[10];
    char estado[30];
    char cidade[30];
    char endereco[MED];
    int prazo;
} CadastroAluguel;

int main(void) {
    system("cls");

    int i = 0;
    int OpMenu = 0;
    int OpBusca = 0;
    int ProximoId = 1;
    char PsqLivro[MED];
    char retorno;

    // PONTEIROS
    CadastroLivro Clivro;
    CadastroLivro *cadastrolivro = &Clivro;

    Acervo Acrv = {0};
    Acervo *acervo = &Acrv;

    Pesquisa Psq;
    Pesquisa *pesquisa = &Psq;

    Alugueis Algs;
    Alugueis *alugueis = &Algs;

    Remocao Rmc;
    Remocao *remocao = &Rmc;

    CadastroAluguel Caluguel;
    CadastroAluguel *cadastroaluguel = &Caluguel;

    do {
        printf("  +------------------------------------------+\n");
        printf("  |                                          |\n");
        printf("  |               BIBLIOTECA                 |\n");
        printf("  |        Sistema de Gerenciamento          |\n");
        printf("  |                                          |\n");
        printf("  +------------------------------------------+\n");
        printf("  |                                          |\n");
        printf("  |                                          |\n");
        printf("  |[1]  Buscar                               |\n");
        printf("  |[2]  Acervo                               |\n");
        printf("  |[3]  Registrar Livro                      |\n");
        printf("  |[4]  Registrar Emprestimo                 |\n");
        printf("  |[5]  Emprestimos                          |\n");
        printf("  |[6]  Atrasos                              |\n");
        printf("  |                                          |\n");
        printf("  |[0]  Sair                                 |\n");
        printf("  |                                          |\n");
        printf("  |                                          |\n");
        printf("  |                                          |\n");
        printf("  |                                          |\n");
        printf("  +------------------------------------------+\n");

        printf("\n  Opcao: ");

        if (scanf("%d", &OpMenu) != 1) {
            printf("Erro! Utilize apenas numeros inteiros entre 0 e 6\n");
            while (getchar() != '\n');
            continue;
        }

        if (OpMenu < 0 || OpMenu > 6) {
            printf("Erro! Escolha um numero entre 0 e 6\n");
            continue;
        }

        switch (OpMenu) {

            case 1:
                printf("[1].Livro\n");
                printf("[2].Autor\n");
                printf("[3].Tema\n");
                printf("[4].Cliente\n");

                scanf("%d", &OpBusca);

                if (OpBusca == 1) {
                    printf("Digite o nome do livro: ");

                    getchar();

                    fgets(PsqLivro, sizeof(PsqLivro), stdin);

                    PsqLivro[strcspn(PsqLivro, "\n")] = '\0';

                    printf("%s\n", PsqLivro);
                }

                break;

            case 2:
                printf("<><><><><><><><><><> ACERVO <><><><><><><><><><>\n");

                for (i = 0; i < Acrv.totalLivros; i++) {
                    printf("{ID[%d]. %s |Autor %s |Genero: %s |Lançamento %d/%d/%d |Quantidade: %d }\n",
                        Acrv.livros[i].id,
                        Acrv.livros[i].NomeLivro,
                        Acrv.livros[i].autor,
                        Acrv.livros[i].genero,
                        Acrv.livros[i].dia,
                        Acrv.livros[i].mes,
                        Acrv.livros[i].ano,
                        Acrv.livros[i].quantidade);
                }

                do {
                    printf("Deseja retornar ao menu? [S/N]\n");
                    scanf(" %c", &retorno);

                    if (retorno != 'S' && retorno != 'N') {
                        printf("Erro! Digite apenas S ou N\n");
                        while (getchar() != '\n');
                        continue;
                    }

                } while (retorno != 'S' && retorno != 'N');

                break;

            case 3:
                printf("////////// CADASTRO DE LIVROS ///////////\n");

                Acrv.livros[Acrv.totalLivros].id = ProximoId;
                ProximoId++;

                printf("| Nome do livro: ");

                getchar();

                fgets(Acrv.livros[Acrv.totalLivros].NomeLivro, MED, stdin);

                Acrv.livros[Acrv.totalLivros].NomeLivro[
                    strcspn(Acrv.livros[Acrv.totalLivros].NomeLivro, "\n")
                ] = '\0';

                printf("| Autor: ");

                fgets(Acrv.livros[Acrv.totalLivros].autor, MED, stdin);

                Acrv.livros[Acrv.totalLivros].autor[
                    strcspn(Acrv.livros[Acrv.totalLivros].autor, "\n")
                ] = '\0';

                printf("| Genero: ");

                fgets(Acrv.livros[Acrv.totalLivros].genero, 30, stdin);

                Acrv.livros[Acrv.totalLivros].genero[
                    strcspn(Acrv.livros[Acrv.totalLivros].genero, "\n")
                ] = '\0';

                printf("|Data de lancamento\n");

                printf("| Dia: ");
                scanf("%d", &Acrv.livros[Acrv.totalLivros].dia);

                printf("| Mes: ");
                scanf("%d", &Acrv.livros[Acrv.totalLivros].mes);

                printf("| Ano: ");
                scanf("%d", &Acrv.livros[Acrv.totalLivros].ano);

                printf("| Quantidade: ");
                scanf("%d", &Acrv.livros[Acrv.totalLivros].quantidade);

                Acrv.totalLivros++;

                break;
        }

    } while (OpMenu != 0);

    return 0;
}