#include <stdio.h>

int n;

int main()
{
    scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    
    int y = x[0];
    int posicao = 0;
    for (int i = 0; i < n; i++)
    {
        if (y > x[i])
        {
            y = x[i];
            posicao = i;
        }
    }
    printf("Menor valor: %d\n", y);
    printf("Posicao: %d\n", posicao);
}