#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // 1. declaracao de variaveis
    int **M = NULL; // ponteiro para matriz dinamica
    int m, n; // numero de linhas e colunas da matriz dinamica M

    // 2. leitura das dimensoes originais da matriz dinamica
    printf("Quantas linhas e colunas tem a matriz? >> ");
    scanf("%d %d", &m, &n);

    // 3. alocacao da matriz
    printf("Alocando a matriz...\n");
    M = (int**)calloc(m, sizeof(int*)); // aloca o vetor ponteiros para linhas
    if (!M){
        printf("Erro 1: Não é possível alocar a matriz!\n");
        exit(1);
    }

    for (int i = 0; i < m; i++){
        M[i] = (int*)calloc(n, sizeof(int));
        if (!M[i]){
            printf("Erro 2: Não é possível alocar a matriz!\n");
            exit(2);
        }
    }

    // 4. preenche a matriz com valores aleatorios
    printf("Preenchendo a matriz com valores aleatórios...\n");
    srand(time(NULL)); // inicia a semente de gerador de numeros aleatorios
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            M[i][j] = rand() % (m*n);
            printf("M[%d][%d] = ");
        }
    }

    // 5. 
     printf("Imprimindo a matriz:\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j ++){
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }


    // 6. realocando a matriz para dobrar o numero de linhas e colunas
    printf("Ampliando a matriz com realloc()\n");

    // 6.1 dobrando o numero de linhas
    M = (int**)realloc(M, sizeof(int*) * 2*m); // dobra o numero de linhas
    if (!M){
        printf("Erro 3: Não é possível alocar a matriz!\n");
        exit(3);
    }

    // 6.2 dobrando o numero de colunas para linha recem adicionada
    for (int i = 0; i < 2*m; i++){
        M[i] = (int*)realloc(M[i], sizeof(int) * 2*n); // dobra o numero de colunas
        if (!M[i]){
            printf("Erro 4: Não é possível alocar a matriz!\n");
            exit(4);
        }
    }

    // 7. preencher somente as novas posicoes com 1
    // 7.1. preenchendo as novas colunas das linhas pre-existentes

        //preencher as novas colunas das linhas pre existentes
    printf("preenchendo as novas posicoes com '1'\n");
    for(int i = 0; i < m; i++){
        for(int j = n; j < 2 * n; j++){
            M[i][j] = 1;
            printf("M[%d][%d] = %d\n", i, j, M[i][j]);
        }
    }

    //preenchendo as novas linhas
    printf("preenchendo as novas linhas com '1'\n");
    for(int i = m; i < m * 2; i++){
        for(int j = 0; j < 2 * n; j++){
            M[i][j] = 1;
            printf("M[%d][%d] = %d\n", i, j, M[i][j]);
            }
    }


    // 8. imprimir a matriz apos a expansao
    printf("Imprimindo a matriz expandida...\n");
    for (int i = 0; i < 2 * m; i++){
        for (int j = 0; j < 2 * n; j++){
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }

    // 9. desaloca a matriz
    for (int i = 0; i < 2 * m; i++){
        free(M[i]); // desaloca cada M[i]
    }
    free(M); // desaloca M
}