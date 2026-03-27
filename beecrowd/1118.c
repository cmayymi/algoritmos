#include <stdio.h>

// variaveis iguais ao do 1117.c
float notas[2]; // declara valores como um vetor de 2 posicoes
float media, notalida, s;
int x; 

// variaveis novas do 1118.c
int novocalculo, y;

int main()
{
    while(1) // pq vc digita 1 para continuar
    {
        x = 0;
        s = 0;
        while(x < 2)
        {
        scanf("%f", &notalida);
 
        if ((notalida >= 0) && (notalida <= 10))
        {
            notas[x] = notalida;
            s += notalida;
            x++;
        }
        else 
            printf("nota invalida\n");
        }
        media = s/2;
        printf("media = %.2f\n", media);

        // mensagem de novo calculo repetida
        do
        {
            printf("novo calculo (1-sim 2-nao)\n");
            scanf("%d", &y);
            if (y == 2)
                return 0; // tem que ser esse, pq se for break, so quebra o do-while
        } while (y != 1 && y != 2);
    }
    return 0;
}