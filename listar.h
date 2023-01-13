#ifndef LISTAR_H_INCLUDED
#define LISTAR_H_INCLUDED

typedef struct prato Pratos;

typedef struct listar ListaR;

typedef struct restaurante Restaurante;

Lista *criar();
void limpar(ListaR *l);

int inserirInicio(ListaR *l, Restaurante it);
int inserirFim(ListaR *l, Restaurante it);
int inserirPosicao(ListaR *l, Restaurante it,int pos);

int removerInicio (ListaR *l);
int removerFim (ListaR *l);
int removerPosicao(ListaR *l,int pos);
int removerItem(ListaR *l, Restaurante it);

int buscarItemChave (ListaR *l,int chave, Restaurante *retorno);
int buscarPosicao(ListaR *l,int posicao, Restaurante *retorno);

int listaVazia(ListaR *l);
int tamanho(ListaR *l);
void mostrar(ListaR *l);



#endif // LISTAR_H_INCLUDED

