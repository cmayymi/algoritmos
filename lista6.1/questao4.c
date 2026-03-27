// Construa	 uma função	para calcular o	perímetro de um	retângulo de largura a e comprimento b
#include <stdio.h>

int x, y;
int perimetro_retangulo(int a, int b);

int main(){
    scanf("%d %d", &x, &y);
    printf("Perimetro do retangulo de %d por %d = %d\n", x, y, perimetro_retangulo(x,y));
}

int perimetro_retangulo(int a, int b){
    int perimetro = 0;
    perimetro = 2*a + 2*b;
    return perimetro;
}