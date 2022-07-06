#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vacina.h"
#include "time.h"

typedef struct vacina{
	char fornecedor[20];
	char finalidade[20];
	int doses;
	int data;
}Vacina;

Vacina *vacinaNova (char fo[], char fi[], int d){
	Vacina *vc = malloc(sizeof(Vacina));
	strcpy(vc->fornecedor,fo);
	strcpy(vc->finalidade,fi);
	vc->doses = d;
	return(vc);
}
void imprimeVacina(Vacina *vc){
	printf("\n\nFornecedor da vacina: %s", vc->fornecedor);
    printf("\nFinalidade da vacina: %s", vc->finalidade);
    printf("\nNumero de doses: %d\n", vc->doses);
}
void destroiVacina(Vacina *vc){
	free(vc);
}

// parte da data

typedef struct data{
	int dia;
	int mes;
	int ano;

}Data;

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
	printf("Data de validade: %d/%d/%d",dt->dia,dt->mes,dt->ano);
}
void liberarData(Data *dt){
	free(dt);
}


