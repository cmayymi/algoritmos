#include <stdio.h>
#include <math.h>

int n;
unsigned x;
unsigned long long kg, gramas;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%u", &x);

        unsigned long long total_graos = 0;
        unsigned long long graos_casa = 1; // 1 grao na casa 1

        // progressao geometrica de razao 2
        for (unsigned casa = 1; casa <= x; casa++)
        {
            total_graos += graos_casa;
            graos_casa *= 2; // dobra a cada casa
        }
        gramas = total_graos/12;
        kg = gramas/1000;
        printf("%llu kg\n", kg);
    }
}