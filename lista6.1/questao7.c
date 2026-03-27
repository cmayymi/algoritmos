// construa uma funcao para calcular a area de um triangulo dadas sua altura h e sua base b
#include <stdio.h>

int x, y;
int perimetro_triangulo(int b, int h);

int main(){
    scanf("%d %d", &x, &y);
    printf("Area do triangulo de base %d e altura %d = %d\n", x, y, perimetro_triangulo(x,y));
}

int perimetro_triangulo(int b, int h){
    int area = 0;
    area = (b * h)/2;
    return area;
}