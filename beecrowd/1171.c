#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int numeros[n]; // armazena os numeros lidos
    int frequencia[2001] = {0}; // inicializa em 0

    for (int i = 0; i < n; i++) // le os numeros
        scanf("%d", &numeros[i]);

    for (int j = 0; j < n; j++) // percorre todos os numeros armazenados no vetor
    {
        int x = numeros[j]; 
        if (x >= 1 && x <= 2000) // verifica se esta no intervalo 
            frequencia[x]++; // incrementa a contagem do numero x
    }

    // percorrer frequencia
    for (int k = 1; k <= 2000; k++)
    {
        if (frequencia[k] > 0)
            printf("%d aparece %d vez(es)\n", k, frequencia[k]);
    }
}