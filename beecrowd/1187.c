#include <stdio.h>

double M[12][12]; // memoria alocada para a matriz
int linha; // linha da matriz
int coluna; // coluna da matriz
double soma = 0;
int contagem = 0;
char operador;

int main()
{
    scanf("%c", &operador);
    // percorrer a matriz e somar os elementos onde coluna < linha

    // leitura da matriz
    for (linha = 0; linha < 12; linha++)
    {
        for (coluna = 0; coluna < 12; coluna++)
            scanf("%lf", &M[linha][coluna]);
    }

    // calculo
    for (linha = 0; linha < 5; linha++)
    {
        for (coluna = 1 + linha; coluna < 11 - linha; coluna++)
        {
            soma += M[linha][coluna];
            contagem++;
        }
    }
    switch (operador)
    {
    case 'S':
        printf("%.1lf\n", soma);
        break;

    case 'M':
        printf("%.1lf\n", soma/contagem);
        break;
    }
    return 0;
}