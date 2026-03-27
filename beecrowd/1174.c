#include <stdio.h>

float a[100];

int main()
{
    for (int i = 0; i < 100; i++)
        scanf("%f", &a[i]);

    for (int i = 0; i < 100; i++)
    {
        if (a[i] <= 10)
            printf("A[%d] = %.1f\n", i, a[i]);
    }
}