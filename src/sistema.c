#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

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

// CADASTRO DE ALUGUEL

typedef struct CadastroAluguel {
    
    int id;
    char cliente[MAX];
    char telefone[MIN];
    char cpf[MIN];
    char cep[10];
    char estado[30];
    char cidade[30];
    char endereco[MED];
    char formaPagar[MED];
    int dia;
    int mes;
    int ano;
    float fatura;
    
} CadastroAluguel;

// ACERVO
typedef struct Acervo {

    CadastroLivro livros[MAX];
    int totalLivros;
    
} Acervo;

// ALUGUEIS
typedef struct Alugueis {

    CadastroAluguel alugueis[MAX];
    int totalAlugueis;

} Alugueis;

int prazoAluguel (int diaAluguel, int mesAluguel, int anoAluguel) {

    time_t agora = time(NULL);
    struct tm *dataAtual = localtime(&agora);

    struct tm dataAluguel = {0};
    dataAluguel.tm_mday = diaAluguel;
    dataAluguel.tm_mon = mesAluguel - 1;
    dataAluguel.tm_year = anoAluguel - 1900;

    dataAluguel.tm_mday += 30;
    mktime(&dataAluguel);

    time_t limite = mktime(&dataAluguel);
    double diferenca = difftime(agora, limite);

    return diferenca > 0;
}

