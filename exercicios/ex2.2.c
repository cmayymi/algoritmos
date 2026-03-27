#include <stdio.h>

int s, f0, f1;
unsigned n;

// serie de fibonacci
int main()
{
    while (scanf("%u", &n) != EOF)
    {
        s = 1;
        f0 = 1;
        f1 = 1;
        for (int i = 2; i <= n; i++)
        {
            s = f0 + f1;
            f0 = f1;
            f1 = s;
        }
        printf("%d\n", s);
    }
}