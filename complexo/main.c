#include "complexo.h"
#include <stdio.h>

int main(){
    complexo a, b, c;
    char op;

    while (scanComplexo(&a) == 2){
        scanf(" %c ", &op);
        scanComplexo(&b); 
        getchar();

        switch (op){
        case '+':
            c = soma(a, b);
            break;

        case '-':
            c = subtracao(a, b);
            break;

        case '*':
            c = multiplicacao(a, b);
            break;

        case '/':
            c = divisao(a, b);
            break;
        }
        printComplexo(a);
        printf(" %c ", op);
        printComplexo(b);
        printf(" = ");
        printComplexo(c);
        printf("\n");
    }
    return 0;
}