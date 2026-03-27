#include <stdio.h>

int x, par[5], impar[5];
int contagem_par = 0, contagem_impar = 0;

int main()
{
    for (int i = 0; i < 15; i++)
    {
        scanf("%d", &x);
        if (x%2 == 0)
        {
            par[contagem_par] = x;
            contagem_par++;
            if (contagem_par == 5)
            {
                for(int j = 0; j < 5; j++)
                    printf("par[%d] = %d\n", j, par[j]);
                contagem_par = 0;
            }
        }

        else 
        {
            impar[contagem_impar] = x;
            contagem_impar++;
            if (contagem_impar == 5)
            {
                for(int j = 0; j < 5; j++)
                    printf("impar[%d] = %d\n", j, impar[j]);
                contagem_impar = 0;
            }
        }
    }
    // imprime os impares restantes
    for (int j = 0; j < contagem_impar; j++)
        printf("impar[%d] = %d\n", j, impar[j]);
    
    // imprime os pares restantes
    for (int j = 0; j < contagem_par; j++)
        printf("par[%d] = %d\n", j, par[j]);
}