#include <stdio.h>

int n, quantidade = 0;
int soma = 0;

int main()
{
    while (1)
    {
        scanf("%d", &n);
        if (n < 0)
            break;
        soma += n;
        quantidade++;
    }
    float media = (float)soma / quantidade;
    printf("%.2f\n", media);
}