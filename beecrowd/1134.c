#include <stdio.h>

int n;
int alcool = 0;
int gasolina = 0;
int diesel = 0;

int main()
{
    while(scanf("%d", &n))
    {
        if (n != 4)
        {
            if (n == 1)
                alcool++;
            else if (n == 2)
                gasolina++;
            else if (n == 3)
                diesel++;
        }
        else
            break;
    }
    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n", alcool);
    printf("Gasolina: %d\n", gasolina);
    printf("Diesel: %d\n", diesel);
}