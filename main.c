//SAULO VICTOR BEZERAR



#include <stdio.h>
#include <stdlib.h>
#define Tam_lista 50

enum MENU_PRINCIPAL {MENU_CADASTRAR_LIVROS = 1, MENU_CONSULTA_POR_CODIGO, MENU_CONSULTA_DOADO, MENU_ALTERA, MENU_EXCLUIR};

typedef struct
{
	int Codigo;
    char Doado [1];
    char Obra [50];
    char Autor [50];
    char Editora [50];
    int Paginas;
}Livros;

typedef struct
{
	Livros Biomedicas [Tam_lista + 1];
	Livros Humanas [Tam_lista + 1];
	Livros Exatas[Tam_lista + 1];
}biblio;

//metodo cadastrar livros
void cadastrar (Livros * livros){

	printf("CADASTRAR LIVROS\n\n");
    printf("Digite o codigo de catalogacao: ");
    scanf("%d", &livros->Codigo);
    printf("Obra doada de aquisicao? s/n: ");
    scanf("%s", &livros->Doado);
    printf("Digite o nome da obra: ");
    scanf("%s", &livros->Obra);
    printf("Digite o nome do autor: ");
    scanf("%s", &livros->Autor);
    printf("Digite a editora: ");
    scanf("%s", &livros->Editora);
    printf("Digite o numero de paginas: ");
    scanf("%d", &livros->Paginas);
    printf("CADASTRO REALIZADO COM SUCESSO!!!\n\n");
    getchar();

}
//metodo exibir livros
void exibir (Livros * livros){

	printf("CONSULTA DE LIVROS\n\n");
    printf("Codigo: %d\n", livros->Codigo);
    printf("Doado: %s\n", livros->Doado);
    printf("Nome do livro: %s\n", livros->Obra);
    printf("Nome do autor: %s\n", livros->Autor);
    printf("Editora: %s\n", livros->Editora);
    printf("Numero de paginas: %d\n", livros->Paginas);
    getch();
}
//metodo alterar livros
void alterar(Livros * livros){


    printf("Digite o codigo de catalogacao: ");
    scanf("%d", &livros->Codigo);
    printf("Obra doada de aquisicao?: ");
    scanf("%s", &livros->Doado);
    printf("Digite o nome da obra: ");
    scanf("%s", &livros->Obra);
    printf("Digite o nome do autor: ");
    scanf("%s", &livros->Autor);
    printf("Digite a editora: ");
    scanf("%s", &livros->Editora);
    printf("Digite o numero de paginas: ");
    scanf("%d", &livros->Paginas);


    getchar();


}
//metodo excluir livros
void excluir(Livros * livros){

    livros->Codigo = "";
    livros->Doado[1] = "";
    livros->Obra[50]= "";
    livros->Autor[50] = "";
    livros->Editora[50] = "";
    livros->Paginas = "";
    printf("DADOS APAGAGOS COM SUCESSO!\n\n");

   }





