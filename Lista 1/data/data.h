#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

typedef struct data Data;

Data *dataNova(int d, int m, int a);
Data *dataHoje(void);
int calculaIdade(Data *dt);
void imprimirData(Data *dt);
void liberarData(Data *dt);

#endif

