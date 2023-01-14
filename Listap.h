#ifndef LISTAP_H_INCLUDED
#define LISTAP_H_INCLUDED

typedef struct prato Pratos;

typedef struct listaP ListaP;

ListaP criarP();
void limparP(ListaPl);

int inserirInicioP(ListaP l, Pratos it);
int inserirFimP(ListaPl, Pratos it);
int inserirPosicaoP(ListaP l, Pratos it,int pos);

int removerInicioP (ListaPl);
int removerFimP (ListaP l);
int removerPosicaoP(ListaPl,int pos);
int removerItemP (ListaP l, Pratos it);

int buscarItemChaveP (ListaPl,int chave, Prato retorno);
int buscarPosicaoP(ListaPl,int posicao, Prato retorno);

int listaVaziaP(ListaPl);
int tamanhoP(ListaP l);
void mostrarP(ListaPl);



#endif // LISTAP_H_INCLUDED
