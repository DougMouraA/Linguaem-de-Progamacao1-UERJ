/*
Escrever um programa em C que leia um valor inteiro (limite na casa do milhar), e o imprima em forma
de caracteres, ou seja, por extenso. Ex. : 98 = noventa e oito.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tamNUm(int n)
{
    int num = n;
    int casa = 0;
    while (num >= 10)
    {
        num = num / 10;
        casa++;
    }
    return (casa);   
}


int main(void)
{
    int num;
    printf("Insira um numero: ");
    scanf("%d", &num);
    int casa = tamNUm(num);

    char *uni[10] = {"um", "dois", "tres", "quatro", "cinco", "seis", \
    "sete", "oito", "nove"};
    
    char *dez[10] = {"dez", "onze", "doze", "treze", "quatorze", "quize", \
    "dezesseis", "dezessete", "dezoito", "dezenove"};
    char *dez2[10] = {"vinte", "trinta", "quarenta", "cinquenta", "sessenta", \
    "setenta", "oitenta", "noventa"};
    char *cem[10] = {"cento", "dozentos", "trezentos", "quatrocentos", \
    "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"}; 

    if (casa == 0)
    {
        if (num == 0)
            printf("zero\n");
        else
            printf("%s\n", uni[num - 1]);
    }
    else if (casa == 1)
    {
        int dezena = num / 10;
        int unidade = num % 10;
        if (unidade == 0){
            printf("%s\n", dez2[dezena - 2]);
        }
        else if (dezena > 1){
            printf("%s e %s\n", dez2[dezena - 2], uni[unidade - 1]);
        }
        else {
            printf("%s\n", dez[unidade]);
        }
    }
    else if (casa == 2)
    {
        int centena = (num / 100);
        int dezena = (num % 100) / 10;
        int unidade = num % 10;

        if(dezena == 0 && unidade == 0) {
            if (num == 100)
                printf("cem\n");
            else
                printf("%s\n", cem[centena - 1]);
        }
        else if (dezena == 0)
            printf("%s e %s\n", cem[centena - 1], uni[unidade - 1]);
        else if (unidade == 0){
            if (dezena > 1)
                printf("%s e %s\n", cem[centena - 1], dez2[dezena - 2]);
            else
                printf("%s e %s\n", cem[centena - 1], dez[dezena - 1]);
        }
        else if (dezena > 1)
            printf("%s e %s e %s\n", cem[centena  - 1], dez2[dezena - 2], uni[unidade - 1]);
        else
            printf("%s e %s\n", cem[centena - 1], dez[unidade]);
    }
    return(0);
}