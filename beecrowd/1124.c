#include <stdio.h>
#include <math.h>

int l, c, r1, r2; // l = largura; c = comprimento; r1 e r2 = raio

int main()
{
    while(1)
    {
        scanf("%d %d %d %d", &l, &c, &r1, &r2); 
        if (l == 0 && c == 0 && r1 == 0 && r2 == 0)
            break;

        // calculo
        int soma_raio = (r1*2) + (r2*2); // 10
        if (soma_raio < l || soma_raio < c)
        {
            printf("S\n");
            continue;
        }
        else
        {
            printf("N\n");
            continue;
        }

        int espaco_horizontal = l - r1 - r2;
        int espaco_vertical = c - r1 - r2;

        if (espaco_horizontal >= 0 && espaco_vertical >= 0)
        {
            if (pow(espaco_horizontal,2) + pow(espaco_vertical,2) >= (r1 + r2) * (r1 + r2))
            {
                printf("S\n");
                continue;
            }
        }
    }
}