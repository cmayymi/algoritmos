// listSE.c
// Exemplos de algoritmos com listas encadeadas

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// define o tipo de dado a ser colocado na lista
typedef short Tdata; 

//tipo de dado para lista encadeada
typedef  struct TNode
{
	Tdata info; // dado armazenado no nó
	struct TNode *next;	// ponteiro para o próximo nó
} TNode;

typedef struct TListSE
{
	TNode *first;
	TNode *last;
	short length;
} TListSE;

//===========================================
//
// Funções sobre listas encadeadas
//
//===========================================

// Inicialização da lista
void initList(TListSE *L)
{
	L->first = NULL;
	L->last = NULL;
	L->length = 0;
}

// destruição da lista
void deleteList(TListSE *L)
{
	TNode *p = L->first;
	while (p)
	{
		L->first = L->first->next;
		free(p);
		L->length--;
		p = L->first;
	}
	L->last = NULL;
}

// verifica lista vazia
bool emptyList(TListSE L)
{
	return (L.length == 0);
}

// escreve a lista;

void printList(TListSE L)
{
	TNode *p = L.first;
	
	printf("[");
	while (p)
	{
		printf("%hd", p->info);
		if (p->next)
			printf(", ");
		p = p->next;
	}
	printf("]");
}

// inserção pela esquerda
short insertLeft(Tdata x, TListSE *L)
{
	TNode *aux;
	aux = (TNode*)malloc(sizeof(TNode));
	if (aux == NULL)	// falha na alocação
		return 1;	// sinaliza com erro, deixando a lista original intacta
	else
	{ // insere x na lista
		aux->info = x;					// atribui x para o campo info
		aux->next = L->first;		// insere o elemento antes do atual primeiro
		L->first = aux;					// Faz o ponteiro do primeiro apontar para o novo nó
		if (L->last == NULL)		// lista estava vazia
			L->last = aux;				// primeiro elemento é também o último
		L->length++;						// incrementa o tamanho da lista
		return 0;								// fim normal
	}
}

// inserção pela direita
short instertRight(Tdata x, TListSE *L)
{
	TNode *aux;
	aux = (TNode*)malloc(sizeof(TNode));
	if (aux == NULL)	// falha na alocação
		return 1;	// sinaliza com erro, deixando a lista original intacta
	else
	{ // insere x na lista
		aux->info = x;					// atribui x para o campo info
		aux->next = NULL;				// nao vai ter nenhum dps do auxiliar, logo é null

		if (L->last == NULL){		    // se a lista estava vazia
			L->last = aux;				// primeiro elemento é também o último
			L->first = aux; 			// primeiro elemento é também o primeiro
		}

		// se nao tiver sozinha
		L->last->next = aux;				// liga primeiro o next no proximo
		L->last = aux;					// dps faz o ultimo ponteiro apontar para o novo nó

		L->length++;						// incrementa o tamanho da lista
		return 0;								// fim normal
	}
}

//remocao pela esquerda
void removeLeft(TListSE *L) {
    TNode *aux;
    aux = L->first; //a variavel de ponteiro aux recebe o primeiro elemento da lista
    L->first = L->first->next; //avança para o próximo nó
    free(aux); //tira o cara enderaçado por aux da memoria
    if (L->first == NULL) { //lista fica vazia
        L->last == NULL; //anula-se last tambem
    }    
    L->length--; //reduz o tamanho da lista
}

//remocao pela direita
void removeRight(TListSE *L) {
    TNode *aux;
    if (L->first == L->last) { //se a lista tem apenas um item
        free(L->first); //libera o nó no first
        L->last = L->first = NULL; //ambos sao anulados
    }
    else {
        while (aux->next->next != NULL) { //laço pra percorrer a lista e procura o penúltimo
            aux = aux->next; //aux aponta para o endereço do next, ou seja, do proximo item da lista
            L->last = aux; //ultimo recebe o atual endereço do aux (penultimo é o ultimo novo)
            free(aux->next); //libera o ultimo
            L->last->next = NULL; //anula o penultimo pra nao deixar ninguem sobrando
        }
        L->length--;
    }
}

//busca de elementos dentro da lista
TNode* searchL(Tdata x, TListSE *L) {
    TNode *aux = L->first;
    
    //andando pela lista
    while (aux && aux->info != x) { //enquanto o endereço ou a informacao do auxiliar forem distintos do valor desejado
        aux = aux->next; //auxiliar recebe o proximo
    }
    return aux; //retorna o endereço do valor desejado
}

// funcao para somar todos os elementos da lista
int soma_lista(TListSE L){
	// ler a lista
	TNode *aux = L.first;
	int soma = 0;
	while (aux){ // enquanto o auxiliar nao for nulo
		soma += aux -> info;
		aux = aux->next;
	}
	return soma;
}

// funcao que vai atribuir um valor v na lista L na posicao x
int atribuicao_valor(Tdata V, TListSE L, int pos){
	TNode *aux = L.first;
	int i = 0;

	if (pos >= L.length)
		return 1;
	else{
		while (i != pos){
			i++;
			aux = aux-> next;
		}
		aux->info=V;
	}
}

// funcao que em uma lista L na posicao x, ao chegar nesse posicao, retorna o valor
int busca_posicao(TListSE *L, int pos, int *v){
	if(L->length <= pos || pos < 0){
        return 1;
    } else {
        TNode *aux = L->first;
        int i = 0;
        while (i != pos){   
            aux = aux->next;
            i++;
        }
        *v = aux->info;
        return 0;
    }
    return 1;
}

// funcao que calcula a media na lista	
int media(TListSE *L, int *quantidade){
	TNode *aux = L->first;
 
    int soma = 0;
 
    if(L->length == 0)
        return 1;
    else{
        *quantidade = aux->info;
        aux = aux->next;
        return 0;
    }
    return 1;
}

int main(){
	// variaveis
	TListSE L1;
	short a;
	printf("Inicializando a lista.\n");
	initList(&L1);
	printf("Lista Inicializada.\n");
	if (emptyList(L1)){
		printf("Lista vazia.\n");
	}
	printList(L1);
	printf("\n");

	// inserindo elementos na lista
	instertRight(1, &L1);
	instertRight(1, &L1);
	printList(L1);
	printf("\n");

	printf("A soma dos elementos é: %d\n", soma_lista(L1));
	
	atribuicao_valor(4, L1, 1);
	printList(L1);
	printf("\n");

	deleteList(&L1);
}