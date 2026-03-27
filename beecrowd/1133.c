#include <stdio.h>

unsigned x, y;
int aux;

int main()
{
    scanf("%u %u", &x, &y);
    // printa todos os numeros entre x e y de forma crescente
    // que dividindo por 5 o resto é 2 ou 3
    if (x > y) // troca de valores, deixando sempre o y como valor max
    {
        aux = x; 
        x = y; 
        y = aux;
    }

    if ((x%5 == 2) || (x%5 == 3)) // como o x nao pode entrar no loop, faz isso
        x = x + 1;

    if (x < y)
    {
        for (int i = x; i < y; i++) // int i = x, pq x e o valor minimo
        {                            // i <= y, pq vai ate o valor maximo (y)
            if ((i%5 == 2) || (i%5 == 3))
                printf("%u\n", i);
        }
    }
}