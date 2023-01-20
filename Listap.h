
typedef struct prato{
    char comida[60];
    float preco;
    char descricao[300];
    int quant;
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

//================================================================

typedef struct restaurante{
    char nome[40];
    int id;
    int culinaria;
    ListaP *l;
}Restaurante;

typedef struct listar ListaR;
typedef struct nor NoR;

ListaR *criarR();

int inserirInicioR(ListaR *l, Restaurante it);
int removerIDR(ListaR *l,int p);
void limparR(ListaR *l);

int buscarItemChaveR (ListaR *l, int ch, Restaurante *ret);
void mostraridR(ListaR *l, int id);
int contemidR(ListaR *l, int id);

int listaVaziaR(ListaR *l);
void mostrarR(ListaR *l);

ListaR *InicializarR();

//==================================================================

void legenda();

typedef struct listaC ListaC;

ListaC *criarC();
int limparc(ListaC *l);

int inserirC(ListaC *l,int tanto,Pratos it);
int removerC(ListaC *l);
int removerC2(ListaC *l,int tanto,int qual);
int listaVaziaC(ListaC *l);

int listacheiaC(ListaC *l);

void mostrarC(ListaC *l);
