#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

    //CADASTRO DO LIVRO

typedef struct CadastroLivro {

    char NomeLivro[50];
    char autor[50];
    char genero[30];
    char lancamento;
    int quantidade;

    struct CadastroLivro  CLivro[MAX];

} CadastroLivro;

  //ACERVO

typedef struct Acervo {

    char livros[MAX];

    struct Acervo  Acrv;

} Acervo;

    //PESQUISA
    
typedef struct Pesquisa {

    char cliente[MAX];
    char NomeLivro[50];
    char autor[50];

    struct Pesquisa  PsqLivro;

} Pesquisa;

  //ALUGUEIS

typedef struct Alugueis {

    char cliente[MAX];
    char NomeLivro[50];
    int prazo;

    struct Alugueis  alugueis[MAX];

} Alugueis;

  //REMOÇÃO

typedef struct Remocao {

    char cliente[MAX];
    char NomeLivro[50];
    char genero[30];
    char autor[50];

    struct Remocao  Del;
    
} Remocao;    

  //CADASTRO DE ALUGUEL

typedef struct CadastroAluguel {

    char cliente[MAX];
    char telefone[15];
    char cpf[15];
    char cep[10];
    char estado[30];
    char cidade[30];
    char endereco [50];
    int prazo;

    struct CadastroAluguel CAluguel[MAX];

} CadastroAluguel;


int main(void) {

    system ("cls");
    int i = 0;
    int OpMenu = 0;
    int OpBusca = 0;
    char PsqLivro[50];

    
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
    scanf("%d", &OpMenu);


do{

    switch (OpMenu) {

           
        case 1:
            
           printf("[1].Livro\n");
           printf("[2].Autor\n");
           printf("[3].Tema\n");
           printf("[4].Cliente\n");
           scanf("%d", &OpBusca);

           if (OpBusca == 1){

            printf("Digite o nome do livro: ");
            fgets(PsqLivro, sizeof(PsqLivro), stdin);

            if (strcmp(PsqLivro, Acrv[i]) ==0) {
                
                printf("%49s", )
            }

    }

}

} 

}