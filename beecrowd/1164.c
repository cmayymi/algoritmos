#include <stdio.h>

int n, x;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) // loop do scan
    {
        scanf("%d", &x);
        int soma = 0;
        for (int j = 1; j < x; j++) // loop soma
        {
            soma += j;
            if (soma == x)
                break;
        }
        if (soma == x)
            printf("%d eh perfeito\n", x);
        else
            printf("%d nao eh perfeito\n", x);
    }
}