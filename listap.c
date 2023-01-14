#include <stdio.h>
#include <stdlib.h>
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

void limpar (ListaP *l){
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
