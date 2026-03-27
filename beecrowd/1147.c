#include <stdio.h>

int posicao_cavalo;
int y, teste = 0; // caso de teste
int x;

int main()
{
    while(scanf("%d", &posicao_cavalo) && posicao_cavalo)
    {
        for (int i = 0; i < 8; i++)
        {
            scanf("%d", &x);
            // nao sei como continuar
        }
        do
        {
            scanf("%d", &y);
            if (y == 0)
                return 0;
            else
                teste++;
        } while (y != 1 && y != 0);
    }
}