// a trilha mais facil é a que, em um dos sentidos do percurso, exige o menor esforço de subida
// o esforco exigido em um trecho de subida é proporcional ao desnivel do trecho

#include <stdio.h>

int quantidade_trilha, pontos, esforco_ida = 0, esforco_volta = 0;
int menor_esforco, trilha;

int main(){
    scanf("%d", &quantidade_trilha);
    // leitura das variaveis
    for (int numero_trilha = 0; numero_trilha < quantidade_trilha; numero_trilha++){
        scanf("%d", &pontos);
        int altura[pontos];
        for (int i = 0; i < pontos; i++){
            scanf("%d", &altura[i]);
        }

        // calculo de subida do h1 para o hm
        for (int j = 0; j < pontos - 1; j++){
            if (altura[j] < altura[j+1])
                esforco_ida += altura[j+1] - altura[j];
        }

        // calculo de subida do hm para o h1
        for (int k = pontos - 1; k > 0; k--){
            if (altura[k] < altura[k-1])
                esforco_volta += altura[k-1] - altura[k];
        }

        printf("%d %d\n", esforco_ida, esforco_volta);

        if (numero_trilha == 0){
            if (esforco_ida > esforco_volta)
                menor_esforco = esforco_volta;
            else
                menor_esforco = esforco_ida;
            trilha = numero_trilha + 1;
        }
        else
            if (menor_esforco > esforco_ida){
                menor_esforco = esforco_ida;
                trilha = numero_trilha + 1;
            }
            else if (menor_esforco > esforco_volta){
                menor_esforco = esforco_volta;
                trilha = numero_trilha + 1;
            }

        esforco_ida = 0;
        esforco_volta = 0;
    }
    printf("%d\n", trilha);
}