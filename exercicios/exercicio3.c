// escreva uma funcao que receba como parametro um numero inteiro n e retorne o valor do n-esimo elemento da sequencia de fibonacci
#include <stdio.h>

// funcao fibonacci
long fibonacci(int n)
{
    long f0, f1, f2; // ultimo, penultimo e valor atual 
    f0 = f1 = f2 = 1; // inicializa todos os valores com 1
    for (int i = 2; i <= n; i++)
    {
        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;
    }
    return f2;
}

// funcao fatorial
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
        printf("fib(%d) = %ld\n", i, fibonacci(i));

    long long s = fatorial(11) + fibonacci(11);
    printf("resposta = %lld\n", s);
    printf("\n");
    return 0;
}