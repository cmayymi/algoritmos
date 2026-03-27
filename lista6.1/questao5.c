// construa uma funcao para calcular a area de um paralelogramo de altura h e base b
#include <stdio.h>

int x, y;
int area_paralelogramo(int b, int h);

int main(){
    scanf("%d %d", &x, &y);
    printf("Area do paralelogramo de base %d e altura %d = %d\n", x, y, area_paralelogramo(x,y));
}

int area_paralelogramo(int b, int h){
    int area = 0;
    area = b * h;
    return area;
}