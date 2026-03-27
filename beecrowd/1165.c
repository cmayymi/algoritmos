#include <stdio.h>

int n, x;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        int divisao = 0;
        for (int j = 1; j <= x; j++)
        {
            if (x%j == 0)
                divisao++;
        }
        if (divisao == 2)
            printf("%d eh primo\n", x);
        else
            printf("%d nao eh primo\n", x);
    }
}