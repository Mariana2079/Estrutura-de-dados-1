#ifndef VACINA_H_INCLUDED
#define VACINA_H_INCLUDED

typedef struct vacina Vacina;

Vacina *cadastraVacina(char fo[], char fi[], int d);
void imprimeVacina(Vacina *vc);
void destroiVacina(Vacina *vc);

typedef struct data Data;

Data *dataNova(int d, int m, int a);
Data *dataHoje(void);
int calculaIdade(Data *dt);
void imprimirData(Data *dt);
void liberarData(Data *dt);

#endif

