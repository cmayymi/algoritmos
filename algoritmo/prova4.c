#include <stdio.h>
int main()
{
    // switch case so
    
    // N = maior numero que o computador consegue representar
    // P = numero 
    // C = operacao (+ ou *)
    // Q = outro numero
    int N, P, Q, a;
    char c;
    scanf("%d", &N);
    scanf("%d %d %d", &P, &c, &Q);

    switch (c)
    {
        case '+':
        a = P + Q;
        break;

        case '*':
        a = P * Q;
        break;
    }

    if (a > N)
        printf("OVERFLOW\n");
    else if (a <= N)
        printf("OK\n");
    
    return 0;
}