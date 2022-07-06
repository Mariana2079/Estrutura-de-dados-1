/*1) Crie um programa que armazena um número dinâmico de Imóveis com os seguintes dados: Descrição,
Endereço e Valor. Após informar os dados de um imóvel o usuário deve informar se pretende fazer um novo
cadastro ou não. Após finalizar os cadastros, o programa deve imprimir os dados informados.
Obs.: Deve-se fazer uso das funções malloc ou calloc, realloc e free*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
typedef struct imovel Imovel;
	struct imovel {
	 float valor;
	 char descricao[30];
	 char endereco[30];
};
int main(void){
	 setlocale(LC_ALL,"portuguese");
	 Imovel *im;

	 int continua = 1;
	 int i = 0;

	 while (continua == 1) {
		 printf("========CADASTRO DE IMÓVEIS========\n");
		 printf("\nInforme os dados do imovel %d:\n\n", i+1);
		if (i == 0){
			im = (Imovel *) malloc(sizeof(Imovel));
		}
		else{
			im = (Imovel *) realloc(im, i * sizeof(Imovel));
        }
		if (im) {
		 printf("Descricao do imovel: ");
		 scanf(" %[^\n]s", im[i].descricao);
		 printf("Endereco: ");
		 scanf(" %[^\n]s", im[i].endereco);
		 printf("Valor: ");
		 scanf("%f", &im[i].valor);
		 printf("\nDeseja informar dados de um novo imovel? (0-Nao/1-Sim): ");
		 scanf("%d", &continua);
		}
		i++;
	 }
	if (im) {
		 printf("\n\n========CADASTRADO COM SUCESSO========\n");
		 printf("\n\nDados dos imoveis: ");
		 for(int j = 0; j < i; j++) {
			 printf("\n\nImovel %d:\n", j+1);
			 printf("\nDescricao do imovel: %s", im[j].descricao);
			 printf("\nEndereco do imovel: %s", im[j].endereco);
			 printf("\nValor: R$%.2f\n\n", im[j].valor);
			}
			free(im);
	}
	 return 0;
}
