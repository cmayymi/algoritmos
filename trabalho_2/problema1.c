#include <stdio.h>

int linha, coluna;
int m[100][100];

int main(){
    scanf("%d %d", &linha, &coluna);

    // leitura da matriz
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            scanf("%d", &m[i][j]);
        }
    }

    // calculo da matriz
    int max_soma = 0;
    // calcular soma de cada linha e encontrar a maior
    for (int i = 0; i < linha; i++){
        int soma_linha = 0;
        for (int j = 0; j < coluna; j++){
            soma_linha += m[i][j];
        }
        if (soma_linha > max_soma)
            max_soma = soma_linha;
    }

    // calcular soma de cada coluna e encontrar a maior
    for (int j = 0; j < coluna; j++){
        int soma_coluna = 0;
        for (int i = 0; i < linha; i++){
            soma_coluna+= m[i][j];
        }
        if (soma_coluna > max_soma)
            max_soma = soma_coluna;
    }
    printf("%d\n", max_soma);
}