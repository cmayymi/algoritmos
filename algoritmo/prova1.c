#include <stdio.h>
int main()
{
    char lugar[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    // F = o número total de fileiras no avião
    // C = o número de posições por fileira
    // E = o número da primeira fileira da classe econômica
    // B = a posição na fila de embarque do Sr. Zuki
    int F, C, E, B, lugares, executiva, coluna, fila;
    scanf("%d %d %d %d", &F, &C, &E, &B);

    // calculo
    lugares = F*C;
    executiva = (F - E) + 1; // adiciona 1 porque a subtração exclui a primeira fileira executiva

    // fila de embarque
    coluna = B%C;
    fila = (B/C) + E;

    if (executiva*C < B)
        printf("PROXIMO VOO\n");
    else
        printf("%d %c\n", fila, lugar[coluna-1]);
    return 0;
}