#include <stdio.h>
#include <stdlib.h>
#include "listar.h"

#define MAX 100

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
    free(noRListaR);
    return 0;
}

void limparR(ListaR *l) {
    while (listaVaziaR(l) != 0)
        removerInicioR(l);
}

void mostrarR(ListaR *l) {
    if (l != NULL) {
       printf("[");
       NoR *noRListaR = l->inicio;
       while (noRListaR != NULL) {
          printf(" {%d, ",noRListaR->valor.id);
          printf("%s, ",noLista->valor.nome);
          printf("%d} ",noLista->valor.culinaria);
          noRListaR = noRListaR->prox;
       }
       printf("]\n");
    }
}

int listaVaziaR(ListaR *l) {
    if (l == NULL) return 2;
    if (l->inicio == NULL) return 0;
    return 1;
}

int removerPosicaoR(ListaR *l, int p) {
    if (l == NULL) return 2;
    if (listaVaziaR(l) == 0) return 1;
    if (p < 0) return 3;
    int r = 0;
    NoR *noRAuxiliarR = NULL;
    NoR *noRListaR = l->inicio;
    while ((noRListaR->prox != NULL)&&(r != p)) {
        noRAuxiliarR = noRListaR;
        noRListaR = noRListaR->prox;
        r++;
    }
    if (noRAuxiliarR == NULL)
        return removerInicio(l);
    else {
        noRAuxiliarR->prox = noRListaR->prox;
    }
    free(noRListaR);
    return 0;

}


int buscarItemChaveR(ListaR *l, int ch, Restaurante *ret) {
    if (l == NULL) return 2;
    NoR *noRListaR = l->inicio;
    while ((noRListaR != NULL)) {
        if ((noRListaR->valor).id == chave) {
           *ret = noRListaR->valor;
           return 0;
        }
        noRListaR = noRListaR->prox;
    }
    return 1;
}
