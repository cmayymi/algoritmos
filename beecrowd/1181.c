#include <stdio.h>



int main()
{
    float m[12][12]; 
    int linha;
    char operacao;
    float soma = 0;

    scanf("%d", &linha);
    scanf(" %c", &operacao);

    // le a matriz
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            scanf("%f", &m[i][j]);

    for (int i = 0; i < 12; i++)
        soma += m[linha][i];

    switch (operacao)
    {
    case 'S':
        // soma
        printf("%.1f\n", soma);
        break;
    
    case 'M':
        // media
        printf("%.1f\n", soma/12);
        break;
    
    default:
        break;
    }

    return 0;
}