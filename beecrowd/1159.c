#include <stdio.h>

int x;

int main()
{
    while(scanf("%d", &x) && x)
    {
        int soma = 0;
        // print a soma de 5 numeros pares consecutivos de x (incluindo x)
        if (x%2 != 0) // se x for impar
            x++; // soma mais um para deixar ele par
        
        for (int i = 0; i < 5; i++)
        {
            if (x%2 == 0) // se x for par
                soma += x;
            x += 2;
        }
        printf("%d\n", soma);
    }
}