// escreva uma funcao que receba como parametro um numero inteiro n e retorne o valor do fatorial de n
#include <stdio.h>

long long fatorial(int n)
{
    long long fat = 1; // variavel de retorno (1 pois fatorial de 0 = 1)
    for (int i = 2; i <= n; i++) // calcula o fatorial para n
        fat *= i;

    // retorna o resultado
    return fat;
}

int main()
{
    for (int i = 0; i < 10; i++)
        printf("%d! = %lld\n", i, fatorial(i));
    printf("\n");
    return 0;
}
