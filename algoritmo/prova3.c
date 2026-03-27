#include <stdio.h>
int main()
{
    // if...else

    // C = numero de competidores
    // P = quantidade de folhas de papel especial compradas pela diretora
    // F = quantidade de folhas de papel especial q cada competidor deve receber
    int C, P, F;
    scanf("%d %d %d", &C, &P, &F);

    // S = suficiente
    // N = nao
    if ((C*F) > P)
        printf("N\n");
    else
        printf("S\n");
}