int main(){

	biblio Biblioteca;
	int i, MENU_PRINCIPAL, opcao;

    memset(&Biblioteca, 0, sizeof(biblio));

    while(1){

        //system("cls");
        printf("    *===================================*\n");
        printf("    |           MENU PRINCIPAL          |\n");
        printf("    *-----------------------------------*\n");
        printf("1 - |Cadastrar livros                   |\n");
        printf("2 - |Consultar obra por codigo e area   |\n");
        printf("3 - |Consulta obras doadas de cada area |\n");
        printf("4 - |Alterar um registro                |\n");
        printf("5 - |Excluir um registro                |\n");
        printf("6 - |Sair                               |\n");
        printf("    *-----------------------------------*\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &MENU_PRINCIPAL);


            switch (MENU_PRINCIPAL)
            {
            case MENU_CADASTRAR_LIVROS:
                {
                //system("cls");
                printf("    *=======================================*\n");
                printf("    |       MENU CADASTRA LIVROS            |\n");
                printf("    *---------------------------------------*\n");
                printf("1 - |Cadastra livro de ciencias exatas      |\n");
                printf("2 - |Cadastra livro de ciencias humanas     |\n");
                printf("3 - |Cadastra livro de ciencias biomedicas  |\n");
                printf("4 - |Retornar ao menu principal             |\n");
                printf("    *---------------------------------------*\n\n");
                printf("Digite sua opcao: ");
                scanf("%d", &opcao);

                switch (opcao)
                    {
                    case 1:
                        for(i=0; i<Tam_lista; i++)
                            if (!Biblioteca.Exatas[i].Codigo)
                                break;
                        cadastrar(&Biblioteca.Exatas[i]);
                    break;
                    case 2:
                        for(i=0; i<Tam_lista; i++)
                            if (! Biblioteca.Humanas[i].Codigo)
                                break;
                        cadastrar (&Biblioteca.Humanas[i]);
                    break;
                    case 3:
                        for(i=0; i<Tam_lista; i++)
                            if (! Biblioteca.Biomedicas[i].Codigo)
                                break;
                        cadastrar (&Biblioteca.Biomedicas[i]);
                    break;
                }
                }
            break;
            case MENU_CONSULTA_POR_CODIGO:
                {
                int Novo_Codigo;
                //system("cls");
                printf("    *===================================*\n");
                printf("    | CONSULTA OBRAS POR CODIGO DA AREA |\n");
                printf("    *-----------------------------------*\n");
                printf("1 - |Exatas                             |\n");
                printf("2 - |Humanas                            |\n");
                printf("3 - |Biomedicas                         |\n");
                printf("4 - |Retornar ao menu principal         |\n");
                printf("    *-----------------------------------*\n\n");
                printf("Digite sua opcao: ");
                scanf("%d", &opcao);
                if (opcao ==1 || opcao ==2 || opcao ==3)
                    {

                    printf("Digite codigo de catalogacao: ");
                    scanf("%d", &Novo_Codigo);

                    }
                switch (opcao)
                    {
                    case 1:
                        for(i=0; i<Tam_lista; i++)
                            if (Biblioteca.Exatas[i].Codigo == Novo_Codigo)
                                {
                                exibir (&Biblioteca.Exatas[i]);
                                break;
                                }
                            else
                                {
                                printf("\n\ncodigo nao cadastrado\n\n");

                                getch();
                                break;
                                }
                    break;
                    case 2:
                        for (i=0; i<Tam_lista; i++)
                            if (Biblioteca.Humanas[i].Codigo == Novo_Codigo)
                                {
                                exibir (&Biblioteca.Humanas[i]);
                                break;
                                }
                            else
                                {
                                printf("\n\ncodigo nao cadastrado\n\n");

                                getch();
                                break;
                                }
                    break;
                    case 3:
                        for (i=0; i<Tam_lista; i++)
                            if (Biblioteca.Biomedicas[i].Codigo == Novo_Codigo)
                                {
                                exibir (&Biblioteca.Biomedicas[i]);
                                break;
                                }

                            else
                                {
                                printf("\n\ncodigo nao cadastrado\n\n");

                                getch();
                                break;
                                }
                    break;

                }
                }
                break;
                case MENU_CONSULTA_DOADO:
                {
                    int Novo_Codigo;
                //system("cls");
                printf("    *==================================*  \n");
                printf("    |CONSULTA OBRAS DOADAS DE CADA AREA|  \n");
                printf("    *----------------------------------*  \n");
                printf("1 - |Exatas                            |  \n");
                printf("2 - |Humanas                           |  \n");
                printf("3 - |Biomedicas                        |  \n");
                printf("4 - |Retornar ao menu principal        |  \n");
                printf("    *----------------------------------*\n\n");
                printf("Digite sua opcao: ");
                scanf("%d", &opcao);
                if (opcao ==1 || opcao ==2 || opcao ==3)
                    {

                    printf("Digite codigo de catalogacao: ");
                    scanf("%d", &Novo_Codigo);

                    }

                    switch (opcao)
                    {
                    case 1:
                        for(i=0; i<Tam_lista; i++)
                            if (Biblioteca.Exatas[i].Codigo == Novo_Codigo)
                                {
                                exibir (&Biblioteca.Exatas[i]);
                                break;
                                }
                            else
                                {
                                printf("\n\ncodigo nao cadastrado\n\n");

                                getch();
                                  break;
                                }
                    break;
                    case 2:
                        for (i=0; i<Tam_lista; i++)
                            if (Biblioteca.Humanas[i].Codigo == Novo_Codigo)
                                {
                                exibir (&Biblioteca.Humanas[i]);
                                break;
                                }
                            else
                                {
                                printf("\n\ncodigo nao cadastrado\n\n");

                                getch();
                                  break;
                                }
                    break;
                    case 3:
                        for (i=0; i<Tam_lista; i++)
                            if (Biblioteca.Biomedicas[i].Codigo == Novo_Codigo)
                                {
                                exibir (&Biblioteca.Biomedicas[i]);
                                break;
                                }

                            else
                                {
                                printf("\n\ncodigo nao cadastrado\n\n");

                                getch();
                                  break;
                                }
                    break;

                }
                }
                break;
                case MENU_ALTERA:
                {
                    int Novo_Codigo;
                //system("cls");
                printf("    *==================================*  \n");
                printf("    |        ALTERAR UM REGISTRO       |  \n");
                printf("    *----------------------------------*  \n");
                printf("1 - |Exatas                            |  \n");
                printf("2 - |Humanas                           |  \n");
                printf("3 - |Biomedicas                        |  \n");
                printf("4 - |Retornar ao menu principal        |  \n");
                printf("    *----------------------------------*\n\n");
                printf("Digite sua opcao: ");
                scanf("%d", &opcao);
                if (opcao ==1 || opcao ==2 || opcao ==3)
                    {

                    printf("Digite codigo de catalogacao: ");
                    scanf("%d", &Novo_Codigo);

                    }

                    switch (opcao)
                    {
                    case 1:
                        for(i=0; i<Tam_lista; i++)
                            if (Biblioteca.Exatas[i].Codigo == Novo_Codigo)
                                {
                                alterar (&Biblioteca.Exatas[i]);
                                break;
                                }
                            else
                                {
                                printf("\n\ncodigo nao cadastrado\n\n");

                                getch();
                                  break;
                                }
                    break;
                    case 2:
                        for (i=0; i<Tam_lista; i++)
                            if (Biblioteca.Humanas[i].Codigo == Novo_Codigo)
                                {
                                alterar (&Biblioteca.Humanas[i]);
                                break;
                                }
                            else
                                {
                                printf("\n\ncodigo nao cadastrado\n\n");

                                getch();
                                  break;
                                }
                    break;
                    case 3:
                        for (i=0; i<Tam_lista; i++)
                            if (Biblioteca.Biomedicas[i].Codigo == Novo_Codigo)
                                {
                                alterar (&Biblioteca.Biomedicas[i]);
                                break;
                                }

                            else
                                {
                                printf("\n\ncodigo nao cadastrado\n\n");

                                getch();
                                  break;
                                }
                    break;

                }
                }
                break;
                case MENU_EXCLUIR:
                {
                  int Novo_Codigo;
                //system("cls");
                printf("    *==================================*  \n");
                printf("    |        EXCLUIR UM REGISTRO       |  \n");
                printf("    *----------------------------------*  \n");
                printf("1 - |Exatas                            |  \n");
                printf("2 - |Humanas                           |  \n");
                printf("3 - |Biomedicas                        |  \n");
                printf("4 - |Retornar ao menu principal        |  \n");
                printf("    *----------------------------------*\n\n");

                 printf("Digite sua opcao: ");

                scanf("%d", &opcao);
                if (opcao ==1 || opcao ==2 || opcao ==3)
                    {

                    printf("Digite codigo de catalogacao: ");
                    scanf("%d", &Novo_Codigo);

                    }
                switch (opcao)
                    {
                    case 1:
                        for (i=0; i<Tam_lista; i++)
                            if (Biblioteca.Exatas[i].Codigo == Novo_Codigo)
                                {
                                excluir(&Biblioteca.Exatas[i]);
                                break;
                                }
                    case 2:
                        for (i=0; i<Tam_lista; i++)
                            if (Biblioteca.Humanas[i].Codigo == Novo_Codigo)
                                {
                                excluir(&Biblioteca.Exatas[i]);
                                break;
                                }
                    case 3:
                        for (i=0; i<Tam_lista; i++)
                            if (Biblioteca.Biomedicas[i].Codigo == Novo_Codigo)
                                {
                                excluir(&Biblioteca.Exatas[i]);
                                break;
                                }
                    break;
                }
                }
                break;
                case 6:
                {
                printf ("Encerrando Sistema\n\n");
                exit (0);
                break;
                }


            default:
                {
                printf ("Opcao invalida\n\n");
                break;
                }
            }
        }



    return 0;
}
