#include <stdio.h>
#include <stdlib.h>
#include "trab.h"
#include "Listap.h"

int main()
{
    char usu[31],sen[31],card[29];
    Lista *l = Inicializar();
    ListaR *lR = InicializarR();
    Pratos pit;
    Cliente it;
    Restaurante rit;
    Restaurante *ret = (Restaurante*)malloc(sizeof(Restaurante));
    int flag=0, lgf=0, c=0,c2=0,n2,n,j;
    int cn,cn2,c3,cj,v1,v2;
    printf("Bem vindo, insira seu usuario e senha:");
    while((flag==0)||(lgf==1)){
    fflush(stdin);
    printf("\n\nUsuario:");
    gets(usu);
    fflush(stdin);
    printf("Senha:");
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
            printf("\nDigite o nome do novo usuario(max:30 caracteres):");
            gets(it.usu);
            fflush(stdin);
            printf("\nDigite a senha do novo usuario(max:30 caracteres):");
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
            legenda();
            printf("Para registrar o cardapio do restaurante, utilize a funcao 'editar restaurante' no menu anterior\n\n");
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
            while (c==0){
            system("cls");
            printf("Bem vindo %s", usu);
            printf("\n\nCarrinho:");
            legenda();
            printf("Digite 0 para desconectar\n\nEscolha um estilo culinario e digite seu numero,\nou digite 8 para completar seu pedido\n\n");
            fflush(stdin);
            scanf("%d",&cn);
            if(cn==0){
                printf("\nAviso: desconectar causara a perda dos itens salvos no carrinho, digite 0 novamente se deseja continuar:");
                fflush(stdin);
                scanf("%d",&cn);
                if(cn==0){
                c=1;
                lgf=1;
                system("cls");}
                }
            else if(cn>7){
                cn2=0;
                while(cn2==0){
                system("cls");
                printf("Valor a pagar:\n\nPor favor digite seu numero de cartao, data de validade e cvv neste exato modelo(com espacos e barras):\n");
                printf("XXXX XXXX XXXX XXXX XX/XX XXX\n");
                fflush(stdin);
                gets(card);
                if(card[29]!='\0'){printf("Credenciais incorretas, digite 1 para tentar novamente:");scanf("%d",&c3);c3=0;}
                else{cn2=1;
                    system("cls");
                    printf("Sucesso, seu pedido foi processado,\npor favor mantenha este programa aberto ate recebe-lo e digite 1 quando seu pedido for entregue\n");
                    printf("Caso nao receba seu pedido dentro de 40 a 50 minutos, digite 0 para entrar em contato com um assistente\n");
                    scanf("%d",&c3);
                    if(c3==1){
                            system("cls");
                            printf("Obrigado por utilizar nosso servico, bom apetite!");
                            printf("\n\nDigite 0 para encerrar o programa, ou 1 para retornar a tela de login:\n");
                            scanf("%d",&v1);
                            if(v1==0)return 0;
                            else{c=1;
                            lgf=1;
                            system("cls");
                    }}
                    else {
                            system("cls");
                            printf("Por favor entre em contato com este numero para falar com um asssitente\n\n34 9XXX-XXXX");
                            printf("\n\nDigite 0 para encerrar o programa, ou 1 para retornar a tela de login");
                            scanf("%d",&v1);
                            if(v1==0)return 0;
                            else{c=1;
                            lgf=1;
                            system("cls");
                            }
                    }
                }
            }}
            else {
                cn2=0;
                while(cn2==0){
                system("cls");
                //funçao
                printf("Finge que tem uns restaurante aqui\n\n");
                printf("Digite 0 para retornar\n\nDigite o ID de um dos restaurantes:");
                fflush(stdin);
                scanf("%d",&cj);
                if(cj==0)cn2=1;
                else{
                    if(buscarItemChaveR(lR,cj,ret)!=0)printf("Erro! Este ID nao existe!");
                    else{
                        c3=0;
                        while(c3==0){
                        system("cls");
                        printf("Carrinho:\n\n");
                        printf("Nome: %s\n\n",ret->nome);
                        mostrarP(ret->l);
                        printf("\nDigite 0 0 para voltar\n\nDigite o numero referente ao prato de sua escolha e quantas unidades deseja:\n");
                        fflush(stdin);
                        scanf("%d %d",&v1,&v2);
                        if((v1==0)&&(v2==0))c3=1;
                        //elsefunção;
                        }
                    }
                }}
            }}
    }
    else printf("Usuario ou senha incorretos, tente novamente.");}
}
