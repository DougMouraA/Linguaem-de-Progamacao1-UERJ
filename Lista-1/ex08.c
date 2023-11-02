/*
Para um vetor A de 50 números inteiros, escrever um programa em C que determine o maior e o segundo
maior elemento desse vetor. Assumir que todos os elementos são distintos.

*/


#include <stdio.h>

int main(void)
{
    int vet[5] = {10, 5, 3, 8 ,9};
    int maior = 0;
    int segundo_maior = 0;
    for (int i = 0; i < 5; i++)
    {
        if (vet[i] > maior)
        {
            segundo_maior = maior;
            maior = vet[i];
        }
        else if (vet[i] > segundo_maior && vet[i] != maior)
            segundo_maior = vet[i];
    }
    printf("O maior numero e %d e o segundo maior numero e %d.\n", maior, segundo_maior);
    return(0);

}