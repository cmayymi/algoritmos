#include <stdio.h>

int x, y;
int soma = 0;

int main()
{
    scanf("%d", &x);
    do
    {
        scanf("%d", &y);
    } while (y <= 0);
    
    // printa a soma de y numeros comecando de x, mas inclusive
    // logo, se y = 2, e x = 3
    // 3 + 0 e 3 + 1 = 4
    // 4 + 3 = 7 (resultado)
    for (int i = 0; i < y; i++)
        soma += i + x;
    printf("%d\n", soma);
}