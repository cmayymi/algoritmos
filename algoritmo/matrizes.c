#include <stdio.h>
#include <string.h>

typedef struct 
{
    float M[10][10]; // memoria alocada para a matriz
    int linha; // numero de linhas da matriz
    int coluna; // numero de colunas da matriz
} MATRIZ;

MATRIZ a, b, c;

int main()
{
    // leitura das dimensoes da matriz a
    scanf("%d %d", &a.linha, &a.coluna);

    // leitura da matriz a
    for (int i = 0; i < a.linha; i++)
    {
        for (int j = 0; j < a.coluna; j++)
            scanf("%f", &a.M[i][j]);
    }

    // escrita da matriz a
    for (int i = 0; i < a.linha; i++)
    {
        for (int j = 0; j < a.coluna; j++)
        {
            printf("%.1f", a.M[i][j]);
            if (j < a.coluna - 1) 
                printf("\t "); // vai imprimir um espaco
        }
        printf("\n");
    }

       // leitura das dimensoes da matriz a
    scanf("%d %d", &a.linha, &a.coluna);

    // leitura da matriz b
    for (int i = 0; i < b.linha; i++)
    {
        for (int j = 0; j < b.coluna; j++)
            scanf("%f", &b.M[i][j]);
    }

    // escrita da matriz b
    for (int i = 0; i < b.linha; i++)
    {
        for (int j = 0; j < b.coluna; j++)
        {
            printf("%.1f", b.M[i][j]);
            if (j < b.coluna - 1) 
                printf("\t "); // vai imprimir um espaco
        }
        printf("\n");
    }

    // multiplicacao das matrizes

    // testa se é possivel multiplicar a e b
    if (a.coluna != b.linha)
        printf("Erro: não é possível multiplicar as matrizes.\n");
    else
        // zerar a matriz c
        memset(c.M, 0, sizeof(float)*a.linha*b.coluna);
        c.linha = a.linha;
        c.coluna = b.coluna;
        // multiplica as matrizes
        for (int i = 0; i < a.linha; i++)
        {
            for (int j = 0; j < b.linha; j++)
            {
                for (int k = 0; k < a.coluna; k++)
                {
                    c.M[i][j] += a.M[i][k]*b.M[k][j];
                }
            }
        }

        // imprime o resultado
        // escrita da matriz c
        for (int i = 0; i < c.linha; i++)
        {
            for (int j = 0; j < c.coluna; j++)
            {
                printf("%.1f", c.M[i][j]);
                if (j < c.coluna - 1) 
                    printf("\t "); // vai imprimir um espaco
            }
            printf("\n");
        }


    return 0;
}