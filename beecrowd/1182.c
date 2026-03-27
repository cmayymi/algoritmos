#include <stdio.h>

float m[12][12];
int coluna_desejada, linha, coluna;
float soma = 0;
int contagem = 0;
char operacao;

int main(){
    scanf("%d", &coluna_desejada);
    scanf(" %c", &operacao);

    // leitura da matriz
    for(linha = 0; linha < 12; linha++){
        for (coluna = 0; coluna < 12; coluna++){
            scanf("%f", &m[linha][coluna]);
        }
    }

    // calculo
    for (linha = 0; linha < 12; linha++){
        for (coluna = 0; coluna < 12; coluna++){
            if (coluna == coluna_desejada){
                soma += m[linha][coluna_desejada];
                contagem++;
            }
        }
    }

    switch (operacao){
    case 'S':
        printf("%.1f\n", soma);
        break;

    case 'M':
        printf("%.1f\n", soma/contagem);
        break;
    }
}