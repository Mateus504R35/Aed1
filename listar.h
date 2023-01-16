#ifndef LISTAR_H_INCLUDED
#define LISTAR_H_INCLUDED

typedef struct restaurante{
    char nome[30];
    int id;
    int culinaria;
}Restaurante;

typedef struct listar ListaR;
typedef struct nor NoR;

ListaR *criarR();

int inserirInicioR(ListaR *l, Restaurante it);
int removerInicioR(ListaR *l);
void limparR(ListaR *l);

int buscarItemChave (ListaR *l, int ch, Restaurante *ret);

int listaVaziaR(ListaR *l);
void mostrarR(ListaR *l);



#endif // LISTAR_H_INCLUDED
