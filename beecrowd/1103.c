#include <stdio.h>

int h1, m1, h2, m2;

int main()
{
    while (1)
    {
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        if (h1 == 0 && h2 == 0 && m1 == 0 && m2 == 0)
            break;
        
        // calculo das horas
        int tempo = ((h2*60) + m2) - ((h1*60) + m1);
        if (tempo <= 0)
            tempo = tempo + 1440;
        printf("%d\n", tempo);
    }
}