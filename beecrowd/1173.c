#include <stdio.h>

int n[10], x;

int main()
{
    scanf("%d", &x);
    int v = x; // v = 2
    for (int i = 0; i < 10; i++)
    {
        printf("N[%d] = %d\n", i, v);
        v *= 2;
    }
}