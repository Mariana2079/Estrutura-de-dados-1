#include <stdio.h>
#include <stdlib.h>

typedef struct item Item;
typedef struct celula Celula;
typedef struct lista Lista;

Lista *criar();
int verifica(Lista *l);
void insereInicio(Lista *l, int chave);
Celula *busca(Lista *l, int chave);
void insereMeio(Lista *l, int chave, int x);
void insereFim(Lista *l, int chave);
void imprime(Lista *l);
void remover(Lista *l, int x);
void libera(Lista *l);
void copia(Lista *l1, Lista *l2);
void guarda(Lista *l1, Lista *l2);
int tamanho(Lista *l);
void trocar(Celula *a, Celula *b);
void ordena(Celula *aux);
