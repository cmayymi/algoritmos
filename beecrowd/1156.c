#include <stdio.h>

float s = 0;
float x = 1;

int main()
{
    for (int i = 1; i <= 39; i+= 2)
    {
        s += i / x;
        x *= 2;
    }
    printf("%.2f\n", s);
}