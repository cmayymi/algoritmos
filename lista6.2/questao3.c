// Construa funções recursivas para:
// Inverter uma string.
// Verificar se uma palavra ou frase é palíndromo.
// Converter uma string com caracteres binários, representando valores em binário puro, para seu valor em decimal.
// Converter um valor em decimal inteiro não-negativo em uma string com sua representação em binário.

#include <stdio.h>
#include <string.h>
#include <math.h>

// a) Inverter uma string
void inverter_string(char str[], int inicio, int fim) {
    if (inicio >= fim) return;
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    inverter_string(str, inicio + 1, fim - 1);
}

// b) Verificar se é palíndromo
int eh_palindromo(char str[], int inicio, int fim) {
    if (inicio >= fim) return 1;
    if (str[inicio] != str[fim]) return 0;
    return eh_palindromo(str, inicio + 1, fim - 1);
}

// c) Converter binário (string) para decimal
int binario_para_decimal(char binario[], int pos, int expoente) {
    if (pos < 0) return 0;
    int digito = binario[pos] - '0';
    return digito * (1 << expoente) + binario_para_decimal(binario, pos-1, expoente+1);
}

// d) Converter decimal para binário (string)
void decimal_para_binario(int n, char binario[], int *index) {
    if (n > 1) {
        decimal_para_binario(n / 2, binario, index);
    }
    binario[(*index)++] = (n % 2) + '0';
    binario[*index] = '\0';
}

int main(){
    char str[] = "hello";
    inverter_string(str, 0, strlen(str)-1);
    printf("String invertida: %s\n", str);

    char palindromo[] = "radar";
    printf("Eh palindromo: %d\n", eh_palindromo(palindromo, 0, strlen(palindromo)-1));
    
    char bin[] = "1101";
    printf("Binario para decimal: %d\n", binario_para_decimal(bin, strlen(bin)-1, 0));
    
    char binario_result[33];
    int index = 0;
    decimal_para_binario(13, binario_result, &index);
    printf("Decimal para binario: %s\n", binario_result);
    
    return 0;
}