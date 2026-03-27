#include <stdio.h>

int n, x;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        if (x == 0)
        {
            printf("Fib(0) = 0\n");
            continue;
        }
        if (x == 1)
        {
            printf("Fib(1) = 1\n");
            continue;
        }

        long long f0 = 0, f1 = 1, s;
        for (int j = 2; j <= x; j++)
        {
            s = f0 + f1;
            f0 = f1;
            f1 = s;
        }
        printf("Fib(%d) = %lld\n", x, s);
    }
}