#include <stdio.h>
#include <string.h>

int casos, tamanho, metade, tamanho_codificado, tamanho_invertido;

int main(){
    scanf("%d", &casos);
    for (int i = 0; i < casos; i++){
        char frase[1001] = " ";
        char frase_codificada[1001] = " ";
        char frase_invertida[1001] = " ";
        scanf(" %[^\n]", frase); // esse espaco diz para o scanf ignorar qualquer espaco em branco (incluindo \n) antes de comecar a ler
        // printf("Original: %s\n", frase);

        tamanho = strlen(frase);
        // toda letra tem que mover 3 posicoes para a direita de acordo com a tabela ascii
        for (int j = 0; j < tamanho; j++){
            if ((frase[j] >= 'a' && frase[j] <= 'z') || (frase[j] >= 'A' && frase[j] <= 'Z'))
                frase_codificada[j] = frase[j] + 3;
            else
                frase_codificada[j] = frase[j];
        }
        frase_codificada[tamanho] = '\0';
        // printf("Codificada: %s\n", frase_codificada);

        tamanho_codificado = strlen(frase_codificada);
        // depois, cada linha tem que ser ao contrario (maca) -> (acam)
        for (int j = tamanho_codificado - 1; j >= 0; j--){
            frase_invertida[tamanho_codificado - 1 - j] = frase_codificada[j]; 
        } // -1 por conta do \0 e -j por conta que se j for sla 10, como a gente ta lendo de tras pra frente, a frase invertida vai colocar isso no lugar do tamanho - 11 
        // enquanto a frase codificada ta no lugar 11
        frase_invertida[tamanho_codificado] = '\0';
        // printf("Invertida: %s\n", frase_invertida);

        // depois, divide a palavra pela metade (se for impar, adiciona + 1) e move uma posicao para a esquerda na tabela ascii
        tamanho_invertido = strlen(frase_invertida);
        metade = tamanho_invertido/2; // como ta pedindo pra ser truncado, ele quer divisao inteira

        for (int j = metade; j < tamanho_invertido; j++){
            frase_invertida[j] = frase_invertida[j] - 1;
        }
        frase_invertida[tamanho_invertido] = '\0';
        // printf("Antes meia: %s\n", frase_invertida);
        printf("%s\n", frase_invertida);
    }
}