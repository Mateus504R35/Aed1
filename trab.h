#include <stdio.h>
#include <stdlib.h>

typedef struct cliente{
char usu[30];
char senha[30];
}Cliente;

typedef struct lista Lista;

Lista *criar();
int listaVazia(Lista *l);
int inserirCli(Lista *l,Cliente it);
int removerCli(Lista *l,Cliente it);
int comparaStrg(char a[], char b[]);
int auth(Lista *l, char a[], char b[]);
Lista *Inicializar();
int authADM(char a[], char b[]);
void mostrar(Lista *l);
