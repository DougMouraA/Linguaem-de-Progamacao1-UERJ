/*
14) Faça um programa em C que simule um cronômetro com horas, minutos e segundos. A simulação
deverá mostrar no vídeo o cronômetro no seguinte formato HH: MM: SS. Inicialmente o cronômetro serázerado ( 00: 00: 00 ), sendo que os segundos começarão a ser incrementados, depois os minutos e
depois as horas. Lembre-se que a cada 60 segundos os minutos deverão ser incrementados, depois os
minutos voltarão a zero. Quando as horas estiverem prestes a chegar em 24, o cronômetro deverá
voltar a zero ( 00: 00: 00 ).
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int hora = 0;
    while(hora < 24)
    {
        for (int min = 0; min < 60; min++)
        {
            for (int seg = 0; seg < 60; seg++)
            {
                printf("%02d: %02d: %02d \n", hora, min, seg);
            }
        }
        hora++;

        if (hora > 23)
        {
            printf("00: 00: 00 \n");
            break;
        }
    }
    return (0);
}