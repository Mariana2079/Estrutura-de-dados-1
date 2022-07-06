#include "Pilha.h"

struct item {
    int chave;
};

struct celula{
	Item item;
	Celula *prox;
};

struct pilha{
    Celula *topo;
};


Pilha *cria(){
	Pilha *p = malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

int verifica(Pilha *p){
	return p->topo == NULL;
}

void imprime(Pilha *p){
	printf("\n");
	Celula *aux;
	for(aux=p->topo; aux!=NULL; aux=aux->prox){
		printf("Chave %d\n", aux->item.chave);
	}
}

void empilha(Pilha *p, int x){
	Item novo;
	novo.chave = x;
	Celula *nova = malloc(sizeof(Celula));
	nova->item = novo;
	nova->prox = p->topo;
	p->topo = nova;
}

void desempilha(Pilha *p){
	if(verifica(p)){
		printf("\tErro na pilha.");
		return;
	}
	Celula *remover = p->topo;
	p->topo = remover->prox;
	free(remover);
}

void classificar(Pilha *p, Pilha *p2, Pilha *p3){
	if(verifica(p)){
		printf("Pilha principal esta vazia");
		return;
	}
	if( !verifica(p2) || !verifica(p3) ){
		printf("Pilhas a serem gravadas nao estao vazias");
		return;
	}

	Celula *aux;
	for(aux=p->topo; aux!=NULL; aux=aux->prox){

		if( aux->item.chave % 2 == 0 ){
			empilha(p2, aux->item.chave);
		}
		else{
			empilha(p3, aux->item.chave);
		}
	}
}

void libera(Pilha *p){
	Celula *aux = p->topo;
	Celula *liberar;
	while(aux != NULL){
		liberar = aux;
		aux = aux->prox;
		free(liberar);
	}
	free(p);
}


