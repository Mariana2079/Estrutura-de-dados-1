#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct nome{
	char nomes[200];
}Nome;

//pesquisa binaria
int pesquisaBinaria(Nome *no, int n, char *chave) {
    int primeiro = 0;
    int ultimo = n - 1;
    int meio;
    while (primeiro <= ultimo) {
        meio = (primeiro + ultimo) / 2;
        if (strcmp(no[meio].nomes,chave)==0) {
            return;
        } else if (strcmp(no[meio].nomes,chave)< 0) {
            ultimo = meio - 1;
        } else {
            primeiro = meio + 1;
        }
    }
    return -1;
}

//Ordenação por Inserção
void insertionSort(Nome *no, int n)
{
    int i, j;
    char x[200];

    for (i = 1; i < n; i++)
    {
        strcpy(x,no[i].nomes);
        j = i - 1;
        while (j >= 0 && (strcmp (no[j].nomes,x)>0)){
            strcpy(no[j+1].nomes,no[j].nomes);
            j--;
        }
        strcpy(no[j+1].nomes,x);
    }
}

//Ordenação por Seleção
void selectionSort(Nome *no, int n)
{
    int i, j, min;
    char aux[200];

    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
        {
            if (strcmp(no[j].nomes,no[min].nomes)<0)
            {
                min = j;
            }
        }
        strcpy(aux,no[i].nomes);
        strcpy(no[i].nomes,no[min].nomes);
        strcpy(no[min].nomes,aux); //troca
    }
}

//Ordenação pelo método bolha
void bubbleSort(Nome *no, int n)
{
    int i, j;
    Nome aux;

    for (i = n-1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (strcmp(no[j].nomes,no[j+1].nomes)>0)
            {
                strcpy(aux.nomes,no[j].nomes);
                strcpy(no[j].nomes,no[j+1].nomes);
                strcpy(no[j+1].nomes,aux.nomes); //troca
            }
        }
    }
}

//Ordenação pelo método QuickSort
void quickSort(Nome *no, int esq, int dir)
{
    int pivo = esq, i, j;
    Nome ch;

    for (i = esq + 1; i <= dir; i++)
    {
        j = i;
        if (strcmp(no[j].nomes,no[pivo].nomes)<0)
        {
            strcpy(ch.nomes,no[j].nomes);
            while (j > pivo)
            {
                strcpy(no[j].nomes,no[j-1].nomes);
                j--;
            }
            strcpy(no[j].nomes,ch.nomes);
            pivo++;
        }
    }
    if (pivo-1 >= esq)
    {
        quickSort(no, esq, pivo -1);
    }
    if (pivo + 1 <= dir)
    {
        quickSort(no, pivo+1, dir);
    }
}

//Ordenação pelo Método MergeSort
void mergeSort(Nome *no, int posicaoInicio, int posicaoFim)
{
    int i, j, k, metadeTamanho;
    Nome *vetorTemp;
    if (posicaoInicio == posicaoFim)
        return;
    metadeTamanho = (posicaoInicio + posicaoFim) / 2;
    mergeSort(no, posicaoInicio, metadeTamanho);
    mergeSort(no, metadeTamanho + 1, posicaoFim);
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (Nome *) malloc(sizeof(Nome) * (posicaoFim - posicaoInicio + 1));
    while (i < metadeTamanho + 1 || j < posicaoFim + 1)
    {
        if (i == metadeTamanho + 1)
        {
            strcpy(vetorTemp[k].nomes,no[j].nomes);
            j++;
            k++;
        }
        else
        {
            if (j == posicaoFim + 1)
            {
                strcpy(vetorTemp[k].nomes,no[i].nomes);
                i++;
                k++;
            }
            else
            {
                if (strcmp(no[i].nomes,no[j].nomes)<0)
                {
                    strcpy(vetorTemp[k].nomes,no[i].nomes);
                    i++;
                    k++;
                }
                else
                {
                    strcpy(vetorTemp[k].nomes,no[j].nomes);
                    j++;
                    k++;
                }
            }
        }

    }
    for (i = posicaoInicio; i <= posicaoFim; i++)
    {
        strcpy(no[i].nomes,vetorTemp[i - posicaoInicio].nomes);
    }
    free(vetorTemp);
}


int main(void)
{
    int n, i, opcao,retorno;
    Nome *no,*item;

    printf("Entre com o tamanho desejado do vetor: ");
    scanf("%d", &n);
    printf("Informe os nomes para o vetor: \n");



    for (i = 0; i < n; i++)
    {
    	if (i == 0){
			no = (Nome *) malloc(sizeof(Nome));
		}
		else{
			no = (Nome *) realloc(no, i * sizeof(char));
        }
        scanf("%s",&no[i]);
        fflush(stdin);
	}

	printf("\nVetor original:\n");
            for (i = 0; i < n; i++)
            {
                printf("%s\t", no[i].nomes);
            }
            printf("\n");

    do
    {
        printf("\nOpcoes de algoritmos de ordenacao:\n");
        printf("1 - Insercao \n2- Selecao \n3 - Bolha \n4 - QuickSort \n5 - MergeSort\n");
        printf("Indique um numero de algoritmo ou 0 para fazer busca binaria: \n\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            insertionSort(no, n);
            break;
        case 2:
            selectionSort(no, n);
            break;
        case 3:
            bubbleSort(no, n);
            break;
        case 4:
            quickSort(no, 0, n-1);
            break;
        case 5:
            mergeSort(no, 0, n-1);
            break;
        case 0:
            break;
        }
        if (opcao != 0)
        {
            printf("\nVetor ordenado:\n");
            for (i = 0; i < n; i++)
            {
                printf("%s\t", no[i].nomes);
            }
            printf("\n");
        }

    }
    while (opcao != 0);

    printf("Informe o item a ser pesquisado: ");
    scanf("%s", &item);
    item = (Nome *) malloc(sizeof(Nome));
    retorno = pesquisaBinaria(no,n,item);
    printf("\n\nPosicao do item no vetor: %d\n",retorno);

    return 0;
}
