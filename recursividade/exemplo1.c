#include <stdio.h>
#include <string.h>
#include <math.h>

// definicao das funcoes

// fatorial
unsigned long long fatorial(int n) // unsigned long long vai ate 20! no max!!
{
    if(n == 0) 
        return 1;
    else
        return n*fatorial(n-1);
}

// fibonacci
int fib(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

// decimal pra binario
char* dec_pra_binario_invertida(int dec, char *s)
{
    char temporaria[17]; // 16 bits + /0 no final
    if (dec < 2) 
    {
        sprintf(s, "%d", dec); // print to a string
        return s;
    }
    else
    {
        sprintf(s, "%d", dec%2);
        strcpy(temporaria, s);
        strcat(s, dec_pra_binario_invertida(dec/2, temporaria));
        return s;
    }
}

// inversao da cadeia de bits
char* reversao(char *reverter, int i, int j)
{
    char auxiliar;
    if (i >= j) // a cadeia considerada tem 0 ou 1 elementos
        return reverter;
    else
    {
        auxiliar = reverter[i];
        reverter[i] = reverter[j];
        reverter[j] = auxiliar;

        // chamar recursivamente e copia para reverter
        strcpy(reverter, reversao(reverter, ++i, --j));
        return reverter;
    }

}

// decimal para binario, 16 bits, normal
char* dec_pra_binario(int dec, char* s)
{
    s = dec_pra_binario_invertida(dec, s);
    strcpy(s, reversao(s, 0, strlen(s) - 1));
    return s;
}

// binario para decimal
unsigned binario_pra_dec(char *bits, int n)
{
    unsigned bit = bits[0] - 48; // 48 pq ele é 48 na tabela ascii
    if (n == 1)
        return bit*pow(2, n - 1);
    else
        return bit*pow(2, n - 1) + binario_pra_dec(&bits[1], n - 1);
}

int main()
{
    for (int i = 0; i < 5; i++)
        printf("%d! = %llu\n", i, fatorial(i));

    for (int i = 0; i < 5; i++)
        printf("Fibonacci de %d = %d\n", i, fib(i));

    char bin[17] = {};
    for (int i = 0; i < 5; i++)
    {
        printf("Binario de %d = %s\n", i, dec_pra_binario(i, bin));
        printf("Decimal de %s = %d\n", bin, binario_pra_dec(bin, strlen(bin)));
    }
    return 0;
}