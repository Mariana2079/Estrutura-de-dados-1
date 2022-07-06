/*5. Escreva uma função que recebe uma fila encadeada que guarda n números
inteiros e verifica se a fila está ordenada (ordem crescente).*/
#include <stdio.h>
#include "Fila.h"

int main(void){

	Fila *f = cria();

	enfileira(f, 0);
	enfileira(f, 2);
	enfileira(f, 20);
	enfileira(f, 37);
	enfileira(f, 42);
	enfileira(f, 99);

	imprime(f);

	ordem(f);

	libera(f);

	return 0;
}
