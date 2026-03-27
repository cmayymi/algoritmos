#include <stdio.h>

char op;

typedef struct
{
    int real;
    int imaginario;
}complexo;

scanC(complexo *c)
{
    scanf("%d %di", &c->real, &c->imaginario);
}

printC(complexo c)
{
    printf("%d %di", c.real, c.imaginario);
}

complexo soma(complexo a, complexo b);
complexo subtracao(complexo a, complexo b);
complexo multiplicacao(complexo a, complexo b);
complexo divisao(complexo a, complexo b);

int main()
{
    while (scanC != EOF)
    {
        switch (operacao)
        {
        case '+'
            printf("(%d %di)\n", )
            break;
        
        case '-'
            /* code */
            break;

        case '*'
            /* code */
            break;

        case '/'
            /* code */
            break;

        default:
            break;
        }
    }
}

complexo soma(complexo a, complexo b)
{
    complexo s;
    s.real = a.real + b.real;
    s.imaginario = a.imaginario + b.imaginario;
    return s;
}

complexo subtracao(complexo a, complexo b)
{
    complexo s;
    s.real = a.real - b.real;
    s.imaginario = a.imaginario - b.imaginario;
    return s;
}

complexo multiplicacao(complexo a, complexo b)
{
    complexo s;
    s.real = a.real * a.imaginario - b.real * b.imaginario;
    s.imaginario = a.real * b.imaginario + b.real * a.imaginario;
    return s;
}

complexo divisao(complexo a, complexo b)
{
    complexo s;
    s.real = (a.real * a.imaginario + b.real * b.imaginario) / (a.imaginario * a.imaginario + b.imaginario * b.imaginario);
    s.imaginario = (b.real * a.imaginario - a.real * b.imaginario) / (a.imaginario * a.imaginario + b.imaginario * b.imaginario);
    return s;
}