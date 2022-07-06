/*4. Escreva uma fun��o que recebe 3 pilhas encadeadas, sendo que a primeira
guarda n n�meros inteiros e a segunda e a terceira est�o vazias. A fun��o
deve preencher a segunda pilha com todos os n�meros pares encontrados na
primeira pilha, e deve preencher a terceira pilha com todos os n�meros
�mpares encontrados na primeira pilha.*/

#include <stdio.h>
#include "Pilha.h"

int main(void){

	Pilha *p = cria();
	Pilha *p2 = cria();
	Pilha *p3 = cria();

	empilha(p, 1);
	empilha(p, 16);
	empilha(p, 23);
	empilha(p, 6);
	empilha(p, 42);
	empilha(p, 55);
	empilha(p, 9);
	empilha(p, 78);
	empilha(p, 8);
	empilha(p, 96);

	classificar(p, p2, p3);

	printf("\nPilha:");
	imprime(p);

	printf("\nPares:");
	imprime(p2);

	printf("\nImpares:");
	imprime(p3);


	libera(p);
	libera(p2);
	libera(p3);

	return 0;
}
