#include <stdio.h>

int t; // t = testes
int pa, pb; // pop a e pop b
double g1, g2; // taxa de crescimento da populacao

int main()
{
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %lf %lf", &pa, &pb, &g1, &g2);
        int anos = 0;
        while (pa <= pb && anos <= 100)
        {
            pa += (int)(pa * g1/100);
            pb += (int)(pb * g2/100);
            anos++;
        }
        if (anos > 100)
            printf("Mais de 1 seculo.\n");
        else
            printf("%d anos.\n", anos);
        
    }
}