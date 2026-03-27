#include <stdio.h>

int numero, linha, coluna;
int valor(int linha, int coluna, int n);

int main(){
    while (scanf("%d", &numero) != EOF){
        int matriz[numero][numero];
        // calculo
        for (linha = 0; linha < numero; linha++){
            for (coluna = 0; coluna < numero; coluna++){
                matriz[linha][coluna] = valor(linha, coluna, numero);
            }
        }

        // print da matriz - funcionando!
        for (linha = 0; linha < numero; linha++){
            for (coluna = 0; coluna < numero; coluna++){
                printf("%d", matriz[linha][coluna]);
            }
            printf("\n");
        }
    }
}

// funcao
int valor(int linha, int coluna, int n){
    // verificar se esta na diagonal secundaria -> imprime 2
    if (coluna == n - 1 - linha){
        return 2;
    }
    // verificar se esta na diagonal principal -> imprime 1
    else if (linha == coluna){
        return 1;
    }
    // caso contrario, imprime 3
    else
        return 3;
}