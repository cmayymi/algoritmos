#include <stdio.h>

int x, y;
int quadrado_soma(int a, int b);

int main()
{
    while (scanf("%d %d", &x, &y) != EOF)
    {
        printf("f1(%d, %d\n) = %d", x, y, quadrado_soma(x,y));
    }
    
}

int quadrado_soma(int a, int b)
{
    int f = 0;
    f = (a*a) + (2*a*b) + (b*b);
    return f;
}