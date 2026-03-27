#include <stdio.h>
int main()
{
    // N = indica a pressao desejada pelo motorista (1 ≤ N ≤ 40)
    // M =  indica a pressão lida pela bomba (1 ≤ M ≤ 40)
    int N, M, x;
    scanf("%d %d", &N, &M);
    
    //  diferença entre a pressão desejada e a pressão lida
    x = N - M;
    printf("%d\n", x);
    return 0;
}