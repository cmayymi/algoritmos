#include <stdio.h>
#include <string.h>

#define max_blocos 25

int numero_blocos, origem, destino;
char comando[8]; // move/pile/quit
char modificador[8]; // onto/over

// estruturas para os blocos
int pilha[max_blocos][max_blocos]; // bloco na posição k da pilha i
int topo[max_blocos]; // quantidade de blocos em cada pilha i
int pos[max_blocos]; // em qual pilha o bloco está 

void devolver_acima(int x){ // devolve os blocos acima de 'x' para suas posições iniciais
    int p = pos[x];
    int h = 0; // encontra a altura de x na pilha p
    while (h < topo[p] && pilha[p][h] != x) h++;

    // move cada bloco acima de x de volta para sua pilha original
    for (int i = topo[p] - 1; i > h; i--) {
        int b = pilha[p][i];
        topo[p]--; // remove do topo de p
        // coloca b na sua pilha de origem, que é b
        pilha[b][topo[b]++] = b;
        pos[b] = b;
    }
}

void mover_somente_x(int x, int pd){ // empilha o bloco x no topo da pilha destino 'pd'
    int p = pos[x];
    int h = 0; // altura de x em p
    while (h < topo[p] && pilha[p][h] != x) h++;
    // remove x
    topo[p] = h;  // tudo que estava acima já foi devolvido antes, corta a pilha em x
    // coloca x em pd
    pilha[pd][topo[pd]++] = x;
    pos[x] = pd;
}

// move a pilha que começa em x (x e acima) para o topo da pilha pd
void empilhar_a_partir_de_x(int x, int pd){
    int p = pos[x];
    // acha altura de x em p
    int h = 0;
    while (h < topo[p] && pilha[p][h] != x) h++;
    // move na ordem (x, x+acima) para pd
    for (int i = h; i < topo[p]; i++){
        int b = pilha[p][i];
        pilha[pd][topo[pd]++] = b;
        pos[b] = pd;
    }
    topo[p] = h; // removeu tudo a partir de x
}

int main(){
    if (scanf("%d", &numero_blocos) != 1) return 0;

    for (int i = 0; i < numero_blocos; i++){ // cada bloco i começa sozinho na pilha i
        pilha[i][0] = i;
        topo[i] = 1;
        pos[i] = i;
    }

    while (1){
        if (scanf("%s", comando) != 1)
            break;
        if (strcmp(comando, "quit") == 0) 
            break;

        scanf("%d %s %d", &origem, modificador, &destino);

        // ignorar se origem == destino ou se estão na mesma pilha
        if (origem == destino || pos[origem] == pos[destino]) 
            continue;

        if (strcmp(comando, "move") == 0 && strcmp(modificador, "onto") == 0){
            devolver_acima(origem);
            devolver_acima(destino);
            mover_somente_x(origem, pos[destino]);
        } 
        else if (strcmp(comando, "move") == 0 && strcmp(modificador, "over") == 0){
            devolver_acima(origem);
            mover_somente_x(origem, pos[destino]);
        } 
        else if (strcmp(comando, "pile") == 0 && strcmp(modificador, "onto") == 0){
            devolver_acima(destino);
            empilhar_a_partir_de_x(origem, pos[destino]);
        } 
        else if (strcmp(comando, "pile") == 0 && strcmp(modificador, "over") == 0)
            empilhar_a_partir_de_x(origem, pos[destino]);
    }

    // print
    for (int i = 0; i < numero_blocos; i++) {
        printf("%d:", i);
        for (int k = 0; k < topo[i]; k++) {
            printf(" %d", pilha[i][k]);
        }
        printf("\n");
    }

    return 0;
}
