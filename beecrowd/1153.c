#include <stdio.h>

unsigned n, x;

int main()
{
    // calcular a fatorial de um numero n
    scanf("%d", &n);

    x = 1;
    for (int i = 1; i <= n; i++)
    {
        x *= i;
    }
    printf("%u\n", x);
}