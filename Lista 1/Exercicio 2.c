/*2) Crie uma função que recebe o limite inferior e o limite superior de um intervalo e tem como objetivo retornar
um vetor com todos os inteiros pertencentes ao intervalo.
• A alocação de memória deve ocorrer dinamicamente para cada novo item acrescentado no vetor.
• Crie um programa para mostrar o uso dessa função.*/

#include <stdio.h>
#include <stdlib.h>

void limites(int inferior, int superior){

	int *vetor;

	for(int i=inferior; i<=superior; i++){
		if (i == inferior){
			vetor = (int *) malloc(sizeof(int));
		}
		else{
			vetor = (int *) realloc(vetor, i * sizeof(int));
		}
		printf("%d   " ,i);
	}
}

int main(void){
	int inferior, superior;

	printf("Informe o limite inferior: ");
	scanf("%d",&inferior);
	printf("Informe o limite superior: ");
	scanf("%d",&superior);

	limites(inferior,superior);

	return 0;
}
