#include <stdio.h>
#include <math.h>
int main()
{
	int x; // entrada
	//double y = 3; // denominador
	double s, pi, sinal; // soma e pi
    // s = 1 - 1/3^3 + 1/5^3
    // pi = raiz cubica(s*32)
    // calcula e imprima o valor de pi
    while (scanf("%d", &x) != EOF) {	// Esqueceu do EOF
        sinal = 1;
        s = 0;
       // pi = 0;
        double base = 1;
        //for (int i = 0; i < x; i++) 
        for (int i = 1; i <= x; i++) {
            // s += sinal* 1 - (1/pow(y,3));
            double termo = sinal*(1.0/pow(base, 3));
            s += termo;
            base += 2;
            //sinal *= -sinal;
            sinal *= -1;
        }
        pi = cbrt(s*32);
        printf("%.5lf\n", pi);
    }
    return 0;
}