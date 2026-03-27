#include <stdio.h>
int main()
{
    int diainicial, diafinal, hi, mi, si, hf, mf, sf, tempoi, tempof, total, resto, dt, ht, st, mt;
    scanf("Dia %d", &diainicial);
    scanf("%d : %d : %d", &hi, &mi, &si);
    scanf("Dia %d", &diafinal);
    scanf("%d : %d : %d", &hf, &mf, &sf);

    // calculo de quantos dias vao ser, quantas horas, min, s
    tempoi = (diainicial*24*3600) + (hi*3600) + (mi*60) + si;
    tempof = (diafinal*24*3600) + (hf*3600) + (mf*60) + sf;
    total = tempof - tempoi;

    dt = total/(24*3600);
    resto = total%(24*3600);
    ht = resto/3600;
    resto = resto%3600;
    mt = resto/60;
    st = resto%60;
    
    printf("%d dia(s)\n", dt);
    printf("%d hora(s)\n", ht);
    printf("%d minuto(s)\n", mt);
    printf("%d segundo(s)\n", st);
    return 0;
}