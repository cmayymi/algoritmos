#include <stdio.h>

int x, z;
int inteiro = 0;

int main()
{
    scanf("%d", &x);
    do
    {
        scanf("%d", &z);
    } while(z <= x);

    int soma = 0;

    for (int i = x; soma <= z; i++) // a soma é <= pq se for > nunca para, msm apos ultrapassar
    {
        soma += i;
        inteiro++;
    }
    printf("%d\n", inteiro);
}