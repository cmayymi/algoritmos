#include <stdio.h>

float notas[2]; // declara valores como um vetor de 2 posicoes
float media, notalida, s = 0;
int x = 0; 

int main()
{
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
}