/*4) Implemente um programa que utilize o conceito de TAD para criar, imprimir e destruir dados
referentes a Vacinas: Fornecedor, Finalidade, Doses e Data de Validade. Crie uma biblioteca chamada
vacina.h, um arquivo chamado vacina.c e outro arquivo para fazer uso das funções implementadas,
chamado usaTADVacina.c
Obs.: Para o campo data, utilizar o TAD Data criado no exercício anterior.
*/

#include <stdio.h>
#include <stdlib.h>
#include "vacina.h"

int main(void){

	char fornecedor[20], finalidade[20];
	int doses;
	int dia, mes, ano;

	printf("Informe o fornecedor de vacina: ");
	scanf("%[^\n]s",&fornecedor);
	fflush(stdin);
	printf("Informe a finalidade da vacina: ");
	scanf("%[^\n]s",&finalidade);
	fflush(stdin);
	printf("Informe o numero de doses da vacina: ");
	scanf("%d",&doses);


	printf("Informe a data de validade da vacina (dd/mm/aaaa): ");
	scanf("%d/%d/%d",&dia,&mes,&ano);


	Data *dt = dataNova(dia, mes, ano);

	Vacina *vc = vacinaNova(fornecedor, finalidade, doses);


	imprimeVacina(vc);
	imprimirData(dt);

	liberarData(dt);
	destroiVacina(vc);

    return 0;
}
