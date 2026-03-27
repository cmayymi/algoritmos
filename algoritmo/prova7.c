#include <stdio.h>
int main()
{
    // N = diametro da bola
    // A = altura
    // L = largura
    // P = profundidade
    int N, A, L, P;
    scanf("%d", &N);
    scanf("%d %d %d", &A, &L, &P);


    // conferir se o diametro da bola é maior que a menor dimensao da caixa
    // se sim = nao cabe
    if (N > A || N > L || N > P)
        printf("N\n");
    else
        printf("S\n");
}