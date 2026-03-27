#include <stdio.h>

int senha;

int main()
{
    while(scanf("%d", &senha))
    {
        if (senha != 2002)
            printf("Senha Invalida\n");
        else
        {
            printf("Acesso Permitido\n");
            break;
        }
    }   
}