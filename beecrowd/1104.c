#include <stdio.h>

int cA, cB; // carta alice e carta betty
int alice[10000];
int betty[10000];

int main()
{
    while (1)
    {
        scanf("%d %d", &cA, &cB); // quantidade de cartas
        if (cA == 0 && cB == 0)
            break;

        for (int i = 0; i < cA; i++)
            scanf("%d", &alice[i]);
        
        for (int i = 0; i < cB; i++)
            scanf("%d", &betty[i]);

        // comparar o primeiro numero com a da betty
        int max_cartas_troca = 0;
        for (int i = 0; i < cA; i++) // para cada cA
        {
            for (int j = 0; j < cB; j++) // para cada cB
            {
                // tirar as repeticoes
                if (alice[i] == alice[i+1])
                    continue; // ele pula pro prox numero
                    
                if (betty[j] > alice[i]) // vai voltar pro segundo for, ent so vai aumentar o do j
                {
                    for (int k = 0; k < cA; k++) // se alice tem carta de betty
                    {
                        if (alice[k] == betty[j]) 
                            max_cartas_troca--; // cancela a soma
                    }
                    max_cartas_troca++; 
                    break;
                }
                else if (betty[j] == alice[i])
                    break;
            }
        }
        printf("%d\n", max_cartas_troca);
    }
}

