#include <stdio.h>
#include <stdlib.h>
#include "trab.h"

int main()
{
    char usu[30],sen[30];
    Lista *l = Inicializar();
    Cliente it;
    int flag=0, lgf=0, c=0,n;
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
            printf("4-Registrar restaurante\n5-Editar restaurante\n6-Mostrar restaurantes\n\n7-Desconectar\n\n");
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
            printf("\nDigite o nome usuario a ser removido:");
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
        case 7:
            c=1;
            lgf=1;
            system("cls");
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
