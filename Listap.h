#ifndef LISTAP_H_INCLUDED
#define LISTAP_H_INCLUDED

typedef struct prato{
    char comida[30];
    float preco;
    char descricao[100];
}Pratos;

typedef struct listaP ListaP;

ListaP *criarP();
void limparP(ListaP *l);

int inserirInicioP(ListaP *l, Pratos it);
int inserirFimP(ListaP *l, Pratos it);
int inserirPosicaoP(ListaP *l, Pratos it,int pos);

int removerInicioP (ListaP *l);
int removerFimP (ListaP *l);
int removerPosicaoP(ListaP *l,int pos);
int removerItemP (ListaP *l, Pratos it);

int buscarItemChaveP (ListaP *l,int chave, Pratos *retorno);
int buscarPosicaoP(ListaP *l,int posicao, Pratos *retorno);

int listaVaziaP(ListaP *l);
int listaCheiaP(ListaP *l);
int tamanhoP(ListaP *l);
void mostrarP(ListaP *l);



#endif // LISTAP_H_INCLUDED
