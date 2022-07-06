/*3. Escreva uma função que recebe duas listas. A primeira guarda n números
inteiros e a segunda está vazia. A função deve inserir os elementos da
primeira lista na segunda lista, de maneira ordenada*/

#include <stdio.h>
#include "Lista.h"

int main(void){

	Lista *l1, *l2;
	l1 = criar();
	l2 = criar();

	insereInicio(l1, 9);
	insereFim(l1, 15);
	insereFim(l1, 67);
	insereFim(l1, 12);
	insereFim(l1, 200);
	insereFim(l1, 53);

	guarda(l1, l2);

	printf("\nLista\n\n");
	imprime(l1);

	printf("\nLista ordenada\n\n");
	imprime(l2);


	libera(l1);
	libera(l2);

	return 0;
}
