#include <stdio.h>

int n[20], i;

int main()
{
    for (i = 0; i < 20; i++)
        scanf("%d", &n[i]);
    
    int valor = 0;
    for (i = 19; i >= 0; i--)
    {
        printf("N[%d] = %d\n", valor, n[i]);
        valor++;
    }
}