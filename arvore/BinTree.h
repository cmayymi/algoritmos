/* 
    binTree.h
    header file para árvore binária de busca simples
*/

#include <stdlib.h>

// codigo para limpar a tela
#define CLEAR "\033[0;0;0m"
#define WHITE_RED "\033[97;101m"
#define RESET "\033[0m"

//-----------------------------------------------------------------
// Definição do tipo de dado armazenado na árvore
//-----------------------------------------------------------------
typedef unsigned Tdado;

//-----------------------------------------------------------------
// Definição da estrutura nó de árvore
//-----------------------------------------------------------------
typedef struct TreeNode
{
    Tdado info; // dado armazenado no nó
    struct TreeNode *left; // ponteiro para o ramo esquerdo
    struct TreeNode *right; // ponteiro para o ramo direito
} TreeNode;

//-----------------------------------------------------------------
// Definição do tipo nó de lista simplesmente encadeado
//-----------------------------------------------------------------
typedef struct TNode{
    TreeNode* info;
    struct TNode *next;
} TNode;

//-----------------------------------------------------------------
// Definição do tipo lista simplesmente encadeada
//-----------------------------------------------------------------
typedef struct{
    TNode *first;
    TNode *last;
    int lenght;
} TListSE;

//-----------------------------------------------------------------
// Função de inserção
//-----------------------------------------------------------------
TreeNode* insertBinTree(Tdado x, TreeNode *bt);

//-----------------------------------------------------------------
// Função de remoção por merge (promoção de um dos filhos)
//-----------------------------------------------------------------
TreeNode *deleteByMerge(TreeNode *bt, Tdado x);

//-----------------------------------------------------------------
// Valor minímo de uma árvore
//-----------------------------------------------------------------
Tdado minTree(TreeNode *bt);

//-----------------------------------------------------------------
// Remoção por cópia
//-----------------------------------------------------------------
TreeNode* deleteByCopy(TreeNode *bt, Tdado x);

//-----------------------------------------------------------------
// Função de impressão
//-----------------------------------------------------------------
void printBinTree(const TreeNode *bt, int level);

//-----------------------------------------------------------------
// Apaga toda a árvore com raiz em bt *
//-----------------------------------------------------------------
void freeBinTree(TreeNode* bt);

//-----------------------------------------------------------------
// Percorre a árvore em pré ordem
//-----------------------------------------------------------------
void preOrdem(TreeNode* bt);

//-----------------------------------------------------------------
// Percorre a árvore em ordem
//-----------------------------------------------------------------
void emOrdem(TreeNode* bt);

//-----------------------------------------------------------------
// Percorre a árvore em pós ordem
//-----------------------------------------------------------------
void posOrdem(TreeNode* bt);

//-----------------------------------------------------------------
// Calcula a altura da árvore
//-----------------------------------------------------------------
void largura (TreeNode *bt);

//-----------------------------------------------------------------
// Calcula a altura da árvore
//-----------------------------------------------------------------
int height(const TreeNode* bt);

//-----------------------------------------------
//  countL: calculando o número de nós por nível
//----------------------------------------------
void countL(const TreeNode* bt, int* counts, int level);
 
//---------------------------------------
//  width: calculando a largura da árvore
//---------------------------------------
int width(TreeNode* bt);

// definicoes das funcoes sobre listas simplesmente encadeadas

// inicializando a lista
void InitList(TListSE *L);

// verifica se a fila esta vazia
int isEmpty(TListSE L);

// apagamento da lista
void DeleteList(TListSE *L);

// imprime a lista
void PrintList(TListSE L);

// remocao pela direita
int InsertRight(TreeNode *x, TListSE *L);

// remocao pela esquerda
TreeNode *RemoveLeft(TListSE *L);

// contar os nós
int contar_node(const TreeNode* bt);

// procurar o endereço de um nó
int buscar_node(TreeNode* bt);