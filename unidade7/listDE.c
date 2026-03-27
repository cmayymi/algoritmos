//listas duplamente encadeadas
//em listas duplamente encadeadas, são utilizados dois tipos de nó, um ponteiro que aponta para o nó anterior
//e outro que aponta para o próximo (previamente apresentado)
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
 
//definindo o tipo de dado que será utilizado na lista 
typedef short Tdata;
 
//tipo de dado para a lista encadeada 
typedef struct TNode {
    Tdata info; //dado que está armazenado no nó
    struct TNode *prev; //ponteiro para o nó anterior
    struct TNode *next; //ponteiro para o nó posterior
} TNode;
 
typedef struct TListDE {
    TNode *first;
    TNode *last;
    short length;
} TListDE;
 
//inicializa a lista 
void initList(TListDE *L) {
    L->first = NULL;
    L->last = NULL;
    L->length = 0;
}
 
//destruição da lista 
void deleteList(TListDE *L) {
    TNode *p = L->first;
    while (p) {
        L->first = L->first->next;
        free(p);
        p = L->first;
    }
    L->last = NULL; //só no final que o last será anulado, diferente das listas simplesmente encadeadas
    L->length = 0;
}
 
//verifica lista vazia
bool emptyList(TListDE L) {
    return (L.length == 0);
}
 
//escrevendo a lista 
void printList(TListDE L, bool inverse) { //inverse indica se a lista será a escrita da forma padrão ou inversa
    TNode *p;
    if (!inverse) { //se for falso, vai escrever do começo até o fim
        printf("First->");
        p = L.first;
        while(p) { //enquanto p for verdadeiro
            printf("[%hd]->", p->info);
            p = p->next;
        }
        printf("[NULL]"); //Ex de impressão: First->[A]->[B]->[C]->[NULL]
    }
    else { //inverse está em verdadeiro, ou seja, escreve do fim ao começo
        printf("Last->");
        p = L.last; //o ponteiro p recebe o último
        while(p) {
            printf("[%hd]->", p->info); //inteiro curto, por isso %hd
            p = p->prev;
        }
        printf("[NULL]"); //Ex de impressão: Last->[C]->[B]->[A]->[NULL]
        }
    }
 
//inserção pela esquerda
short insertLeft(Tdata x, TListDE *L) {
    TNode *aux;
    aux = (TNode*)malloc(sizeof(TNode));
    if (aux == NULL) { //checa falha na alocação
        return 1;
    }
    else {
        aux->info = x; //x vai para o campo info
        aux->next = L->first; //insere elemento antes do atual primeiro
        aux->prev = NULL; //não tem anterior
        if (L->first != NULL) //tinha alguém antes
            L->first->prev = aux; //anterior do primeiro nó recebe o aux
        L->first = aux; //faz o ponteiro do primeiro apontar para o novo nó 
        if (L->last == NULL)  //lista estava vazia?
            L->last = aux;      //último recebe o aux
        L->length++; //aumenta o tamanho da lista
        return 0;
    }
}
 
//inserção pela direita
short insertRight(Tdata x, TListDE *L) {
    TNode *aux;
    aux = (TNode*)malloc(sizeof(TNode));
    if (aux == NULL) { //checa falha na alocação
        return 1;
    }
    else {
        aux->info = x; //x vai para o campo info
        aux->next = NULL; //não há próximo
        aux->prev = L->last; //anterior é o antigo último
        if (L->last == NULL) //lista já estava vazia
            L->first = L->last = aux; //atualiza o primeiro e o último, pois só tem ele na lista
        else {                          //atualiza só os últimos
            L->last->next = aux;        //liga o novo último ao nó
            L->last = aux;          //atualiza o ponteiro para o novo último
        } 
        L->length++; //aumenta o tamanho da lista
        return 0;
    }
}
 
//remoção pela esquerda
void removeLeft(TListDE *L) {
    TNode *aux = L->first;          //guarda o nó a ser removido
    L->first = L->first->next;      //primeiro vai para o próximo nó
    free(aux);                      //libera o aux
    if (L->first == NULL)           //se o primeiro é anulado
        L-last = NULL;
    else                            //se não é nulo
        L->first->prev = NULL;      //primeiro vai para o anterior
    L->length--;                    //diminui o tamanho da lista
}
 
//remoção pela direita
void removeRight(TListDE *L) {      
    TNode *aux = L->last;           //guarda o nó a ser removido
    L->last = L->last->prev;        //último vai para o nó anterior
    free(aux);                      //libera aux
    if (L->last == NULL)            //se o último for nulo...
        L->first = NULL;
    else
        L->last->next = NULL;       //o próximo do último será anulado
    L->length--;                    //diminui o tamanho da lista
}
 
//busca por elemento
TNode* searchList(Tdata x, TListDE *L) {
    TNode *aux = L->first;
    while (aux && aux->info != x) {
        aux = aux->next;
    }
    return aux;
}
 
int main() {
 
    return 0;
}