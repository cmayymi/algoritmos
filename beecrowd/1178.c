#include <stdio.h>

double x;
int n[100];

int main()
{
    scanf("%lf", &x);
    for (int i = 0; i < 100; i++)
    {
        n[i] = x;
        printf("N[%d] = %.4lf\n", i, x);
        x /= 2;
    }
}