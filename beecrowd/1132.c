#include <stdio.h>

int x, y, aux;
int soma = 0;

int main()
{
    scanf("%d %d", &x, &y);
    // print a soma de todos os numeros entre x e y nao divisivel por 13, incluindo eles
    if (x > y) // x = 5 e y = 10
    {
        aux = x; 
        x = y; 
        y = aux;
    }
    if (x < y)
    {
        for (int i = x; i <= y; i++) // int i = x, pq x e o valor minimo
        {                            // i <= y, pq vai ate o valor maximo (y)
            if (i%13 != 0)
                soma += i;
        }
    }
    printf("%d\n", soma);
}