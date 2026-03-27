// QUESTÃO 1 - CAROLINE MAYUMI GRELLMANN SAITO

#include <stdio.h>
#include <stdlib.h>

int N, M; // n = linha; m = coluna -> parque
int X, Y; // x = linha; y = coluna -> microfone
int K; // numero de quadrados pelos quais os dois homens passearam
int direcao; // direcao do movimento

int main(){
    scanf("%d %d", &N, &M);
    scanf("%d %d", &X, &Y);
    scanf("%d", &K);

    int hx = 0, hy = 0;
    int contador = 0;

    for (int i = 0; i < K; i++){
        scanf("%d", &direcao);
        if (direcao == 1) // norte
            hx++;
        else if (direcao == 2) // sul
            hx--;
        else if (direcao == 3) // leste
            hy++;
        else if (direcao == 4) // oeste
            hy--;

        if (abs(hx - X) <= 1 && abs(hy - Y) <= 1) 
            contador++;
        }

    printf("%d\n", contador);
    return 0;
}