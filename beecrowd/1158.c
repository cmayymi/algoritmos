#include <stdio.h>

int n, x, y;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        int soma = 0;
        if (x%2 == 0) // se x for par, ex x = 4; y = 3;
        {
            x = x+1; // entao x = 5
            for (int j = 0; j < y; j++) // loop do y, pq tem que repetir 3 vezes (y = 3)
            {
                if (x%2 != 0) // se x for impar
                    soma += x;
                x += 2;
            }
        }
        else // se x for impar ex x = 11; y = 2;
        {
            for (int j = 0; j < y; j++) // loop do y
            {
                if (x%2 != 0)
                    soma += x;
                x += 2;
            }
        }
        printf("%d\n", soma);
    }
}