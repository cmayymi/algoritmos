#include <stdio.h>

int x, y, n;
float resultado = 0;

int main()
{
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        resultado = (float)x/(float)y;
        if (y == 0)
            printf("divisao impossivel\n");
        else 
            printf("%.1f\n", resultado);
    }
}