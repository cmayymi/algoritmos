// execicio de alocacao de vetor
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *v;  // vetor dinamico
    // se fosse vetor estatico era v[]
    // o * significa que ele ta tratando v como um ponteiro que 
    // aloca esse v para uma regiao de memoria de tamanho indefinido
    int n; // tamanho de v
    int l; // numero de linhas de m

    int **m; // matriz dinamica
    // matriz sao 2 asteriscos

    printf("Qual o tamanho do vetor? ");
    scanf("%d", &n);

    // tenta alocar o vetor
    v = malloc(sizeof(int)*n); // sizeof de um int indica que eu estou alocando o numero de bytes de um inteiro
    if (v == NULL){
        printf(" Erro 1: Memória insuficiente.\n");
        return 1;
    }

    // manipular o vetor
    for (int i = 0; i < n; i++)
        v[i] = i + 1;

    // escreve o vetor
    for (int i = 0; i < n; i++){
        printf("%d", v[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("\n");

    // desaloca o vetor
    free(v);
    
    // alocacao de matriz dinamica
    printf("Quantas linhas? ");
    scanf("%d", &l);
    printf("Quantas colunas? ");
    scanf("%d", &n);

    // tenta alocar o vetor de linhas
    m = (int**)malloc(l * sizeof(int*));
    if (m == NULL){
        printf(" Erro 2: Memória insuficiente.\n");
        return 2;
    }

    // tenta alocar os vetores de linhas
    for (int i = 0; i < l; i++){
        m[i] = (int*)malloc(n*sizeof(int));
        if (m[i] == NULL){
            printf(" Erro 3: Memória insuficiente.\n");
            return 3;
        }
    }

    // manipula a matriz
    for (int i = 0; i < l; i++){
        for (int j = 0; j < n; j++){
            m[i][j] = i + j;
        }
    }

    // escreve a matriz
    for (int i = 0; i < l; i++){
        for (int j = 0; j < n; j++){
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }

    // desaloca a matriz
    for (int i = 0; i < l; i++){
        free(m[i]);
    }
    free(m);

    return 0;
}