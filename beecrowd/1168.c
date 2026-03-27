#include <stdio.h>

int n, x;
char numero[100000];

int main()
{
    scanf("%d", &n);
    enum leds{dig_0 = 6, dig_1 = 2, dig_2 = 5, dig_3 = 5, dig_4 = 4, dig_5 = 5, dig_6 = 6, dig_7 = 3, dig_8 = 7, dig_9 = 6};
    for (int i = 0; i < n; i++)
    {
        scanf("%s", numero);
        int total_leds = 0;
        for (int j = 0; numero[j] != '\0'; j++) // vai parar quando achar o \0
        {
            char digito = numero[j];
            switch (digito)
            {
                case '0':
                    total_leds += dig_0;
                    break;
                case '1':
                    total_leds += dig_1;
                    break;
                case '2':
                    total_leds += dig_2;
                    break;
                case '3':
                    total_leds += dig_3;
                    break;
                case '4':
                    total_leds += dig_4;
                    break;
                case '5':
                    total_leds += dig_5;
                    break;
                case '6':
                    total_leds += dig_6;
                    break;
                case '7':
                    total_leds += dig_7;
                    break;
                case '8':
                    total_leds += dig_8;
                    break;
                case '9':
                    total_leds += dig_9;
                    break;
            }
        }
        printf("%d leds\n", total_leds);
    }
}