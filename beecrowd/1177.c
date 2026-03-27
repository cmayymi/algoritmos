#include <stdio.h>

int t, n[1000];

int main()
{
    scanf("%d", &t);
    for (int i = 0; i < 1000; i++)
    {
        n[i] = i%t; // pq i = 0, vai dar 0, i = 1
    }
    for (int i = 0; i < 1000; i++)
            printf("N[%d] = %d\n", i, n[i]);
}