#include <stdio.h>

float s, denominador, numerador, n;

int main()
{
    // S = 1/N + 2/(N - 1) + 3/(n - 2) + ... + (N - 1)/2 + N/1
    // S tem que ter 1 casa decimal

    while (scanf("%f", &n) != EOF && n)
    {
        s = 0;
        denominador = n;
        numerador = 1;
        for (int i = 0; i < n; i++)
        {
            s += numerador/denominador;
            numerador += 1;
            denominador -= 1;
        }
        printf("%.1f\n", s);
    }
}