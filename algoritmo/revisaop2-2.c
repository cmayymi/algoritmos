// calculo do dia de semana de acordo com a data nos calendarios

#include <stdio.h>

char data[10]; // incluindo o \0
int dia, mes, ano, K, J, dia_semana;

int main(){
    while(scanf("%[^\n]s", data) != EOF){
        getchar();  // consome o \n do buffer

        // utilizar a tabela ascii
        // fazer o valor - '0' 

        // descobrir o dia
        dia = (data[0] - '0') * 10 + (data[1] - '0'); // *10 pois o primeiro numero é decimal

        // descobrir o mes
        mes = (data[3] - '0') * 10 + (data[4] - '0');

        // descobrir o ano
        ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + (data[8] - '0') * 10 + (data[9] - '0');

        if (mes <= 2){ // se o mes for janeiro, o mes tem valor 13 e o ex pede que eles vao ser considerados do ano anterior
            mes += 12;
            ano--;
        }

        // descobrir o K e o J
        K = ano%100; // dois ultimos digitos do ano
        J = ano/100; // dois primeiros digitos do ano 

        dia_semana = (dia + (13 * (mes + 1)/5) + K + (K/4) + (J/4) - 2*J)%7;

        switch (dia_semana)
        {
        case 0:
            printf("sábado\n");
            break;

        case 1:
            printf("domingo\n");
            break;

        case 2:
            printf("segunda-feira\n");
            break;

        case 3:
            printf("terça-feira\n");
            break;

        case 4:
            printf("quarta-feira\n");
            break;

        case 5:
            printf("quinta-feira\n");
            break;

        case 6:
            printf("sexta-feira\n");
            break;
        }
    }
}