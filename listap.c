#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Listap.h"

#define MAX 100

typedef struct listaP{
    int total;
    Pratos valores[MAX];
}ListaP;

ListaP *criarP(){
        ListaP *l = (ListaP*)malloc(sizeof(ListaP));
        if(l!=NULL)
            l->total = 0;
        return l;
}

void limparP (ListaP *l){
    if(l!=NULL)
        l->total=0;
}

int inserirFimP (ListaP *l,Pratos it){
    if(l==NULL)
        return 2;
    if(listaCheiaP(l)==0) return 1;
    l->valores[l->total] = it;
    l->total++;
    return 0;
}

int removerFimP(ListaP *l) {
    if(l==NULL)
        return 2;
    if(listaVaziaP(l)==0)
        return 1;
    l->total--;
    return 0;
}

int buscarPosicaoP(ListaP *l,int posicao,Pratos *retorno){
    if(l == NULL)
        return 2;
    if(listaVaziaP(l) == 0)
        return 1;
    *retorno = l->valores[posicao];
    return 0;
}

int listaVaziaP(ListaP *l) {
    if(l==NULL)
        return 2;
    if(l->total==0)
        return 0;
    else
        return 1;
}

int listaCheiaP(ListaP *l) {
    if(l==NULL)
        return 2;
    if(l->total==MAX)
        return 0;
    else
        return 1;
}

int tamanhoP(ListaP *l){
    if(l == NULL)
        return -2;
    return l->total;
}

void mostrarP(ListaP *l) {
    int i;
    if(l!=NULL)
    {
        printf("Cardapio\n");
        for(i=0;i<l->total;i++)
        {
            printf("[%d] %s,\t",i+1,l->valores[i].comida);
            printf("$%.2f\n",l->valores[i].preco);
            printf("     %s\n",l->valores[i].descricao);
        }
        printf("\n");
    }
}

int removerPosicaoP(ListaP *l,int pos){
    int i;
    pos--;
    if(l==NULL)
        return 2;
    if(listaVaziaP(l)==0)
        return 1;
    for(i = pos; i < l->total-1; i++)
        l->valores[i] = l->valores[i+1];
    l->total--;
    return 0;
}

//================================================================

typedef struct nor{
    Restaurante valor;
    struct nor *prox;
}NoR;

typedef struct listar{
    NoR *inicio;
}ListaR;

ListaR *criarR() {
    ListaR *lr = (ListaR*)malloc(sizeof(ListaR));
    lr->inicio = NULL;
    return lr;
}

int inserirInicioR(ListaR *l, Restaurante it) {
    if (l == NULL) return 2;
    NoR *nor = (NoR*)malloc(sizeof(NoR));
    nor->valor = it;
    nor->prox = l->inicio;
    l->inicio = nor;
    return 0;
}

int removerInicioR(ListaR *l) {
    if (l == NULL) return 2;
    if (listaVaziaR(l) == 0) return 1;
    NoR *noRListaR = l->inicio;
    l->inicio = noRListaR->prox;

    return 0;
}

void limparR(ListaR *l) {
    while (listaVaziaR(l) != 0)
        removerInicioR(l);
}

void mostrarR(ListaR *l) {
    if (l != NULL) {
       printf("Tabela de tipos:\n1-Italiano\n2-Comida caseira\n3-Japones\n4-Fast food\n5-Bar e aperitivos\n6-Doces e sorvetes\n\n");
       NoR *noRListaR = l->inicio;
       while (noRListaR != NULL) {
          printf("%s, ",noRListaR->valor.nome);
          printf("ID: %d, ",noRListaR->valor.id);
          printf("Tipo :%d\n\n ",noRListaR->valor.culinaria);
          noRListaR = noRListaR->prox;
       }
    }
}

int listaVaziaR(ListaR *l) {
    if (l == NULL) return 2;
    if (l->inicio == NULL) return 0;
    return 1;
}

int removerIDR(ListaR *l, int p) {
    if (l == NULL) return 2;
    if (listaVaziaR(l) == 0) return 1;
    NoR *noRAuxiliarR = NULL;
    NoR *noRListaR = l->inicio;
    while ((noRListaR->prox != NULL)&&(noRListaR->valor.id != p)) {
        noRAuxiliarR = noRListaR;
        noRListaR = noRListaR->prox;
    }
    if (noRAuxiliarR == NULL)
        return removerInicioR(l);
    else {
        noRAuxiliarR->prox = noRListaR->prox;
    }

    return 0;

}

int buscarItemChaveR(ListaR *l, int ch, Restaurante *ret) {
    if (l == NULL) return 2;
    NoR *noRListaR = l->inicio;
    while ((noRListaR != NULL)) {
        if ((noRListaR->valor).id == ch) {
           *ret = noRListaR->valor;
           return 0;
        }
        noRListaR = noRListaR->prox;
    }
    return 1;
}

