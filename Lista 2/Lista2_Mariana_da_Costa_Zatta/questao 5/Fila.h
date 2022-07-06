#include <stdio.h>
#include <stdlib.h>

typedef struct item Item;
typedef struct celula Celula;
typedef struct fila Fila;


Fila *cria();
int verifica(Fila *f);
void imprime(Fila *f);
void enfileira(Fila *f, int x);
void desenfileira(Fila *f);
void libera(Fila *f);
void ordem(Fila *f);
