#include <stdio.h>

int numero, linha, coluna;

int valor(int linha, int coluna);

int main(){
    while(scanf("%d", &numero)){
        if (numero == 0)
            break;

        int matriz[numero][numero];
        // calculo, todos os valores na diagonal tem que estar igual
        for (linha = 0; linha < numero; linha++){
            for (coluna = 0; coluna < numero; coluna++){
                matriz[linha][coluna] = valor(linha, coluna);
            }
        }

        // print da matriz - funcionando!
        for (linha = 0; linha < numero; linha++){
            for (coluna = 0; coluna < numero; coluna++){
                if (coluna == numero - 1)
                    printf("%3d", matriz[linha][coluna]);
                else
                    printf("%3d ", matriz[linha][coluna]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int valor(int linha, int coluna){
    int distancia;
    if (linha > coluna)
        distancia = linha - coluna;
    else
        distancia = coluna - linha;
    return distancia + 1;
}