// lista simplesmente encadeada
#include <stdio.h>
#include <stdlib.h>

int numero_casos, pessoas, passos;

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
void deleteList(TListSE *L){
    if (L->last && L->last->next == L->first){
        // estava circular -> quebrar o ciclo
        L->last->next = NULL;
    }

    TNode *p = L->first;
    while (p){
        TNode *nxt = p->next;
        free(p);
        p = nxt;
    }
    L->first = L->last = NULL;
    L->length = 0;
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

// funcao para printar a lista
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

// torna a lista circular (last->next = first), se não estiver vazia
void circular(TListSE *L) {
    if (L->last != NULL) {
        L->last->next = L->first;
    }
}

// funcao para pular numeros na lista e remover os que eu quero
short puloList(TListSE *L, int pulo){
	if (L->length == 0) 
		return -1;

    circular(L); // transformar a lista em circular

    TNode *atual = L->first; // nó corrente (candidato a ser removido)
    TNode *anterior = L->last;  // nó anterior ao corrente (necessário para remoção)

    while (L->length > 1){
        // andar passos-1 passos
        for (int i = 1; i <= passos - 1; ++i){
            anterior = atual;
            atual = atual->next;
        }

        // remover 'atual'
        // manter first/last coerentes
        if (atual == L->first)
            L->first = atual->next;
        if (atual == L->last)
            L->last = anterior;

        anterior->next = atual->next; // salta o removido
        TNode *proximo = atual->next;
        free(atual);
        L->length--;

        atual = proximo; // continua a partir do próximo
    }

	// único nó restante
    int sobrevivente = L->first->info;

    // descircularizar para permitir deleteList/prints
    L->last = L->first;
    L->first->next = NULL;

    return sobrevivente;
}

int main(){
    scanf("%d", &numero_casos);
    for (int i = 0; i < numero_casos; i++){
        scanf("%d %d", &pessoas, &passos);
		TListSE L1;
        initList(&L1); // inicializou a lista
        for (int j = 1; j <= pessoas; j++){
            instertRight(j, &L1); // colocou todas as pessoas na lista
        }

        // printa o resultado e deleta a lista
        printf("Case %d: %d\n", i + 1, puloList(&L1, passos));
        deleteList(&L1);
    }
}