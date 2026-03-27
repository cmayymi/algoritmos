// Exemplo de realocacao dinamica de vetores

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // decalracao de variaveis
    int *V = NULL; // ponteiro para o vetor dinamico
    int n; // numero de elementos em vetor

    // leitura do numero de elementos inicial em vetor
    printf("Quantos elementos deve ter o vetor? >> ");
    scanf("%d", &n);

    // aloca V com o tamanho inicial
    printf("Alocando V com o tamanho %d...\n", n);
    V = (int*)realloc(NULL, sizeof(int)*n); // funciona como malloc() (1 alocacao)
    if (!V){
        printf("Erro: não foi possível alocar o vetor!");
        exit(1);
    }

    // preenchendo o vetor com numeros aleatorios
    printf("Preenchendo o vetor com números aleatórios...\n");
    srand(time(NULL)); // inicializa o gerador de numeros aleatorios
    for (int i = 0; i < n; i++){
        V[i] = rand()%(2*n); // preenche com valor aleatorio entre 0 e 2n
    }

    // imprimindo o vetor vetor
    printf("V = [");
    for (int i = 0; i < n; i++){
        printf("%d", V[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");

    // mudando o tamanho do vetor
    printf("Dobrando o tamanho do vetor...\n");
    n *= 2;
    V = (int*)realloc(V, sizeof(int)*n);
    if (!V){
        printf("Erro: não foi possível alocar o vetor!");
        exit(2);
    }

    // imprimindo o vetor vetor
    printf("V = [");
    for (int i = 0; i < n; i++){
        printf("%d", V[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");

    // mudando o tamanho novamente
    // diminuindo o tamanho do vetor
    printf("Reduzindo para 2/3 o tamanho do vetor...\n");
    n *= (float)2/3;
    V = (int*)realloc(V, sizeof(int)*n);
    if (!V){
        printf("Erro: não foi possível alocar o vetor!");
        exit(3);
    }

    // imprimindo o vetor
    printf("V = [");
    for (int i = 0; i < n; i++){
        printf("%d", V[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");

    // desaloca vetor
    free(V);
}