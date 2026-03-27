// QUESTÃO 2 - CAROLINE MAYUMI GRELLMANN SAITO

#include <stdio.h>

int N; 
int A1, A2, A3, B1, B2, B3;

int main(){
    scanf("%d", &N);
    int partidasA = 0, partidasB = 0; // numero de partidas vencidas por cada jogador

    int forca[14];

    forca[4]  = 0;
    forca[5]  = 1;
    forca[6]  = 2;
    forca[7]  = 3;
    forca[12] = 4; // Q
    forca[11] = 5; // J
    forca[13] = 6; // K
    forca[1]  = 7; // A
    forca[2]  = 8;
    forca[3]  = 9;

    for (int i = 0; i < N; i++){
        scanf("%d %d %d", &A1, &A2, &A3);
        scanf("%d %d %d", &B1, &B2, &B3);

        int vA = 0, vB = 0; // contar os pontos de cada jogador em cada rodada

        // rodada 1
        if (forca[A1] >= forca[B1])
            vA++;
        else vB++;

        // rodada 2
        if (forca[A2] >= forca[B2]) 
            vA++;
        else vB++;

        // rodada 3
        if (forca[A3] >= forca[B3]) 
            vA++;
        else vB++;

        // vencedor da partida
        if (vB >= 2)
            partidasB++;
        else
            partidasA++;
    }

    printf("%d %d\n", partidasA, partidasB);
    return 0;
}