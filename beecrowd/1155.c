#include <stdio.h>

float s = 0;

int main()
{
    for (int i = 1; i <= 100; i++)
        s += 1.0/i;
    printf("%.2f\n", s);
}