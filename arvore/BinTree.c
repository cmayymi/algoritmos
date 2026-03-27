//arquivo implementação para a árvore binária de busca simples
 
#include <stdlib.h>
#include <stdio.h>
#include "BinTree.h"
 
// inicializacao da lista
void InitList(TListSE *L){
    L->first = NULL;
    L->last = NULL;
    L->lenght = 0;
}

// verifica se a fila está vazia
int isEmpty(TListSE L){
    return (L.lenght == 0);
}

// apagamento da lista
void DeleteList(TListSE *L){
    TNode *aux = L->first;

    while(aux){
        L->first = L->first->next;
        free(aux);
        L->lenght--;
        aux = L->first;
    }
    L->last = NULL;
}

// imprime a lista
void PrintList(TListSE L){
    TNode *aux = L.first;

    printf("[");
    while (aux){
        printf("%d", aux->info->info);
        if (aux->next)
            printf(", ");
    }
    printf("]");
}

// insercao pela direita
int InsertRight(TreeNode *x, TListSE *L){
    TNode *aux = (TNode*)malloc(sizeof(TNode));
    if (aux == NULL)
        return 1;
    aux->info = x;
    aux->next = NULL;

    if (L->last == NULL)
        L->first = L->last = aux;
    else{
        L->last->next = aux;
        L->last = aux;
    }
    L->lenght++;
    return 0;
}

// remocao pela esquerda
TreeNode *RemoveLeft(TListSE *L){
    TNode *aux = L->first;
    TreeNode *ret = aux->info;
    L->first = L->first->next;
    free(aux);
    if (L->first == NULL)
        L->last = NULL;
    L->lenght--;
    return ret;
}

//---------------------
//   função de inserção
//---------------------
TreeNode* insertBinTree(Tdado x, TreeNode *bt) {        //recebe o dado de "entrada" e a raiz da árvore atual
    TreeNode *aux;      //aloca um novo nó auxiliar (que contém o x) para percorrer pela árvore
 
    //verificar se o ponteiro é nulo (bt é nulo; a árvore é nula, ou seja, aponta para o vazio)
    if (!bt) {
        //insere o novo nó
        aux = (TreeNode*)malloc(sizeof(TreeNode));
        if (!aux) {
            printf("Erro: Memória insuficiente!\n");
            return bt;
        }
        else {
            aux->info = x;          //pega o valor de x e copia para dentro do campo info
            aux->left = NULL;       //
            aux->right = NULL;      //
            return aux;
        }
    }   //se não for nulo, realiza a inserção
    else if(x < bt->info) {
        //x é menor que o valor do nó atual, desce pelo lado esquerdo
        bt->left = insertBinTree(x, bt->left);      //insere no ramo esquero
        return bt;
    }
    else {
        //x é maior do que o valor do nó atual, desce pelo lado direito
        bt->right = insertBinTree(x, bt->right);    //insere no ramo direito
        return bt;
    }
 
}
 
//função de remoção por merge (por promoção)
TreeNode* deleteByMerge(TreeNode *bt, Tdado x) {
    TreeNode *p, *p2;
 
    if (bt == NULL) {   //árvore vazia ou fim da árvore
        return NULL;
    }
    else if(bt->info == x) {
        //apaga a raiz da subárvore
        if (bt->left == bt->right) {        //filho esquerdo igual ao filho direito (não existem, são nulos); é apenas uma folha
            //subárvore com apenas um elemento, no caso, a raiz
            free(bt);
            return NULL;
        }
        else if (bt->left == NULL) {        //se o lado esquerdo é nulo, há apenas filhos do lado direito
            p = bt->right;
            free(bt);                       //apaga o pai
            return p;                       //filho substitui o pai e o liga ao avô
        }
        else if (bt->right == NULL) {       //se o lado direito é nulo, há apenas filhos do lado esquerdo
            p = bt->left;
            free(bt);                       //mata o pai
            return p;                       //filho substitui o pai e o liga ao avô
        }
        else {
            p2 = bt->left;  //guarda o endereço do filho esquerdo (novo herdeiro)
            p = p2;
 
            //achar o último descendente mais à direita do ramo esquerdo
            while (p->right != NULL) {
                p = p->right;
            }
            p->right = bt->right;       //onde for encontrado o local nulo, o bt (irmão) à direita vai para o lugar de último herdeiro
            free(bt);
            return p2;
        }
    }
    else if (bt->info > x) {
        bt->left = deleteByMerge(bt->left, x);
    }
    else {
        bt->right = deleteByMerge(bt->right, x);
    }
    return bt;          //conectando os ponteiros
}
 
