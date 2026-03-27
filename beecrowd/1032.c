#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int primo(int n){
    int i, fim;
    if (n == 2)
        return 1;
    else if ((n % 2) == 0)
        return 0;
    else{
        fim = (int)sqrt(n);
        for (i = 3; i <= fim; i+= 2){
            if ((n % i) == 0)
                return 0;
        }
    }
}

int puloList(TListSE *L){
    // circulariza
    if (L.last) 
        L.last->next = L.first;

    TNode *atual = L.first; // nó “corrente”
    TNode *proximo = L.last;  // anterior ao corrente

    int last_prime = 1;    // para gerar 2 como primeiro próximo primo
    while (L.length > 1){
        int k = next_prime(&last_prime);     // próximo primo: 2,3,5,7,...
        int step = k % L.length;             // reduzir passos
        if (step == 0) step = L.length;

        // andar (step-1) nós; o próximo nó 'curr' será removido
        for (int t = 1; t <= step - 1; ++t){
            prev = atual;
            atual = atual->next;
        }

        // remover atual
        if (atual == L.first)  L.first = atual->next;
        if (atual == L.last)   L.last  = prev;

        prev->next = atual->next;
        TNode *next = atual->next;
        free(atual);
        L.length--;

        atual = next;
    }

    int ans = L.first->info;

    // descirculariza para liberar memória
    L.last = L.first;
    L.first->next = NULL;

    return ans;
}

int main(){
    int pulo;
    scanf("%d", &pulo);
    TListSE L; 
    initList(&L);
    for (int i = 1; i <= pulo; ++i){
        insertRight(i, &L);
    }

}