#include <stdio.h>

int n; // numero de questoes
int x1, x2, x3, x4, x5; // a b c d e 
char alternativas[] = {'A', 'B', 'C', 'D', 'E'};

int main()
{
    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d %d %d", &x1, &x2, &x3, &x4, &x5);
            // valor maior ou igual a 127 é branco
            // valor menor ou igual a 127 é preto   

            int valores[] = {x1, x2, x3, x4, x5};
            int contador = 0; // conta quantos sao <= 127
            char correta = '*'; // guarda a resposta

            for (int i = 0; i < 5; i++)
            {
                if (valores[i] <= 127)
                {
                    contador++;
                    correta = alternativas[i];
                }
            }
            if (contador == 1)
                printf("%c\n", correta);
            else
                printf("*\n");
        }
    }
}