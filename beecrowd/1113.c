#include <stdio.h>

int x, y;

int main()
{
    while(scanf("%d %d", &x, &y))
    {
        if (x == y)
            break;
        else
        {
            if (x > y)
                printf("Decrescente\n");
            else 
                printf("Crescente\n");
        }
    }
}