// crie um algoritmo para abreviar nomes
// ultimo nome seguido de virgula, seguido pelo primeiro nome seguido
// pelas iniciais dos sobrenomes seguidos por ponto e virgula separadas por espaco
// ex: se o nome for Joaquim José da Silva Xavier, o resultado tem que ser "Xavier, Joaquim J.S."

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char nome[100] = " ";
int tamanho;
char nome_abreviado[100] = " ";
int posicao_sobrenome, posicao_nome;

int main(){
    while(scanf("%[^\n]s", nome) != EOF){
        getchar();  // consome o \n do buffer
        // printf("%s\n", nome);
        // percorrer a string do ultimo (utilizar strlen) até o espaço
        tamanho = strlen(nome);
        // printf("%d\n", tamanho);
        for (posicao_sobrenome = tamanho - 1; nome[posicao_sobrenome] != ' '; posicao_sobrenome--); // encontrar o espaço, comecando do ultimo caractere
        //printf("%s\n", &nome[posicao_sobrenome + 1]); 

        int tamanho_abreviado = 0;

        // fazer um loop para ler o primeiro nome
        // encontrar o espaço, comecando do primeiro caractere
        for (posicao_nome = 0; nome[posicao_nome] != ' '; posicao_nome++);
        

        // loop para printar o nome do xavier
        for (int i = posicao_sobrenome + 1; nome[i] != '\0'; i++){
            nome_abreviado[tamanho_abreviado++] = nome[i];
        }
        nome_abreviado[tamanho_abreviado] = '\0';

        // adiciona a virgula e o espaco
        nome_abreviado[tamanho_abreviado++] = ',';
        nome_abreviado[tamanho_abreviado++] = ' ';

        // adiciona o joaquim
        for (int i = 0; i < posicao_nome; i++){
            nome_abreviado[tamanho_abreviado++] = nome[i];
        }
        nome_abreviado[tamanho_abreviado] = '\0';
        nome_abreviado[tamanho_abreviado++] = ' '; 

        // fazer um loop para percorrer os nomes do meio
        while (posicao_nome < posicao_sobrenome){ // enquanto a posicao do primeiro nome for menor que a posicao do sobrenome
            if (isupper(nome[posicao_nome]) != 0){ // se for letra maiuscula
                nome_abreviado[tamanho_abreviado++] = nome[posicao_nome]; // pega a letra
                nome_abreviado[tamanho_abreviado++] = '.'; // adiciona ponto
                nome_abreviado[tamanho_abreviado++] = ' '; // adiciona virgula
                // avanca até próximo espaço (pula palavra inteira)
                while (posicao_nome < posicao_sobrenome && nome[posicao_nome] != ' ') {
                    posicao_nome++;
                }
            } 
            else {
                posicao_nome++;  // avança normalmente
            }
        }
        printf("%s\n", nome_abreviado); 
    } 
}