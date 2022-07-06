#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};
    FILE *arq;

    ArvBin* raiz = cria_ArvBin();

    int vazia = estaVazia_ArvBin(raiz);
    printf("Arvore vazia? %d", vazia);
    int i;
    char texto[50] = "Dados da árvore binária gravados: \n";
    arq = fopen("exemploArqTxt.txt", "w");
    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo.\n");
        system("pause");
        exit(1);
    }

    for(i=0; i < N; i++)
    {
        insere_ArvBin(raiz,dados[i]);
        fprintf(arq, ".Item[%d]: %d\n", i, dados[i]);
    }

    fclose(arq);
    vazia = estaVazia_ArvBin(raiz);
    printf("\nArvore vazia? %d\n", vazia);

    printf("Total nos: %d\n", totalNO_ArvBin(raiz));

    printf("Impressao de arvore binaria em preOrdem: \n");
    preOrdem_ArvBin(raiz);
    printf("\nImpressao de arvore binaria em posOrdem: \n");
    posOrdem_ArvBin(raiz);
    printf("\nImpressao de arvore binaria em Ordem: \n");
    emOrdem_ArvBin(raiz);

    printf("\nItem 30 esta na arvore? %d \n", consulta_ArvBin(raiz, 30));

    printf("\nRemocao de item 30: \n");
    remove_ArvBin(raiz, 30);
    printf("Total nos: %d\n", totalNO_ArvBin(raiz));
    printf("\nImpressao de arvore binaria em Ordem: \n");
    emOrdem_ArvBin(raiz);

    libera_ArvBin(raiz);

    printf("\nLeitura dos dados gravados em arquivo TXT: \n");
    arq = fopen("exemploArqTxt.txt", "r");
    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo.\n");
        system("pause");
        exit(1);
    }

    char rotulo[30];
    for (i = 0; i < N; i++)
    {
        fscanf(arq, "%s %s", rotulo, texto);
        printf("%s %s \n", rotulo, texto);
    }
    fclose(arq);

    return 0;
}
