// construa uma funcao para calcular o perimetro de um triangulo retangulo dados sua altura h e sua base b
#include <stdio.h>
#include <math.h>

int x, y;
int perimetro_triangulo(int b, int h);

int main(){
    scanf("%d %d", &x, &y);
    printf("Perimetro do triangulo de base %d e altura %d = %d\n", x, y, perimetro_triangulo(x,y));
}

int perimetro_triangulo(int b, int h){
    int perimetro = 0;
    int hipotenusa = 0;
    hipotenusa = sqrt(b*b + h*h);
    perimetro = b + h + hipotenusa;
    return perimetro;
}