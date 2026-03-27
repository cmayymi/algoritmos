#include <stdio.h>

int m, n, aux;

int main()
{
    while (1)
    {
        scanf("%d %d", &m, &n);
        if (m <= 0 || n <= 0)
            break;

        if (m > n)
        {
            aux = m; // m menor
            m = n;
            n = aux; // n maior
        }
        int soma = 0;
        for (int i = m; i <= n; i++)
        {
            soma += i;
            printf("%d ", i);
        }
        printf("Sum=%d\n", soma);
    }
}