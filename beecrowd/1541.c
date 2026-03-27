#include <stdio.h>
#include <math.h>

int largura, comprimento, porcentagem, area_terreno, area_casa, lado;

int main(){
    while (scanf("%d", &largura) && largura != 0){
        scanf("%d %d", &comprimento, &porcentagem);
        area_terreno = largura*comprimento;
        area_casa = (area_terreno * 100)/porcentagem;
        lado = sqrt(area_casa);
        printf("%d\n", lado);
    }
}