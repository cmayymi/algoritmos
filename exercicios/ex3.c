#include <stdio.h>

float x, s;
unsigned a;


int main()
{
    // leia x e calcule o resultado de s = x - x/1! + x/2! - ... usando os primeiros 20 termos
    while (scanf("%f", &x) != EOF)
    {
        int sinal = 1; // como os sinais intercalam ne
        a = 1; // fatorial sempre vai ser igual ou maior q 1
        s = 0; // zera o s para n ficar somando toda vez q inicia o loop
        // x/2! - x/3! + ...
        for (int i = 2; i <= 18; i++)
        {
            a *= i; // para fazer o calculo do fatorial
            s += sinal * (x/a); // calculo da soma
            sinal *= -1; // muda o sinal para -1 dnv
        }
        printf("%.5f\n", s);
    }
}