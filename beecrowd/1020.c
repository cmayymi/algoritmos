#include <stdio.h>

int idade, mes, ano, dia;

int main()
{
    scanf("%d", &idade);
    
    // calculo
    ano = idade/365;
    printf("%d ano(s)\n", ano);

    idade %= 365;
    mes = idade/30;
    printf("%d mes(es)\n", mes);

    idade %= 30;
    dia = idade;
    printf("%d dia(s)\n", dia);
}