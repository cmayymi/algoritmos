#include <stdio.h>

// h = 1/2 + 1/3 + 1/4 + ... + 1/n
float n, h;

int main()
{
    while (scanf("%f", &n) && n)
    {
        h += 1/n;
        printf("%.5f\n", h);
    }
}