#include "Fila.h"

struct item{
	int chave;
};
struct celula{
	Item item;
	Celula *prox;
};
struct fila{
	Celula *inicio;
	Celula *fim;
};

Fila *cria(){
	Fila *f = malloc(sizeof(Fila));
	f->inicio = NULL;
	f->fim = NULL;
	return f;
}

int verifica(Fila *f){
	return f->inicio == NULL;
}

void imprime(Fila *f){
	Celula *aux = f->inicio;
	while(aux != NULL){
		printf("\nChave: %d", aux->item.chave);
		aux = aux->prox;
	}
	printf("\n");
}

void enfileira(Fila *f, int chave){
	Item novo;
	novo.chave = chave;
	Celula *nova = malloc(sizeof(Celula));
	nova->item = novo;
	nova->prox = NULL;
	if(verifica(f)){
		f->inicio = nova;
	}
	else{
		f->fim->prox = nova;
	}
	f->fim = nova;
}

void desenfileira(Fila *f){
	if(verifica(f)){
		printf("\n\tErro, fila vazia");
		return;
	}
	Celula *remover = f->inicio;
	f->inicio = remover->prox;
	free(remover);
	if(verifica(f)){
		f->fim = NULL;
	}
}

void libera(Fila *f){
	Celula *aux = f->inicio;
	Celula *liberar;
	while(aux != NULL){
		liberar = aux;
		aux = aux->prox;
		free(liberar);
	}
	free(f);
}

void ordem(Fila *f){
	if( verifica(f) ){
		printf("Erro, fila vazia");
		return;
	}

	Celula *aux = f->inicio;
	int zero = aux->item.chave;
	aux = aux->prox;

	while(aux != NULL){
		if( aux->item.chave < zero ){
			   	printf("\nNao esta em ordem crescente pois %d esta depois de %d\n", aux->item.chave, zero);
			   	return;
		}
		else{
			zero = aux->item.chave;
		}
		aux = aux->prox;
	}

	printf("\nA fila esta em ordem crescente\n\n");
}
