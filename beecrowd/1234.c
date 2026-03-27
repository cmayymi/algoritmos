#include <stdio.h>
#include <string.h>
#include <ctype.h>

char frase[55];
int tamanho;

int main(){
    scanf("%[^\n]s", frase);
    tamanho = strlen(frase);

    // toda frase tem que começar com um maiusculo
    if (isupper(frase[0]) == 0)
        frase[0] = toupper(frase[0]);

    // printf("%s\n", frase);

    // seguindo isso, os proximos tem que mudar 
    // espaço nao conta
    // so letra
    for (int i = 1; i < tamanho; i++){
        if ((frase[i] >= 'a' && frase[i] <= 'z') || (frase[i] >= 'A' && frase[i] <= 'Z')){
            
        }




        if (isupper(frase[i]) != 0) 
            continue;
        else
            frase[i] = toupper(frase[i]);
    }

    printf("%s\n", frase);
}