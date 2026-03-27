#include <stdio.h>
#include <math.h>

long double h, dx; // altura, distancia na horizontal (eixo x)
int p1, p2; // onde a cidade comeca e termina
int n; // numero de testes que vao atacar a cidade
long double angulo, v; // angulo e velocidade

const long double radianos = 3.14159/180.0;
const long double gravidade = 9.80665;
const long double EPS = 10E-6;

int main()
{
    while(scanf("%Lf", &h) != EOF)
    {
        scanf("%d %d", &p1, &p2);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) // processar as tentativas
        {
            scanf("%Lf %Lf", &angulo, &v);

            // converter angulo para radianos
            angulo *= radianos;

            // calcular o deslocamento no eixo x
            dx = v*cos(angulo) * (v*sin(angulo) + sqrt(v*v*sin(angulo)*sin(angulo) + 2*gravidade*h))/gravidade;

            if (dx + EPS >= p1 && dx <= p2 + EPS)
                printf("%.5Lf -> DUCK\n", dx);
            else
                printf("%.5Lf -> NUCK\n", dx);
        }
    }
}