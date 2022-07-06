/*3) Crie um TAD Data, composto por dia, mês e ano, e crie a implementação para as seguintes funções
declaradas em um arquivo chamado Data.h:*/

#include <stdio.h>
#include <stdlib.h>
#include "data.h" // TAD

int main(void){

	int idade, dia, mes, ano;

	printf("Informe o dia de nascimento:\n ");
	scanf("%d", &dia);
	printf("Informe o mes de nascimento:\n ");
	scanf("%d", &mes);
	printf("Informe o ano de nascimento:\n ");
	scanf("%d", &ano);

	Data *dt = dataNova(dia, mes, ano);

    idade = calculaIdade(dt);

    imprimirData(dt);

	printf("\nIdade = %d anos\n\n",idade);

	liberarData(dt);
}
