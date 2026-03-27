#include <stdio.h>

float M[12][12]; // memoria alocada para a matriz
int linha; // linha da matriz
int coluna; // coluna da matriz
float soma = 0;
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
            scanf("%f", &M[linha][coluna]);
    }

    // calculo do triangulo superior
    for (linha = 1; linha < 6; linha++)
    {
        for (coluna = 12 - linha; coluna < 12; coluna++)
        {
            soma += M[linha][coluna];
            contagem++;
        }
    }

    // calculo do triangulo inferior
    for (linha = 6; linha < 11; linha++) 
    {
        for (coluna = linha + 1; coluna < 12; coluna++)
        {
            soma += M[linha][coluna];
            contagem++;
        }
    }

    switch (operador)
    {
    case 'S':
        printf("%.1f\n", soma);
        break;

    case 'M':
        printf("%.1f\n", soma/contagem);
        break;
    }
    return 0;
}