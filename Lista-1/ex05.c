/*
    O troco em moedas é uma combinação de moedas com os seguintes valores :
    R$ 1,00 ; 0,50; 0,25; 0,10; 0,05; 0,01
    Escreva um programa em C que leia qualquer valor em centavos (R$0,01 até R$1,00). Calcule e imprima
    seu equivalente em moedas. Encontre a solução que utilize o menor número possível de moedas.
 */

#include <stdio.h>

int main(void)
{
    float coin;

    printf("Digite um valor em reais: ");
    scanf("%f", &coin);

    int moeda = coin * 100;
    int m1 = 0;
    int m50 = 0;
    int m25 = 0;
    int m10 = 0;
    int m05 = 0;
    int m01 = 0;

    if (moeda >= 100)
    {
        m1 = moeda / 100;
        moeda = moeda % 100;
    }
    if (moeda >= 50)
    {
        m50 = moeda / 50;
        moeda = moeda % 50;
    }
    if (moeda >= 25)
    {
        m25 = moeda / 25;
        moeda = moeda % 25;
    }
    if (moeda >= 10)
    {
        m10 = moeda / 10;
        moeda = moeda % 10;
    }
    if (moeda >= 5)
    {
        m05 = moeda / 5;
        moeda = moeda % 5;
    }
    if (moeda >= 1)
    {
        m01 = moeda / 1;
    }

    printf("O troco de %.2f: %d R$1, %d R$0,50, %d R$0,25, %d R$0,10, %d R$0,05, %d R$0,01\n", coin, m1, m50, m25, m10, m05, m01);
}