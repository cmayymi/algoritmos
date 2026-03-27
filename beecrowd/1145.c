#include <stdio.h>

int x, y, aux; // y tem que ser maior que x

int main()
{
    scanf("%d %d", &x, &y);
    if (x > y)
    {
        aux = x;
        x = y;
        y = aux;
    }
    for (int i = 1; i <= y; i++)
    {
        if (i%x != 0)
            printf("%d ", i);
        else
            printf("%d\n", i);
    }
}