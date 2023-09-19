/*
    4) Escreva um programa em C que calcule o fatorial de um número inteiro positivo.
 */

#include <stdio.h>

int main (void)
{
    int n;
    int total = 1;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    if (n == 0 || n == 1)
        printf("%d! e: 1\n", n);
    else 
    {
        for (int i = 1;i <= n; i++)
        {
            total = total * i;
        }
        printf("%d! e: %d\n", n, total);
    }
    return (0);
}