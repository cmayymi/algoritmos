#include <stdio.h>

int n, x, y;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);

        int soma = 0;

        // trocar de lugar para que o primeiro numero sempre seja o menor
        if (x > y) // x = 10, y = 5
        {
            int aux = x; // aux = 10
            x = y; // x = 5
            y = aux; // y = 10
        }

        // loop
        for (int j = x + 1; j < y; j++)
        {
            if (j%2 != 0)
                soma += j;
        }
        printf("%d\n", soma);
    }
}