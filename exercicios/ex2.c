#include <stdio.h>

unsigned n, x;

int main()
{
    // calcular a fatorial de um numero n
    while (scanf("%u", &n) != EOF)
    {
        x = 1;
        for (int i = 1; i <= n; i++)
        {
            x *= i;
        }
        printf("%u\n", x);
    }
}