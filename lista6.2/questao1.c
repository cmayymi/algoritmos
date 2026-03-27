// escreva funcoes recursivas para:
// somar dois numeros naturais a e b
// subtrair dois numeros naturais a e b
// multiplicar dois numeros interios a e b por somas sucessivas
// dividir dois numeros inteiros a e b por subtracoes sucessivas
// calcular a funcao potencia (base ^ expoente) , utilizando multiplicacao sucessivas

#include <stdio.h>

int x, y;
int soma(int a, int b);
int subtracao(int a, int b);
int multiplicacao(int a, int b);
int divisao(int a, int b);
int potencia(int a, int b);

int main(){
    scanf("%d %d", &x, &y);
    printf("%d + %d = %d\n", x, y, soma(x,y));
    printf("%d - %d = %d\n", x, y, subtracao(x,y));
    printf("%d * %d = %d\n", x, y, multiplicacao(x,y));
    printf("%d / %d = %d\n", x, y, divisao(x,y));
    printf("%d ^ %d = %d\n", x, y, potencia(x,y));
}

int soma(int a, int b){
    if (b == 0)
        return a;
    return soma(a + 1, b - 1);
}

int subtracao(int a, int b){
    if (b == 0)
        return a;
    return subtracao(a - 1, b - 1);
}

int multiplicacao(int a, int b){
    if (b == 0)
        return 0;
    return a + multiplicacao(a, b-1);
}

int divisao(int a, int b){
    if (b == 0)
        return -1;
    if (a < b) return 0;
    return 1 + divisao(a - b, b);
}

int potencia(int base, int expoente){
    if (expoente == 0) 
        return 1;
    return base * potencia(base, expoente - 1);
}