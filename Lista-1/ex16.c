/*
16) Faça um programa em C que atenda às regras do seguinte jogo de dados. Dois jogadores estão
confrontando-se entre si, usando dois dados, numerados de 1 até 6 (dado RAND(5) + 1). Vence uma
rodada quem obtiver o maior número no lançamento. Entretanto, caso um jogador obtiver um
lançamento com dois dados iguais (por exemplo, 1 e 1, 2 e 2,....) e o outro jogador não, o jogador que
tiver lançado a dupla ganha. Caso os dois jogadores fizerem o lançamento e o resultado for de duas
duplas para os dois jogadores, ganha o jogador com a dupla maior. A disputa é em 11 lançamentos.
Indique o jogador vencedor ou se houve empate.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    srand(time(0));
    int jogador1 = 0;
    int jogador2 = 0;
    for (int i = 0; i < 11; i++)
    {
        int jog1dado1 = (rand() % 6) + 1;
        int jog1dado2 = (rand() % 6) + 1;
        int jog2dado1 = (rand() % 6) + 1;
        int jog2dado2 = (rand() % 6) + 1;
        if (jog1dado1 == jog1dado2 && jog2dado1 == jog2dado2)
        {
            if (jog1dado1 > jog2dado1)
            {
                printf("O jogador 1 venceu a rodada! dados do vencedor: %d e %d\n", jog1dado1, jog1dado2);
                printf("Dados do perdedor: %d e %d\n", jog2dado1, jog2dado2);
                jogador1++;
            }
            else if (jog2dado1 > jog1dado1)
            {
                printf("O jogador 2 venceu a rodada! dados do vencedor: %d e %d\n", jog2dado1, jog2dado2);
                printf("Dados do perdedor: %d e %d\n", jog1dado1, jog1dado2);
                jogador2++;
            }
            else{
                printf("Empate!\n");
                printf("Dados dos jogador 1: %d e %d\n", jog1dado1, jog1dado2);
                printf("Dados dos jogador 2: %d e %d\n", jog2dado1, jog2dado2);
                jogador1 = jogador1 + 0;
                jogador1 = jogador1 + 0;
            }
        }
        else if (jog1dado1 == jog1dado2 || jog2dado1 == jog2dado2)
        {
            if (jog1dado1 == jog1dado2 && jog2dado1 != jog2dado2)
            {
                printf("O jogador 1 venceu a rodada! dados do vencedor: %d e %d\n", jog1dado1, jog1dado2);
                printf("Dados do perdedor: %d e %d\n", jog2dado1, jog2dado2);
                jogador1++;
            }
            else
            {
                printf("O jogador 2 venceu a rodada! dados do vencedor: %d e %d\n", jog2dado1, jog2dado2);
                printf("Dados do perdedor: %d e %d\n", jog1dado1, jog1dado2);
                jogador2++;
            }
        }
        else
        {
            int soma1 = jog1dado1 + jog1dado2;
            int soma2 = jog2dado1 + jog2dado2;
            if (soma1 > soma2)
            {
                printf("O jogador 1 venceu a rodada! dados do vencedor: %d e %d\n", jog1dado1, jog1dado2);
                printf("Dados do perdedor: %d e %d\n", jog2dado1, jog2dado2);
                jogador1++;
            }
            else if (soma2 > soma1)
            {
                printf("O jogador 2 venceu a rodada! dados do vencedor: %d e %d\n", jog2dado1, jog2dado2);
                printf("Dados do perdedor: %d e %d\n", jog1dado1, jog1dado2);
                jogador2++;
            }
            else
            {
                printf("Empate!\n");
                printf("Dados dos jogador 1: %d e %d\n", jog1dado1, jog1dado2);
                printf("Dados dos jogador 2: %d e %d\n", jog2dado1, jog2dado2);
                jogador1 = jogador1 + 0;
                jogador1 = jogador1 + 0;
            }
        }
    }
    
    if (jogador1 > jogador2)
            printf("O jogador 1 e o vencedor! Venceu %d rodadas\n", jogador1);
        else if (jogador2 > jogador1)
            printf("O jogador 2 e o vencedor! Venceu %d rodadas\n", jogador2);
        else
            printf("Os jogadores 1 e 2 empataram! Cada um venceu %d rodadas\n", jogador1);
    return (0);
}