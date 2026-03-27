#include <stdio.h>
int main()
{
    // A = preco por litro do alcool    
    // G = preco por litro da gasolina
    // Ra = rendimento do carro usando alcool
    // Rg = rendimento do carro usando gasolina
    float A, G, Ra, Rg, alcool, gasolina;
    scanf("%f %f %f %f", &A, &G, &Ra, &Rg);

    // calculo
    alcool = A/Ra;
    gasolina = G/Rg;

    if (alcool < gasolina)
        printf("A\n");
    else if ((gasolina = alcool) || (gasolina > alcool))
        printf("G\n");
}