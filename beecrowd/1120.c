#include <stdio.h>
#include <string.h>

int digito, tamanho;
char numero_falho[1000] = " ";
char digito_falho[2] = " ";
char resultado[1000] = " ";

int main(){
    while (scanf("%d %s", &digito, numero_falho)){
        if (digito == 0 && numero_falho[0] == '0')
            break;
        
        // transformar o inteiro para string
        sprintf(digito_falho, "%d", digito);
        
        // pegar o tamanho do numero
        tamanho = strlen(numero_falho);

        int j = 0;
        // remover o numero falho da string
        for (int i = 0; i < tamanho; i++){
            if (numero_falho[i] == digito_falho[0]){
                continue;
            }
            else{
                resultado[j] = numero_falho[i];
                j++;
            }
        }
        resultado[j] = '\0';

        // se o 0 tiver em sequencia antes do numero
        int zeros = 0;
        while (resultado[zeros] == '0' && resultado[zeros] != '\0') {
            zeros++;
        }

        // se todos eram zeros ou string vazia
        if (resultado[zeros] == '\0') {
            printf("0\n");
        } 
        else {
            printf("%s\n", resultado + zeros);
        }
    }
}