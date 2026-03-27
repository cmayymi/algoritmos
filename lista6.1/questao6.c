// contrua uma funcao para calcular o perimetro de um paralelogramo retangulo de altura h e base b
#include <stdio.h>

int x, y;
int perimetro_paralelogramo(int b, int h);

int main(){
    scanf("%d %d", &x, &y);
    printf("Perimetro do paralelogramo de base %d e altura %d = %d\n", x, y, perimetro_paralelogramo(x,y));
}

int perimetro_paralelogramo(int b, int h){
    int perimetro = 0;
    perimetro = 2 * (b + h);
    return perimetro;
}
