#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trab.h"

typedef struct no {
Cliente valor;
struct no *prox;
}No;

typedef struct lista {
No *inicio;
}Lista;

Lista *criar() {
Lista *l = (Lista*)malloc(sizeof(Lista));
l->inicio = NULL;
return l;
}

int listaVazia(Lista *l) {
if (l == NULL)
return 2;
if (l->inicio == NULL)
return 0;
return 1;
}

int inserirCli(Lista *l, Cliente it) {
if (l == NULL)
return 2;
No *no = (No*)malloc(sizeof(No));
no->valor = it;
no->prox = l->inicio;
l->inicio = no;
return 0;
}

int comparaStrg(char a[],char b[]) {
    int flag=0,i=0;
    while(a[i]!='\0' &&b[i]!='\0')
    {
       if(a[i]!=b[i])
       {
           flag=1;
           break;
       }
       i++;
    }
    if(a[i]!='\0'||b[i]!='\0')
       return 1;
    if(flag==0)
    return 0;
    else
    return 1;
}

int removerCli(Lista *l, Cliente it){
if (l == NULL) return 2;
No *temp = NULL;
No *noLista = l->inicio;
if(comparaStrg(noLista->valor.usu,it.usu)==0){
    l->inicio = noLista->prox;
    free(noLista);
    return 0;
};

while ((noLista->prox != NULL)&&(comparaStrg(noLista->valor.usu,it.usu)!=0))
{
temp = noLista;
noLista = noLista->prox;
}
if(comparaStrg(noLista->valor.usu,it.usu)==0){
temp->prox = noLista->prox;
free(noLista);
return 0;}
else return 1;
}

int auth(Lista *l,char a[], char b[]) {
if (l == NULL) return 2;
int flag = 0;
No *noLista = l->inicio;
while ((noLista != NULL)&&(flag==0))
{
    if((comparaStrg(noLista->valor.usu,a)==0)&&(comparaStrg(noLista->valor.senha,b)==0)){
       flag=1;break;}
else noLista = noLista->prox;
}
if(flag==1) return 0;
else return 1;}

int authADM(char a[], char b[]) {
    char admS[30],admU[30];
    strcpy(admU, "ADMIN");
    strcpy(admS, "1234");
    if((comparaStrg(admU,a)==0)&&(comparaStrg(admS,b)==0))return 0;
    else return 1;
}

void mostrar(Lista *l) {
if (l != NULL) {
printf("\n//");
No *noLista = l->inicio;
while (noLista != NULL) {
printf("%s //",noLista->valor.usu);
noLista = noLista->prox;
}
printf("\n");
}
}

Lista *Inicializar(){
    Lista *l = criar();
    Cliente it;
    strcpy(it.usu,   "Pedro");
    strcpy(it.senha, "01234");
    if (inserirCli(l,it)!=0) printf("Erro?");
    strcpy(it.usu,   "Jeff");
    strcpy(it.senha, "98765");
    if (inserirCli(l,it)!=0) printf("Erro?");
    strcpy(it.usu,   "Mateus");
    strcpy(it.senha, "56789");
    if (inserirCli(l,it)!=0) printf("Erro?");
    strcpy(it.usu,   "Geraldo");
    strcpy(it.senha, "43210");
    if (inserirCli(l,it)!=0) printf("Erro?");
    return l;
}

int authcard(char c[]){
    if((c[4]!=' ')||(c[9]!=' ')||(c[14]!=' ')||(c[19]!=' ')||(c[22]!='/')||(c[25]!=' '))return 1;
    if((c[0] == '0')&&(c[0]!=' ')&&(c[0]!=' ')&&(c[0]!=' ')&&(c[0]!='/')&&(c[0]!=' ')) return 3;
    return 0;
}
