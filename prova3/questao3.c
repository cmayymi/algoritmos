// QUESTÃO 3 - CAROLINE MAYUMI GRELLMANN SAITO

#include <stdio.h>

int L, C; // L = linhas, C = colunas de cajueiros existentes
int M, N; // M = linhas, N = colunas de cajueiros a serem colhidos

int main(){
    scanf("%d %d", &L, &C);
    scanf("%d %d", &M, &N);

    static int a[1001][1001]; // comeca zerado
    // leitura da matriz
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= C; j++)
            scanf("%d", &a[i][j]);
    }

    int maximo = 0;
  // percorre todas as submatrizes M x N possíveis
    for (int i = 1; i <= L - M + 1; i++) {
        for (int j = 1; j <= C - N + 1; j++) {
            int atual = 0;
            // soma os valores da área M x N
            for (int x = i; x < i + M; x++) {
                for (int y = j; y < j + N; y++)
                    atual += a[x][y];
            }
            if (atual > maximo)
                maximo = atual;
        }
    }

    printf("%d\n", maximo);
    return 0;
}