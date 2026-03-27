#include <stdio.h>

float numero;

int main(){
    scanf("%f", &numero);
    if (numero < 0.0 || numero > 100.0)
        printf("Fora de intervalo\n");
    else if (numero >= 0.0 && numero <= 25.0)
        printf("Intervalo [0,25]\n");
    else if (numero > 25.0 && numero <= 50.0)
        printf("Intervalo (25,50]\n");
    else if (numero > 50.0 && numero <= 75.0)
        printf("Intervalo (50,75]\n");
    else if (numero > 75.0 && numero <= 100.0)
        printf("Intervalo (75,100]\n");
}