// Construa funções recursivas para:
// Calcular o MDC entre dois números naturais.
// Determinar quantas vezes um dado dígito k ocorre em um número decimal inteiro N.
// Calcular o somatório de um vetor V, de números reais, com tamanho n.
// Dado um array de números em ponto flutuante, inverter a posição de seus elementos.
// Procurar e retornar o menor valor de um vetor de números reais.

#include <stdio.h>

int mdc(int a, int b) {
    if (b == 0) 
        return a;
    return mdc(b, a % b);
}   

int contar_digito(int n, int k) {
    if (n == 0) 
        return 0;
    int ultimo_digito = n % 10;
    int count = (ultimo_digito == k) ? 1 : 0;
    return count + contar_digito(n / 10, k);
}

float somatorio(float v[], int n) {
    if (n == 0) 
        return 0;
    return v[n-1] + somatorio(v, n-1);
}

void inverter_array(float v[], int inicio, int fim) {
    if (inicio >= fim) 
        return;
    float temp = v[inicio];
    v[inicio] = v[fim];
    v[fim] = temp;
    inverter_array(v, inicio + 1, fim - 1);
}

float menor_valor(float v[], int n) {
    if (n == 1) 
        return v[0];
    float menor_resto = menor_valor(v, n-1);
    return (v[n-1] < menor_resto) ? v[n-1] : menor_resto;
}

int main(){
    printf("MDC: %d\n", mdc(48, 18));
    printf("Contar digito: %d\n", contar_digito(122542, 2));
    
    float vetor[] = {1.5, 2.3, 4.7, 0.8};
    printf("Somatorio: %.2f\n", somatorio(vetor, 4));
    printf("Menor valor: %.2f\n", menor_valor(vetor, 4));
    
    char str[] = "hello";
    inverter_string(str, 0, strlen(str)-1);
    printf("String invertida: %s\n", str);
}