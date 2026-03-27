#include <stdio.h>

// variaveis
int x;
int valores[50]; // declara valores como um vetor de 50 posicoes
int i; // indice do vetor
int s; // soma de todos os inputs
int media; // media

int main()
{
    while (x != EOF)
    {
        // le o vetor
        for (i = 0; i < 50; i++)
            scanf("%d", &valores[50]);
            // soma todos e faz o calculo da media
            s += valores[50];
            media = s/i;
        printf("%d\n", media);

        // escreve o vetor
    }
}