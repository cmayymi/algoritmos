// QUESTÃO 4 - CAROLINE MAYUMI GRELLMANN SAITO

#include <stdio.h>

int R, C; // R = linhas, C = colunas 
char fazenda[251][251];
static int visitado[251][251]; // comeca zerado
int total_ovelhas = 0;
int total_lobos = 0;
int ovelhas_pasto = 0;
int lobos_pasto = 0;

// ovelha = letra k
// lobo = letra v
// cerca = #
// vazio = .

void explorar(int i, int j) {

    // fora da fazenda
    if (i < 0 || i >= R || j < 0 || j >= C)
        return;

    // se for cerca, para
    if (fazenda[i][j] == '#')
        return;

    // se já foi visitado, para
    if (visitado[i][j] == 1)
        return;

    visitado[i][j] = 1;

    // conta os animais
    if (fazenda[i][j] == 'k')
        ovelhas_pasto++;

    if (fazenda[i][j] == 'v')
        lobos_pasto++;

    // anda para os lados
    explorar(i + 1, j); // baixo
    explorar(i - 1, j); // cima
    explorar(i, j + 1); // direita
    explorar(i, j - 1); // esquerda
}

int main(){
    scanf("%d %d", &R, &C);

    for (int i = 0; i < R; i++)
        scanf("%s", fazenda[i]);

    // percorre toda a fazenda
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            if (fazenda[i][j] != '#' && visitado[i][j] == 0) {
                ovelhas_pasto = 0;
                lobos_pasto = 0;
                explorar(i, j);
                if (ovelhas_pasto > lobos_pasto)
                    total_ovelhas += ovelhas_pasto;
                else
                    total_lobos += lobos_pasto;
            }
        }
    }
    printf("%d %d\n", total_ovelhas, total_lobos);
    return 0;
}