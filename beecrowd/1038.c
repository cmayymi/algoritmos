#include <stdio.h>

int codigo, quantidade;
float valor;

int main(){
    scanf("%d %d", &codigo, &quantidade);
    switch (codigo){
    case 1:
        valor = 4.0 * quantidade;
        printf("Total: R$ %.2f\n", valor);
        break;

    case 2:
        valor = 4.50 * quantidade;
        printf("Total: R$ %.2f\n", valor);
        break;

    case 3:
        valor = 5.0 * quantidade;
        printf("Total: R$ %.2f\n", valor);
        break;

    case 4:
        valor = 2.0 * quantidade;
        printf("Total: R$ %.2f\n", valor);
        break;

    case 5:
        valor = 1.50 * quantidade;
        printf("Total: R$ %.2f\n", valor);
        break;
    }
}