//função remoção por cópia
TreeNode* deleteByCopy(TreeNode *bt, Tdado x) {
    TreeNode *t1, *temp;    //um marca o nó a ser removido e o outro para descer pela árvore
 
    if (bt == NULL) {   //chegou em um nó nulo, retorna nulo
        return NULL;
    }
    if (bt->info == x) {    //achou o elemento a ser apagado
        if (bt->right == NULL) {        //se não há filhos à direita
            t1 = bt->left;
            free(bt);
            return t1;
        }
        else if (bt->left == NULL) {    //se não há filhos à esquerda
            t1 = bt->right;
            free(bt);
            return t1;
        }
        else {
            temp = bt->right;               //temp é o filho direito
            while (temp->left != NULL) {
                temp = temp->left;
            }
            bt->info = temp->info;
            bt->right = deleteByCopy(bt->right, temp->info);
        }
    }
    else if (bt->info > x) {
        bt->left = deleteByCopy(bt->left, x);
    }
    else {
        bt->right = deleteByCopy(bt->right, x);
    }
    return bt;
}
 
//função de impressão (da esquerda para a direita, sendo o elemento mais à esquerda a raiz e os elementos seguintes, as ramificações/filhos)
void printBinTree(const TreeNode *bt, int level) {      //level indicia o nível de descendência da árvore
    int i;
 
    if (!bt) {
        return;
    }
    else {
        printBinTree(bt->right, level + 1);     //incrementa o nível em 1
        for (i = 0; i < level; i++) {
            printf("----|");
        }
        printf(WHITE_RED "%u" RESET "\n", bt->info);
        printBinTree(bt->left, level + 1);
    }
}
 
//função que apaga toda a árvore com raiz em bt
void freeBinTree(TreeNode* bt) {
    if(!bt){
        return;
    }
    freeBinTree(bt->left);
    freeBinTree(bt->right);
    free(bt);
    bt = NULL;
}
 
//------------------------
//busca em profundidade
//------------------------
 
//  *percurso em pré-ordem*
void preOrdem(TreeNode* bt) {
    if (!bt) return;            //se o nó for nulo
    printf("%u ", bt->info);              //visitar o nó
    preOrdem(bt->left);         //percorre à esquerda do nó
    preOrdem(bt->right);        //percorre à direita do nó
}
 
//  *percurso em ordem*
void emOrdem(TreeNode* bt) {
    if (!bt) return;            //se o nó for nulo
    emOrdem(bt->left);         //percorre à esquerda do nó
    printf("%u ", bt->info);              //visitar o nó
    emOrdem(bt->right);        //percorre à direita do nó
}
 
//  *percurso em pós-ordem*
void posOrdem(TreeNode* bt) {
    if (!bt) return;            //se o nó for nulo
    posOrdem(bt->left);         //percorre à esquerda do nó
    posOrdem(bt->right);        //percorre à direita do nó
    printf("%u ", bt->info);              //visitar o nó
}
 
// calculando a altura da árvore
int height(const TreeNode* bt) {
    if(!bt) return 0;       //árvore vazia tem altura 0
    int leftH = height(bt->left);
    int rightH = height(bt->right);
    if(leftH > rightH) {
        return leftH + 1;
    }
    else {
        return rightH + 1;
    }
}
 
//  calculando o número de nós por nível
void countL(const TreeNode* bt, int* counts, int level) {
    if(!bt) return;
    counts[level]++;
    countL(bt->left, counts, level + 1);
    countL(bt-> right, counts, level + 1);
}
 
//  calculando a largura da árvore
int width(TreeNode* bt){
    if(!bt) 
        return 0;
    int h = height(bt);
    if (h < 0) 
        return 0;
 
    int* counts = (int*)calloc(h, sizeof(int));
    if(!counts) 
        return 0;
 
    countL(bt, counts, 0);
 
    int max = counts[0];
    for (int i = 1; i < h; i++){
        if (counts[i] > max){
            max = counts[i];
        }
    }
    free(counts);
    return max;
}

// busca por largura
void largura (TreeNode *bt){
    if (!bt)
        return;
    TListSE fila;
    InitList(&fila);
    InsertRight(bt, &fila);
    while(!isEmpty(fila)){
        TreeNode *atual = RemoveLeft(&fila);
        printf("%u", atual->info); //visitar o no
        if (atual->left)
            InsertRight(atual->left, &fila);
        if (atual->right)
            InsertRight(atual->right, &fila);
    }
}

// contar nós
int contar_node(const TreeNode* bt){
    if (!bt)
        return 0;
    return 1 + contar_node(bt->left) + contar_node(bt->right);
}

// procurar um numero na arvore e dizer o local em que ele ta

  