#include "Lista.h"

struct item {
    int chave;
};

struct celula{
	Item item;
	Celula *prox;
};

struct lista{
    Celula *primeira;
};


Lista *criar(){
	Lista *l = malloc(sizeof(Lista));
	l->primeira = NULL;
	return l;
}

void libera(Lista *l){
	Celula *aux = l->primeira;
	Celula *liberar;
	while(aux != NULL){
		liberar = aux;
		aux = aux->prox;
		free(liberar);
	}
	free(l);
}

int verifica(Lista *l){
	return l->primeira == NULL;
}

Celula* busca(Lista *l, int x){
	Celula *aux = l->primeira;
	while(aux != NULL && aux->item.chave != x){
		aux = aux->prox;
	}
	return aux;
}

void imprime(Lista *l){
	Celula *aux;
	for(aux=l->primeira; aux!=NULL; aux=aux->prox){
		printf("Chave: %d\n", aux->item.chave);
	}
}

void insereInicio(Lista *l, int x){
	Item novo;
	novo.chave = x;
	Celula *nova = malloc(sizeof(Celula));
	nova->item = novo;
	nova->prox = l->primeira;
	l->primeira = nova;
}

void insereMeio(Lista *l, int x, int a){
	Celula *aux = busca(l, a);
	if(aux != NULL){
		Item novo;
		novo.chave = x;
		Celula *nova = malloc(sizeof(Celula));
		nova->item = novo;
		nova->prox = aux->prox;
		aux->prox = nova;
	}
	else{
		printf("O item não existe");
	}
}

void insereFim(Lista *l, int x){
	Item novo;
	novo.chave = x;
	Celula *nova = malloc(sizeof(Celula));
	nova->item = novo;
	nova->prox = NULL;
	if(verifica(l)){
		l->primeira = nova;
	}
	else{
		Celula *ultima;
		ultima = l->primeira;
		while(ultima->prox != NULL){
			ultima = ultima->prox;
		}
		ultima->prox = nova;
	}
}

void remover(Lista *l, int x){
	Celula *aux = l->primeira;
	Celula *anterior;
	while(aux != NULL && aux->item.chave != x){
		anterior = aux;
		aux = aux->prox;
	}
	if(aux == NULL){
		printf("ERRO");
		return;
	}
	if(aux == l->primeira){
		l->primeira = aux->prox;
	}
	else{
		anterior->prox = aux->prox;
	}
	free(aux);
}



int tamanho(Lista *l) {
   Celula *aux = l->primeira;
   int i = 0;
   while(aux != NULL) {
      aux = aux->prox;
      i++;
   }
   return i;
}



void trocar(Celula *a, Celula *b){
    int temp = a->item.chave;
    a->item.chave = b->item.chave;
    b->item.chave = temp;
}
void ordena(Celula *aux) {
    if(aux == NULL){
    	printf("\nErro, a lista esta vazia.");
        return;
	}
	int trocado;
    Celula *ptr1;
    Celula *ptr2 = NULL;
	do{
        trocado = 0;
		for( ptr1 = aux; ptr1->prox != ptr2; ptr1 = ptr1->prox){
            if (ptr1->item.chave > ptr1->prox->item.chave){
                trocar(ptr1, ptr1->prox);
                trocado = 1;
            }
        }
        ptr2 = ptr1;
    }
    while(trocado);
}


void copia(Lista *l1, Lista *l2){
	Celula *aux;
	for(aux=l1->primeira; aux!=NULL; aux=aux->prox){
		!verifica(l2) ? insereFim(l2, aux->item.chave) : insereInicio(l2, aux->item.chave);
	}
}

void guarda(Lista *l1, Lista *l2){
	if(verifica(l1)){
		printf("Primeira lista deve conter elementos\n");
		return;
	}
	if(!verifica(l2)){
		printf("Segunda lista deve estar vazia\n");
		return;
	}

	copia(l1, l2);
	Celula *ini = l2->primeira;
	ordena(ini);

}
