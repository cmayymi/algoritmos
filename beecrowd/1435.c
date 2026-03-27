#include <stdio.h>

int numero, linha, coluna;

int minimo(int a, int b);
int valor(int linha, int coluna, int n);

int main(){
    while (scanf("%d", &numero)){
        if (numero == 0)
            break;

        // calculo, distancia ate a borda
        int matriz[numero][numero];
        for (linha = 0; linha < numero; linha++){
            for (coluna = 0; coluna < numero; coluna++){
                matriz[linha][coluna] = valor(linha, coluna, numero);
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

int minimo(int a, int b){
    if (a < b)
        return a;
    else
        return b;
}

int valor(int linha, int coluna, int n){ // ex linha = 0, coluna = 3, n = 4
    // distancia até o topo
    int topo = linha;

    // distancia até a base
    int base = (n - 1) - linha;

    // distancia até a esquerda
    int esquerda = coluna;

    // distancia até a direita
    int direita = (n - 1) - coluna;

    // pega o menor
    int menor = minimo(minimo(topo, base), minimo(esquerda, direita));

    // retorna menor + 1
    return menor + 1;
}

