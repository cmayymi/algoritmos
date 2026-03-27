#include <stdio.h>

int x; // quantidade de regioes
int y; // tamanho do salto
int i, j, k; // indices
int fila[100]; // estrutura com as estacoes a serem desligadas

int main()
{
    // ler os casos de teste
    while (scanf("%d", &x) && x)
    {
        y = 0;
        // determine the smallest number m that will ensure that region 13
        // can function while the rest of the country is blacked out
        for (j = 0; j < x; j++)
            fila[j] = j+1; // pq o zero vai receber o 1

        // tenta achar um valor de salto que termine em 13
        while (fila[0] != 13)
        {
            y++;
            // recriar o vetor de tamanho x para conter as cidades
            i = x;
            for (j = 0; j < i; j++)
                fila[j] = j + 1;

            // processar a fila de cidades
            j = 0;
            while (i > 1)
            {
                // apaga a cidade da posicao j da fila
                for (k = j; k < i - 1; k++)
                    fila[k] = fila[k+1];
                fila[k] = 0; // zerar a ultima posicao da fila
                i--;
                // salta para a proxima cidade a ser apagada
                j = (j + y - 1)%i; //se j = 0, y = 7, i = 5; 6%5 = 1, vai pra posicao 1, ou seja prox regiao
            }
        }
        printf("%d\n", y);
    }
}