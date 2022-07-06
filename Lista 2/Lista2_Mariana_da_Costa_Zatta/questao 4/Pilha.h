#include <stdio.h>
#include <stdlib.h>

typedef struct item Item;
typedef struct celula Celula;
typedef struct pilha Pilha;


Pilha *cria();
int verifica(Pilha *p);
void imprime(Pilha *p);
void empilha(Pilha *p, int x);
void desempilha(Pilha *p);
void libera(Pilha *p);
void classificar(Pilha *p, Pilha* p2, Pilha* p3);
