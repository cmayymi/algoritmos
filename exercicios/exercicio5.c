// utilizando a funcao soma do exericio 4, construa uma funcao que receba como parametro um vetor v
// e um inteiro n e retorne o valor da media dos elementos do vetor
#include <stdio.h>
// funcao soma dos elementos do vetor
float soma_vetorial(float V[], int n)
{
    float soma = 0; // valor do retorno
    for (int i = 0; i < n; i++)
        soma += V[i];
    return soma;
}

float media_vetorial(float V[], int n)
{
    float media = 0;
    media = soma_vetorial(V, n)/n;
    return media;
}

int main()
{
    int size = 10;
    float A[50]; // declara o vetor
    for (int i = 0; i < size; i++) // criacao do vetor
        A[i] = i + 1;

    printf("Media de A = %f\n\n", media_vetorial(A, size));
    return 0;
}