int main(void) {

    system("cls");

    int i = 0;
    int OpMenu = 0;
    int OpBusca = 0;
    int ProximoId = 1;
    int ProximoLivroId = 1;
    int OpRemocao = 0;
    char PsqLivro[MED];
    char retorno;

    // PONTEIROS
    Acervo Acrv = {0};
    Acervo *acervo = &Acrv;

    CadastroLivro Clivro;
    CadastroLivro *cadastrolivro = &Clivro;

    CadastroAluguel Caluguel;
    CadastroAluguel *cadastroaluguel = &Caluguel;

    Alugueis Algs = {0};
    Alugueis *alugueis = &Algs;

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
        printf("  |[2]  Registrar Livro                      |\n");
        printf("  |[3]  Registrar Emprestimo                 |\n");
        printf("  |[4]  Acervo                               |\n");
        printf("  |[5]  Alugueis                             |\n");
        printf("  |[6]  Remover                              |\n");
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

            while(getchar() != '\n');

            continue;
        }

        while (getchar() != '\n');

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

                while (getchar() != '\n');

                if (OpBusca == 1) {

                    printf("Digite o nome do livro: ");
                    fgets(PsqLivro, sizeof(PsqLivro), stdin);

                    PsqLivro[strcspn(PsqLivro, "\n")] = '\0';

                    printf("%s\n", PsqLivro);
                }

                break;
                
            case 2:
                
                printf("////////// CADASTRO DE LIVROS ///////////\n");
                
                Acrv.livros[Acrv.totalLivros].id = ProximoId;
                ProximoId++;

                printf("| Nome do livro: ");
                fgets(Acrv.livros[Acrv.totalLivros].NomeLivro, MED, stdin);

                Acrv.livros[Acrv.totalLivros].NomeLivro[strcspn(Acrv.livros[Acrv.totalLivros].NomeLivro, "\n")] = '\0';

                printf("| Autor: ");
                fgets(Acrv.livros[Acrv.totalLivros].autor, MED, stdin);

                Acrv.livros[Acrv.totalLivros].autor[strcspn(Acrv.livros[Acrv.totalLivros].autor, "\n")] = '\0';
                
                printf("| Genero: ");
                fgets(Acrv.livros[Acrv.totalLivros].genero, 30, stdin);
                
                Acrv.livros[Acrv.totalLivros].genero[strcspn(Acrv.livros[Acrv.totalLivros].genero, "\n")] = '\0';
                
                printf("|Data de lancamento\n");
                
                printf("| Dia: ");
                scanf("%d", &Acrv.livros[Acrv.totalLivros].dia);
                
                printf("| Mes: ");
                scanf("%d", &Acrv.livros[Acrv.totalLivros].mes);
                
                printf("| Ano: ");
                scanf("%d", &Acrv.livros[Acrv.totalLivros].ano);
                
                printf("| Quantidade: ");
                scanf("%d", &Acrv.livros[Acrv.totalLivros].quantidade);

                printf("\nCadastro concluido com sucesso!!!\n");
                
                Acrv.totalLivros++;
                
                break;
                
            case 3: 

                printf("////////// CADASTRO DE ALUGUEIS ///////////\n");
                
                Algs.alugueis[Algs.totalAlugueis].id = ProximoLivroId;
                ProximoLivroId++;
                
                while(getchar() != '\n');

                printf("Nome: ");
                fgets(Algs.alugueis[Algs.totalAlugueis].cliente, MAX, stdin);
                
                Algs.alugueis[Algs.totalAlugueis].cliente[strcspn(Algs.alugueis[Algs.totalAlugueis].cliente, "\n")] = '\0';

                printf("Telefone: ");
                scanf("%d", &Algs.alugueis[Algs.totalAlugueis].telefone);

                while(getchar() != '\n');

                printf("CPF: ");
                fgets(Algs.alugueis[Algs.totalAlugueis].cpf, MIN stdin);

                Algs.alugueis[Algs.totalAlugueis].cpf[strcspn(Algs.alugueis[Algs.totalAlugueis].cpf, "\n")] = '\0';
                
                printf("CEP: ");
                fgets(Algs.alugueis[Algs.totalAlugueis].cep, 10 stdin);

                Algs.alugueis[Algs.totalAlugueis].cep[strcspn(Algs.alugueis[Algs.totalAlugueis].cep, "\n")] = '\0';
                
                while (getchar() != '\n');
                
                printf("Estado: ");
                fgets(Algs.alugueis[Algs.totalAlugueis].estado, MAX, stdin);
                
                Algs.alugueis[Algs.totalAlugueis].estado[strcspn(Algs.alugueis[Algs.totalAlugueis].estado, "\n")] = '\0';
                
                printf("Cidade: ");
                fgets(Algs.alugueis[Algs.totalAlugueis].cidade, MAX, stdin);
                
                Algs.alugueis[Algs.totalAlugueis].cidade[strcspn(Algs.alugueis[Algs.totalAlugueis].cidade, "\n")] = '\0';
                
                printf("Endereco: ");
                fgets(Algs.alugueis[Algs.totalAlugueis].endereco, MAX, stdin);
                
                Algs.alugueis[Algs.totalAlugueis].endereco[strcspn(Algs.alugueis[Algs.totalAlugueis].endereco, "\n")] = '\0';
                
                printf("Prazo da reserva, digite apenas numeros.");

                printf("Dia: ");
                scanf("%d", &Algs.alugueis[Algs.totalAlugueis].dia);

                printf("Mes: ");
                scanf("%d", &Algs.alugueis[Algs.totalAlugueis].mes);
                
                printf("Ano: ");
                scanf("%d", &Algs.alugueis[Algs.totalAlugueis].ano);
                
                printf("Valor total: ");
                scanf("%f", &Algs.alugueis[alugueis->totalAlugueis].fatura);
                
                while(getchar() != '\n');
                
                printf("Forma de pagamento: ");
                fgets(Algs.alugueis[Algs.totalAlugueis].formaPagar, MED, stdin);
                
                Algs.alugueis[Algs.totalAlugueis].formaPagar[strcspn(Algs.alugueis[Algs.totalAlugueis].formaPagar, "\n")] = '\0';
                
                printf("\nCadastro concluido com sucesso!!!\n");
                
                FILE *comprovante = fopen("comprovante.txt", "w");
                
                if (comprovante == NULL) {
                    
                    printf("Erro ao gerar comprovante!\n");
                    
                } else {
                    
                    fprintf(comprovante, "========== COMPROVANTE DE ALUGUEL ==========\n");
                    fprintf(comprovante, "========== SISTEMA DE BIBLIOTECA ==========\n" );
                    fprintf(comprovante, "Nome:        %s\n", Algs.alugueis[Algs.totalAlugueis].cliente);
                    fprintf(comprovante, "CPF:         %s\n", Algs.alugueis[Algs.totalAlugueis].cpf);
                    fprintf(comprovante, "ID:[%d]Livro:       %s\n", Acrv.livros[Acrv.totalLivros - 1].id, Acrv.livros[Acrv.totalLivros - 1].NomeLivro);
                    fprintf(comprovante, "Prazo:       %d/%d/%d\n", Algs.alugueis[Algs.totalAlugueis].dia, Algs.alugueis[Algs.totalAlugueis].mes, Algs.alugueis[Algs.totalAlugueis].ano);
                    fprintf(comprovante, "Taxa:        R$ %.2f\n", Algs.alugueis[Algs.totalAlugueis].fatura);
                    fprintf(comprovante, "============================================\n");
                    fclose(comprovante);
                    
                    printf("Comprovante gerado com sucesso!\n");
                    
                    Algs.totalAlugueis++;
                   
                  }
                    
                    break;

            case 4:
                    
                printf("<><><><><><><><><><> ACERVO <><><><><><><><><><>\n");
                    
                for (i = 0; i < Acrv.totalLivros; i++) {
                    
                printf("{ID[%d]. %s |Autor %s |Genero: %s |Lançamento %d/%d/%d |Quantidade: %d }\n", Acrv.livros[i].id, Acrv.livros[i].NomeLivro, Acrv.livros[i].autor,  Acrv.livros[i].genero,  Acrv.livros[i].dia, Acrv.livros[i].mes, Acrv.livros[i].ano,  Acrv.livros[i].quantidade);
                                           
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

            case 5:

                printf("<><><><><><><><><><> ALUGUEIS <><><><><><><><><><>\n");
                printf("Digite a data de hoje para a atualizacao dos alugueis");
                printf("Dia:");

                
                for(i = 0; i <= Algs.totalAlugueis; i++) {
                    
                    if(prazoAluguel(Algs.alugueis[i].dia, Algs.alugueis[i].mes, Algs.alugueis[i].ano)) {
                        
                        printf("|                                                     ><><>FORA DO PRAZO<><><                                                         |\n\n\n");
                        printf("|ID|NOME                                        |TELEFONE       |ID|LIVRO                                            |PRAZO   |Fatura    |");
                        printf("|%d|%99s|%d|%d|%49s|%d/%d/%d|R$%.2lf|",Algs.alugueis[Algs.totalAlugueis].id, Algs.alugueis[Algs.totalAlugueis].cliente, Algs.alugueis[Algs.totalAlugueis].telefone, Acrv.livros[Acrv.totalLivros].id, Acrv.livros[Acrv.totalLivros].NomeLivro, Algs.alugueis[Algs.totalAlugueis].dia, Algs.alugueis[Algs.totalAlugueis].mes, Algs.alugueis[Algs.totalAlugueis].ano, Algs.alugueis[Algs.totalAlugueis].fatura);
                        
                    } else {
                        
                        printf("|                                                     ><><>DENTRO DO PRAZO<><><                                                       |\n\n\n");
                        printf("|ID|NOME                                        |TELEFONE       |ID|LIVRO                                            |PRAZO   |Fatura    |");
                        printf("|%d|%99s|%d|%d|%49s|%d/%d/%d|R$%.2lf|",Algs.alugueis[Algs.totalAlugueis].id, Algs.alugueis[Algs.totalAlugueis].cliente, Algs.alugueis[Algs.totalAlugueis].telefone, Acrv.livros[Acrv.totalLivros].id, Acrv.livros[Acrv.totalLivros].NomeLivro, Algs.alugueis[Algs.totalAlugueis].dia, Algs.alugueis[Algs.totalAlugueis].mes, Algs.alugueis[Algs.totalAlugueis].ano, Algs.alugueis[Algs.totalAlugueis].fatura);
                        
                    }

                    break;
                }

            case 6:

                printf("O que deseja deletar?\n");
                printf("[1].Livro.\n");
                printf("[2].Aluguel.\n");
                printf(": \n");
                scanf("%d", &OpRemocao);

                int OpID;
                char OpCpf[15];

                
                if (OpRemocao = 1) {

                    printf("Digite o ID do livro que deseja remover: ");
                    scanf("%d", &OpID);

                    for (i = 0; i < Acrv.totalLivros; i++) {

                        if (Acrv.livros[i].id == OpID) {

                            Acrv.livros[i] = Acrv.livros[Acrv.totalLivros - 1];
                            Acrv.totalLivros--;

                            printf("Livro removido com sucesso!\n");

                            break;
                         } 
                    }
                }

                if (OpRemocao = 2) {

                    printf("Digite o Cpf do alguel que deseja remover: ");
                    scanf("%d", OpCpf);

                    for (i = 0; i < Algs.totalAlugueis; i++) {

                        if (Algs.alugueis[i].cpf == OpCpf) {

                            Algs.alugueis[i] = Algs.alugueis[Algs.totalAlugueis - 1];
                            Algs.totalAlugueis--;

                            printf("Aluguel removido com sucesso!\n");

                            break;
                        }
    
                    }
                }
        }

   } while (OpMenu != 0);
    
    return 0;
}