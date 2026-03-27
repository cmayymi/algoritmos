#include <stdio.h>

int n;

int main()
{
    while (scanf("%d", &n) && n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i%n != 0)
                printf("%d ", i);
            else
                printf("%d\n", i);
        }
    }
}