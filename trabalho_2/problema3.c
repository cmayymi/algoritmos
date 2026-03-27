#include <stdio.h>

int i, j, resposta, max_ciclo = 0;
int questao(int n);

int main(){
    while (scanf("%d %d", &i, &j) == 2){
        for (int k = i; k <= j; k++){
            resposta = questao(k);
            if (resposta > max_ciclo)
                max_ciclo = resposta;
        }
        printf("%d %d %d\n", i, j, max_ciclo);
        max_ciclo = 0;
    }
}

int questao(int n){
    int soma = 1; 
    // printf("%d\n", n);
    while (n != 1){
        if (n % 2 == 1)
            n = 3*n + 1;
        else
            n = n/2;
        // printf("%d\n", n);
        soma++;
    }
    // printf ("%d\n", soma);
    return soma;
}