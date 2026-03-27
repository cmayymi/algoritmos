#include <stdio.h>

int n, s, f0 = 0, f1 = 1;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            printf("%d", f0); // primeiro numero
        else if (i == 1)
            printf(" %d", f1); // segundo numero
        else
        {
            s = f0 + f1;
            f0 = f1;
            f1 = s;
            printf(" %d", s);
        }
    }
    printf("\n");
}