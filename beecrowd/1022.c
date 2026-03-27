#include <stdio.h>

int n; // numero de casos
int numerador1, numerador2, denominador1, denominador2;
char operador;

int main()
{
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d / %d %c %d / %d", &numerador1, &denominador1, &operador, &numerador2, &denominador2);
        int resultado_num = 0;
        int resultado_den = 0; 
        switch (operador)
        {
            case '+':
                resultado_num = (numerador1*denominador2 + numerador2*denominador1);
                resultado_den = (denominador1*denominador2);
                break;

            case '-':
                resultado_num = (numerador1*denominador2 - numerador2*denominador1);
                resultado_den = (denominador1*denominador2);
                break;

            case '*':
                resultado_num = (numerador1*numerador2);
                resultado_den = (denominador1*denominador2);
                break;

            case '/':
                resultado_num = (numerador1*denominador2);
                resultado_den = (numerador2*denominador1);
                break;
        }
        // guardar os valores
        int x = resultado_num;
        int y = resultado_den;

        // calculo do MDC 
        int a = resultado_num;
        int b = resultado_den;

        // é baseado no algoritmo de euclides que diz que o mdc de dois numeros tambem divide a diferenca entre eles
        while (b) // enquanto b nao for zero
        {
            int aux = b; // guarda o valor atual de b no aux
            b = a%b; // atualiza b para ser o resto da divisao de a por b
            a = aux; // atualiza a para ser o valor antigo de b
        }
        int mdc = a; // quando b chegar a zero, o mdc é o ultimo valor de a

        // simplificar a fracao
        resultado_num /= mdc;
        resultado_den /= mdc;

        // ajustar o sinal para q o denominador sempre seja positivo
        if (resultado_den < 0)
        {
            resultado_num = -resultado_num;
            resultado_den = -resultado_den;
        }

        printf("%d/%d = %d/%d\n", x, y, resultado_num, resultado_den);
    }
}