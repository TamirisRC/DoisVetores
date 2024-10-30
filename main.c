#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "interface.h"

int main(void)
{
    int size = QTD_ELEM - 1;
    int vetor[QTD_ELEM];

    gerarValores(vetor);


    buildHeap(vetor, QTD_ELEM);

    imprimiVetor(vetor);

    determinaDoisMaioresElementos(vetor);
}

void gerarValores(int vetor[])
{
    srand(time(0));

    for (int i = 0; i < QTD_ELEM; i++)
    {
        vetor[i] = rand() / 100;
    }
}

void imprimiVetor(int vetor[])
{
    printf("=========================================\n");
    for (int i = 0; i < QTD_ELEM; i++)
    {
        printf("%i\n", vetor[i]);
    }
    printf("=========================================\n");
}

void sift(int i, int n, int vetor[])
{
    int elementoEsquerdo = 2 * i + 1;
    int elementoDireito = 2 * i + 2;
    int elementoMaior = i;

    if (elementoEsquerdo <= n && vetor[elementoEsquerdo] > vetor[elementoMaior])
       elementoMaior = elementoEsquerdo;

    if (elementoDireito<= n && vetor[elementoDireito] > vetor[elementoMaior])
        elementoMaior = elementoDireito;

    if (elementoMaior != i)
    {
        int aux = vetor[i];
        vetor[i] = vetor[elementoMaior];
        vetor[elementoMaior] = aux;
        sift(elementoMaior, n, vetor);
    }
}

void buildHeap(int vetor[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        sift(i, n - 1, vetor);
    }
}

void determinaDoisMaioresElementos(int vetor[])
{
    int maior2 = vetor[1] > vetor[2] ? vetor[1] : vetor[2];

    printf("Os dois maiores elementos do vetor: \n%i\n%i", vetor[0], maior2);
}