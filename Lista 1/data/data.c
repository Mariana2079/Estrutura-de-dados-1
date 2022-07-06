/*3) Crie um TAD Data, composto por dia, mês e ano, e crie a implementação para as seguintes funções
declaradas em um arquivo chamado Data.h:*/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "data.h"

struct data{
	int dia;
	int mes;
	int ano;
};

Data *dataNova(int d, int m, int a){
	Data *dt = malloc(sizeof(Data));
	dt->dia = d;
	dt->mes = m;
	dt->ano = a;

	return(dt);
}
Data *dataHoje(void){
	Data *dt = malloc(sizeof(Data));
	time_t tempo;
	struct tm *hj;
	tempo = time(NULL); // obtem o tempo corrente
	hj = localtime(&tempo); // obtem a data do sistema operacional
	dt->dia = hj->tm_mday;
	dt->mes = hj->tm_mon + 1;
	dt->ano = hj->tm_year + 1900;

	return(dt);
}
int calculaIdade(Data *dt){

	Data *hj = dataHoje();

	int idade;

	idade = hj->ano - dt->ano;

	if((hj->mes < dt->mes) || ((hj->mes == dt->mes) && (hj->dia < dt->dia))){
		idade--;
	}

	return(idade);
}
void imprimirData(Data *dt){
	printf("%d/%d/%d",dt->dia,dt->mes,dt->ano);
}
void liberarData(Data *dt){
	free(dt);
}





