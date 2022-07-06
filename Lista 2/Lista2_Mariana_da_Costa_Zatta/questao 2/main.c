/*2. Escreva uma função que recebe duas listas encadeadas e concatena as duas
(liga a segunda lista no final da primeira lista).*/

#include <stdio.h>
#include "Lista.h"

int main(void){

	Lista *l1, *l2;
	l1 = criar();
	l2 = criar();

	insereInicio(l1, 7);
	insereFim(l1, 15);
	insereMeio(l1, 42, 7);
	insereFim(l1, 1);
	insereMeio(l1, 22, 42);
	insereFim(l1, 14);
	remover(l1, 1);

	printf("\n");
	imprime(l1);

	insereInicio(l2, 9);
	insereFim(l2, 13);
	insereMeio(l2, 37, 9);
	insereFim(l2, 17);
	insereMeio(l2, 4, 13);
	insereFim(l2, 3);

	printf("\n");
	imprime(l2);

	concatena(l1, l2);

	printf("\n");
	imprime(l1);



	libera(l1);
	libera(l2);

	return 0;
}
