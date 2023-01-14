#ifndef LISTAP_H_INCLUDED
#define LISTAP_H_INCLUDED

typedef struct prato Pratos;

typedef struct listaP ListaP;

ListaP criar();
void limpar(ListaPl);

int inserirInicio(ListaP l, Pratos it);
int inserirFim(ListaPl, Pratos it);
int inserirPosicao(ListaP l, Pratos it,int pos);

int removerInicio (ListaPl);
int removerFim (ListaP l);
int removerPosicao(ListaPl,int pos);
int removerItem(ListaP l, Pratos it);

int buscarItemChave (ListaPl,int chave, Prato retorno);
int buscarPosicao(ListaPl,int posicao, Prato retorno);

int listaVazia(ListaPl);
int tamanho(ListaP l);
void mostrar(ListaPl);



#endif // LISTAP_H_INCLUDED
