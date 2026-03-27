#include <stdio.h>
#include <math.h>

int n;

int main()
{
    scanf("%d", &n);
    for (float i = 1; i <= n; i++)
    {
        printf("%.0f %.0f %.0f\n", i, pow(i,2), pow(i,3));
    }
}