#include <stdio.h>
#include <stdlib.h>
#include "trab.h"
#include "Listap.h"

int main()
{
    char usu[30],sen[30];
    Lista *l = Inicializar();
    ListaR *lR = InicializarR();
    Pratos pit;
    Cliente it;
    Restaurante rit;
    Restaurante *ret = (Restaurante*)malloc(sizeof(Restaurante));
    int flag=0, lgf=0, c=0,c2=0,n2,n,j;
    printf("Bem vindo, insira seu usuario e senha:");
    while((flag==0)||(lgf==1)){
    fflush(stdin);
    printf("\nUsuario:");
    gets(usu);
    fflush(stdin);
    printf("\nSenha:");
    gets(sen);
    fflush(stdin);
    system("cls");
    if (authADM(usu, sen)==0) {
            flag = 1;
            lgf = 0;
            c =0;
        while (c==0){
            system("cls");
            printf("Bem vindo administrador\n");
            printf("\nSelecione uma opcao\n\n1-Registrar usuario\n2-Remover usuario\n3-Mostrar usuarios\n\n");
            printf("4-Registrar restaurante\n5-Editar restaurante\n6-Mostrar restaurantes\n\n7-Desconectar\n8-Encerrar programa\n\n");
            scanf("%d", &n);
        switch(n)
        {
        case 1:
            system("cls");
            fflush(stdin);
            printf("\nDigite o nome do novo usuario:");
            gets(it.usu);
            fflush(stdin);
            printf("\nDigite a senha do novo usuario:");
            gets(it.senha);
            if (inserirCli(l,it)!=0)printf("ERRO!");
        break;
        case 2:
            system("cls");
            fflush(stdin);
            mostrar(l);
            printf("\n\nDigite o nome do usuario a ser removido:");
            gets(it.usu);
            if (removerCli(l,it)!=0)printf("ERRO!");
        break;
        case 3:
            system("cls");
            mostrar(l);
            printf("\n\nDigite 0 para retornar:");
            scanf("%d", &c);
            c=0;
        break;
        case 4:
            system("cls");
            printf("Tabela de tipos:\n1-Italiano\n2-Comida caseira\n3-Japones\n4-Fast food\n5-Bar e aperitivos\n6-Doces e sorvetes\n\nPara registrar o cardapio do restaurante, utilize a funcao 'editar restaurante' no menu anterior\n\n");
            fflush(stdin);
            printf("Digite o nome do novo restaurante:");
            gets(rit.nome);
            fflush(stdin);
            printf("\nDigite o numero correspondente ao tipo do novo restaurante:");
            scanf("%d",&rit.culinaria);
            fflush(stdin);
            printf("\nDigite o ID do novo restaurante:");
            scanf("%d",&rit.id);
            rit.l = criarP();
            if (inserirInicioR(lR,rit)!=0)printf("ERRO!");
        break;
        case 5:
            system("cls");
            mostrarR(lR);
            printf("\n\nDigite o ID do restaurante que deseja editar:");
            scanf("%d", &j);
            system("cls");
            buscarItemChaveR(lR,j,ret);
            c2=0;
            while (c2==0){
            system("cls");
            printf("Nome: %s\nID:%d\nTipo:%d",ret->nome,ret->id,ret->culinaria);
            printf("\n\n1-Remover prato\n2-Adicionar prato\n3-Mostrar pratos\n4-Deletar restaurante\n\n5-Voltar\n");
            scanf("%d", &n2);
            switch(n2){
            case 1:
                system("cls");
                mostrarP(ret->l);
                fflush(stdin);
                printf("\nDigite o numero do prato:");
                scanf("%d", &j);
                if (removerPosicaoP(ret->l,j)!=0)printf("ERRO!");
            break;
            case 2:
                system("cls");
                mostrarP(ret->l);
                fflush(stdin);
                printf("\n\nDigite o nome do prato:");
                gets(pit.comida);
                fflush(stdin);
                printf("\nDigite a descricao do prato:\n");
                gets(pit.descricao);
                fflush(stdin);
                printf("\nDigite o preco:");
                scanf("%f",&pit.preco);
                if (inserirFimP(ret->l,pit)!=0)printf("ERRO!");
            break;
            case 3:
                system("cls");
                mostrarP(ret->l);
                printf("\n\nDigite 0 para retornar:");
            scanf("%d", &c2);
            c2=0;
            break;
            case 4:
                limparP(ret->l);
                if (removerIDR(lR,ret->id)!=0)printf("ERRO!");
                c2=1;
                system("cls");
            break;
            case 5:
                c2=1;
                system("cls");
            break;
            }
            }
        break;
        case 6:
            system("cls");
            mostrarR(lR);
            printf("\n\nDigite 0 para retornar:");
            scanf("%d", &c);
        break;
        case 7:
            c=1;
            lgf=1;
            system("cls");
        break;
        case 8:
            system("cls");
            printf("Encerrando...\n\nAte a proxima.\n");
            return 0;
        break;
        }}

    }
    else if (auth(l,usu, sen)==0){
            flag = 1;
            lgf = 0;
            c=0;
            printf("Bem vindo %s", usu);

    }
    else printf("Usuario ou senha incorretos, tente novamente.");}
}
