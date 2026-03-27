#include <stdio.h>

int n;
float x;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x);
        // a criatura come metade da sua comida disponivel por dia
        // calcula quantos dias ate que ele coma tudo ou deixe 1kg ou menos
        int dias = 0;
        while (x > 1)
        {
            x /= 2;
            dias++;
        }
        printf("%d dias\n", dias);
    }
}