#include <stdio.h>

char vendedor[10];
double salario, vendas, total;

int main(){
    scanf("%s", vendedor);
    scanf("%lf", &salario);
    scanf("%lf", &vendas);

    total = (vendas * 0.15) + salario;
    printf("TOTAL = R$ %.2lf\n", total);
}