void mostraridR(ListaR *l,int id){
    NoR *noRListaR = l->inicio;
    int flag=0;
    if(id==7){
        while(noRListaR != NULL) {
          flag=1;
          printf("[%d]: ",noRListaR->valor.id);
          printf("%s,\n",noRListaR->valor.nome);
        noRListaR = noRListaR->prox;
    }}
    while(noRListaR != NULL) {
        if(noRListaR->valor.culinaria == id){
          flag=1;
          printf("[%d]: ",noRListaR->valor.id);
          printf("%s,\n",noRListaR->valor.nome);
        }
        noRListaR = noRListaR->prox;
    }
    if(flag==0)printf("\nNao ha restaurantes desse tipo,\npor favor escolha outro\n");
    printf("\n");
}

int contemidR(ListaR *l, int id){
    NoR *noRListaR = l->inicio;
    while(noRListaR != NULL) {
        if(noRListaR->valor.id == id){
            return 1;
        }
        noRListaR = noRListaR->prox;
    }
    return 0;
}

//=========================================================

ListaR *InicializarR() {
    ListaR *LR = criarR();
    Restaurante it,it3,it4,it5;
    it.l = criarP();
    Pratos it2;
    strcpy(it2.comida,"Macarrao bolonhesa");
    strcpy(it2.descricao,"Macarrao espaguetti ao molho de tomate com carne moida, temperado com sal, oregano e pimenta do reino");
    it2.preco = 14.50;
    if (inserirFimP(it.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Macarrao alho e oleo");
    strcpy(it2.descricao,"Macarrao fettucini temperado com sal, oregano, alho e refogado no oleo");
    it2.preco = 12;
    if (inserirFimP(it.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Macarrao kids");
    strcpy(it2.descricao,"Macarrao gravatinha ao molho branco com pedacos de presunto e ervilhas, temperado com sal e oregano");
    it2.preco = 11.50;
    if (inserirFimP(it.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Macarrao da casa");
    strcpy(it2.descricao,"Macarrao pene ao molho de tomate com pedacos de calabresa, bacon, presunto e temperado com sal, oregano e alho");
    it2.preco = 16;
    if (inserirFimP(it.l,it2)!=0) printf("Erro?");
    strcpy(it.nome,"Casa do macarrao");
    it.id = 1;
    it.culinaria = 1;
    if (inserirInicioR(LR,it)!=0) printf("Erro?");

    //===============

    it3.l = criarP();
    strcpy(it2.comida,"Sashimi de salmao");
    strcpy(it2.descricao,"10 Filetes de salmao cru gelados, acompanhados de sache de molho shoyu");
    it2.preco = 17.50;
    if (inserirFimP(it3.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Lula a milanesa");
    strcpy(it2.descricao,"Pedacos de lula cobertos de massa e faleros de panko, fritos no oleo, acompanhados de sache de molho shoyu");
    it2.preco = 19;
    if (inserirFimP(it3.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Sushi: atum");
    strcpy(it2.descricao,"10 Pedacos de atum enrolados em arroz, com um exterior de nori(alga japonesa), acompanhados de sache de molho shoyu");
    it2.preco = 13.50;
    if (inserirFimP(it3.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Sushi: salmao");
    strcpy(it2.descricao,"10 Pedacos de salmao enrolados em arroz, com um exterior de nori(alga japonesa), acompanhados de sache de molho shoyu");
    it2.preco = 15.50;
    if (inserirFimP(it3.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Barca sortida");
    strcpy(it2.descricao,"10 sushis de salmao, 10 sushis de atum, 15 pecas de lula frita e 5 sashimis de salmao, acompanhados de sache de molho shoyu");
    it2.preco = 65.50;
    if (inserirFimP(it3.l,it2)!=0) printf("Erro?");
    strcpy(it3.nome,"Isshin the sushi saint");
    it3.id = 2;
    it3.culinaria = 3;
    if (inserirInicioR(LR,it3)!=0) printf("Erro?");

    //===============

    it4.l = criarP();
    strcpy(it2.comida,"Arroz");
    strcpy(it2.descricao,"Arroz branco com sal");
    it2.preco = 4.50;
    if (inserirFimP(it4.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Feijao");
    strcpy(it2.descricao,"Feijao marrom");
    it2.preco = 4;
    if (inserirFimP(it4.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Frango");
    strcpy(it2.descricao,"File de frango cozido na chapa");
    it2.preco = 3;
    if (inserirFimP(it4.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Bife");
    strcpy(it2.descricao,"Bife de vaca cozido na chapa");
    it2.preco = 3.50;
    if (inserirFimP(it4.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Salada");
    strcpy(it2.descricao,"Alface, tomate, azeite e cebola roxa");
    it2.preco = 2;
    if (inserirFimP(it4.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Marmita completa: B");
    strcpy(it2.descricao,"Arroz, feijao, salada e bife");
    it2.preco = 16;
    if (inserirFimP(it4.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Marmita completa: F");
    strcpy(it2.descricao,"Arroz, feijao, salada e file de frango");
    it2.preco = 16;
    if (inserirFimP(it4.l,it2)!=0) printf("Erro?");
    strcpy(it4.nome,"Jantinha da tia");
    it4.id = 3;
    it4.culinaria = 2;
    if (inserirInicioR(LR,it4)!=0) printf("Erro?");

    //===============

    it5.l = criarP();
    strcpy(it2.comida,"Peperoni");
    strcpy(it2.descricao,"Massa de pizza com molho de tomate, queijo, oregano e fatias de peperoni");
    it2.preco = 16.50;
    if (inserirFimP(it5.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"4 queijos");
    strcpy(it2.descricao,"Massa de pizza com molho de tomate, quatro queijos sortidos e oregano");
    it2.preco = 15;
    if (inserirFimP(it5.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Frango catupiry");
    strcpy(it2.descricao,"Massa de pizza com molho de tomate, catupiry frango desfiado");
    it2.preco = 16;
    if (inserirFimP(it5.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Churrasco");
    strcpy(it2.descricao,"Massa de pizza com molho de tomate, queijo, oregano e pedacos de carne");
    it2.preco = 18;
    if (inserirFimP(it5.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Chocolate");
    strcpy(it2.descricao,"Massa de pizza com queijo, chocolate derretido e pedaços de sonho de valsa");
    it2.preco = 14;
    if (inserirFimP(it5.l,it2)!=0) printf("Erro?");
    strcpy(it2.comida,"Banana & morango");
    strcpy(it2.descricao,"Massa de pizza com queijo, chocolate derretido e fatias de morango e de banana");
    it2.preco = 15;
    if (inserirFimP(it5.l,it2)!=0) printf("Erro?");
    strcpy(it5.nome,"DiGiornoGiovanna");
    it5.id = 4;
    it5.culinaria = 1;
    if (inserirInicioR(LR,it5)!=0) printf("Erro?");

    return LR;
}

void legenda() {
    printf("Tabela de tipos:\n1-Italiano\n2-Comida caseira\n3-Japones\n4-Fast food\n5-Doces e sorvetes\n6-Outros(nao categorizaveis)\n7-Todos os restaurantes\n\n");
}

//=========================================================

typedef struct listaC{
    int qtd;
    float prec;
    Pratos valores[MAX];
}ListaC;

ListaC *criarC(){
    ListaC *l = (ListaC*) malloc (sizeof(ListaC));
    if (l != NULL) l -> qtd = 0;
    l->prec=0;
    return l;
    }

int limparc( ListaC *l){
    if (l == NULL) return 1;
    l -> qtd = 0;
    l->prec=0;
    return 0;
}

int inserirC(ListaC *l,int tanto,Pratos it){
    if (l == NULL) return 1;
    if (listacheiaC(l)==0) return 2;
    l->valores[l->qtd] = it;
    l->valores[l->qtd].quant = tanto;
    l->qtd ++;
    l->prec=l->prec+(tanto*it.preco);
    return 0;
}

int removerC(ListaC *l){
    if (l == NULL) return 1;
    if (l->qtd==0) return 2;
    l->prec=l->prec-(l->valores[l->qtd-1].quant*l->valores[l->qtd-1].preco);
    l->qtd--;
    return 0;
}

int removerC2(ListaC *l,int tanto,int qual){
    if (l == NULL) return 1;
    while (qual != l->qtd){
        l->valores[qual] = l->valores[qual+1];
        qual++;
        l->qtd--;}
    return 0;
}

int listacheiaC(ListaC *l) {
    if(l==NULL)
        return 2;
    if(l->qtd == MAX)
        return 0;
    else
        return 1;
}

int listaVaziaC(ListaC *l) {
    if(l==NULL)
        return 2;
    if(l->qtd == 0)
        return 0;
    else
        return 1;
}

void mostrarC(ListaC *l){
    int i;
    if(l==NULL) printf("ERRO");
    if(l->qtd==0)printf("\nCarrinho vazio...\n\n");
    else{
    printf("Carrinho:\n\nTotal de itens: %d\nTotal a pagar: $%.2f\n\n",l->qtd,l->prec);
    for (i = 0;i < (l->qtd);i++){
        printf("(%d) %s\t",i + 1,l->valores[i].comida);
        printf("%d X $%.2f\n ",l->valores[i].quant,l->valores[i].preco);
        }
    printf("\n");}
}
