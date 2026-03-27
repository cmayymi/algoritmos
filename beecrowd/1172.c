#include <stdio.h>

int x[10];

int main()
{
    for (int i = 0; i < 10; i++)
        scanf("%d", &x[i]);
    
    // escreve o vetor
    for (int i = 0; i < 10; i++)
    {
        if (x[i] <= 0)
            printf("X[%d] = 1\n", i);
        else
            printf("X[%d] = %d\n", i, x[i]);
    }
}