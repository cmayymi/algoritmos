// construa uma funcao para calcular a area de um retangulo de largura a e comprimento b
#include <stdio.h>

int x, y;
int area_retangulo(int a, int b);

int main(){
    scanf("%d %d", &x, &y);
    printf("Area do retangulo de %d por %d = %d\n", x, y, area_retangulo(x,y));
}

int area_retangulo(int a, int b){
    int area = 0;
    area = a * b;
    return area;
}