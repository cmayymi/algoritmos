#include <stdio.h>

long long fatorial(int y); // tem que ser long long pq vai ate 20

int main()
{
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF)
    {
        long long fat_m = fatorial(m);
        long long fat_n = fatorial(n);
        printf("%lld\n", fat_m + fat_n);
    }
}

long long fatorial(int y)
{
    long long x = 1;
    if (y == 0)
        return 1;
    for (int i = 1; i <= y; i++)
    {
        x *= i;
    }
    return x;
}