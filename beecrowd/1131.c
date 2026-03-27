#include <stdio.h>

int x, y, g; // g = novo grenal, x = inter, y = gremio
int grenal = 1;
int golinter = 0;
int golgremio = 0;
int empate = 0;

int main()
{
    while(1)
    {
        scanf("%d %d", &x, &y);
        if (x > y)
            golinter++;
        else if (x < y)
            golgremio++;
        else
            empate++;
        do
        {
            printf("Novo grenal (1-sim 2-nao)\n");
            scanf("%d", &g);
            if (g == 2)
            {
                printf("%d grenais\n", grenal);
                printf("Inter:%d\n", golinter);
                printf("Gremio:%d\n", golgremio);
                printf("Empates:%d\n", empate);
                if (golgremio > golinter)
                    printf("Gremio venceu mais\n");
                else if (golgremio < golinter)
                    printf("Inter venceu mais\n");
                else
                    printf("Não houve vencedor\n");
                return 0; // tem que ser esse, pq se for break, so quebra o do-while
            }
            else
                grenal++;
        } while (g != 1 && g != 2);
    }
}