#include <stdio.h>
#include "BinTree.h"
 
void clear() {
    printf(CLEAR); //escape codes para limpar a tela
}
 
//função principal
int main() {
    TreeNode* bt = NULL;
    int op = 0, v = 0;
 
    do {
        clear();
        printf("Árvore atual:\n\n");
        printBinTree(bt, 0);
        printf("\nPercurso em Pré-ordem: ");
        preOrdem(bt);
        printf("\n\n");
        printf("\nPercurso em ordem: ");
        emOrdem(bt);
        printf("\n\n");
        printf("\nPercurso em Pós-ordem: ");
        posOrdem(bt);
        printf("\n\n");
        printf("Altura da árvore = %d\n\n", height(bt));
        printf("\n\n");
        printf("\nPercurso em Largura: ");
        largura(bt);
        printf("Largura da árvore = %d\n\n", width(bt));
        // printf("Número de nós: %d\n\n", countL(bt));
        printf("Selecione a opção desejada:\n");
        printf("(0) sair\n");
        printf("(1) inserir\n");
        printf("(2) remoção por merge\n");
        printf("(3) remoção por cópia\n");
        printf("Opção >> ");
        scanf("%d", &op);
        switch (op) {
            case 0:
                printf("Programa encerrado!\n");
                break;
            case 1:
                printf("Qual valor? >> ");
                scanf("%d", &v);
                bt = insertBinTree(v, bt);
                break;
            case 2:
                printf("Qual valor? >> ");
                scanf("%d", &v);
                bt = deleteByMerge(bt, v);
                break;
            case 3:
                printf("Qual valor? >> ");
                scanf("%d", &v);
                bt = deleteByCopy(bt, v);
                break;
            default:
                printf("Opção inválida!\n");
        }
    }
    while (op != 0);
    freeBinTree(bt);
    return 0;
}
 