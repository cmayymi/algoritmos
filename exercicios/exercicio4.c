// escreva uma funcao que receba como parametros um vetor V de reais (max 50 posicoes) 
// e um inteiro n que representa o numero de elementos validos em V e retorne a soma dos elementos de V
#include <stdio.h>
// funcao soma dos elementos do vetor
float soma_vetorial(float V[], int n)
{
    float soma = 0; // valor do retorno
    for (int i = 0; i < n; i++)
        soma += V[i];
    return soma;
}

// funcao para imprimir o vetor (procedimento)
void print_vetor(float V[], int n)
{
    printf("(");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f", V[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf(")");
}

int main()
{
    int size = 10;
    float A[50]; // declara o vetor
    for (int i = 0; i < size; i++) // criacao do vetor
        A[i] = i + 1;

    print_vetor(A, size);
    printf("\n");
    printf("Soma de A = %f\n\n", soma_vetorial(A, size));
    return 0;
}

