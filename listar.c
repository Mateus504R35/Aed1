#include "listar.h"

typedef struct restaurante{
    char nome[30];
    int id;
    Pratos *cardapio;   // encadeada
    int culinaria;
    Restaurante *prox;
}Restaurante;

typedef struct prato{
    char comida[30];
    int preco;
    char descricao[100]; 
    Pratos *prox;
}Pratos;

typedef struct listar {
  Restaurante *inicio;
}ListaR;

