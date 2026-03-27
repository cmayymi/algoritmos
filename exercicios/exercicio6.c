// considere que desejamos representar numeros racionais em um registro que contem dois valores inteiros: numerador e denominador
// construa esse tipo registro e escreva funcoes que realizem as seguintes operacoes sobre numeros racionais
// soma, subtracao, multiplicacao, divisao
#include <stdio.h>

// definicao do tipo racional
typedef struct 
{
    int numerador;
    int denominador;
}racional;

// definicao das funcao
int mdc(int a, int b)
{
    while (b != 0)
    {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

racional simplificacao(racional r)
{
    int MDC = mdc(r.numerador, r.denominador);
    r.numerador /= MDC;
    r.denominador /= MDC;
    if (r.denominador < 0)
    {
        r.denominador *= -1;
        r.numerador *= -1;
    }
    return r;
}

racional soma_racional(racional r1, racional r2)
{
    racional soma; // variavel de retorno
    // implementacao da soma
    soma.denominador = r1.denominador*r2.denominador;
    soma.numerador = (r1.numerador*r2.denominador) + (r2.numerador*r1.denominador);
    return simplificacao(soma);
}

racional subtracao_racional(racional r1, racional r2)
{
    racional sub; // variavel de retorno
    // implementacao da subtracao
    sub.denominador = r1.denominador*r2.denominador;
    sub.numerador = (r1.numerador*r2.denominador) - (r2.numerador*r1.denominador);    
    return simplificacao(sub);
}

racional multiplicacao_racional(racional r1, racional r2)
{
    racional mult; // variavel de retorno
    // implementacao da multiplicacao
    mult.denominador = r1.denominador*r2.denominador;
    mult.numerador = r1.numerador*r2.numerador;
    return simplificacao(mult);
}

racional divisao_racional(racional r1, racional r2)
{
    racional div; // variavel de retorno
    // implementacao da divisao
    div.denominador = r1.denominador*r2.numerador;
    div.numerador = r1.numerador*r2.denominador;
    return simplificacao(div);
}

float decimal(racional r)
{
    return r.numerador / (float)r.denominador;
}

int main()
{
    racional x, y; // variaveis de entrada
    racional resposta; // resposta
    float dec;

    // ler as entradas
    scanf("%d/%d %d/%d", &x.numerador, &x.denominador, &y.numerador, &y.denominador);
    resposta = soma_racional(x,y);
    printf("X + Y = %d/%d\n", resposta.numerador, resposta.denominador);
    dec = decimal(resposta);
    printf("Em decimal = %lf\n\n", dec);

    resposta = subtracao_racional(x,y);
    printf("X - Y = %d/%d\n", resposta.numerador, resposta.denominador);
    dec = decimal(resposta);
    printf("Em decimal = %lf\n\n", dec);

    resposta = multiplicacao_racional(x,y);
    printf("X * Y = %d/%d\n", resposta.numerador, resposta.denominador);
    dec = decimal(resposta);
    printf("Em decimal = %lf\n\n", dec);

    resposta = divisao_racional(x,y);
    printf("X / Y = %d/%d\n", resposta.numerador, resposta.denominador);
    dec = decimal(resposta);
    printf("Em decimal = %lf\n\n", dec);
}