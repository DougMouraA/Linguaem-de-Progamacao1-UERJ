/*
    2) Escreva um programa em C que verifique se um determinado inteiro positivo que é lido via teclado, é ou
    não primo. 
*/

#include <stdio.h>

int nprimo(int n)
{
    if (n < 2)
        return (1);
    else if (n == 2)
        return (0);
    else 
    {
        int i = 2;
        while (i <= (n / 2))
        {
            if (n % i == 0)
            {
                return (1);
                break;
            }
            i++;
        }
    }
    return (0);
}

int main (void)
{
    int n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);
    if (nprimo(n) == 1)
        printf("Nao e primo\n");
    else
        printf("E primo!\n");
    return (0);
}