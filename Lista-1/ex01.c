/* 
1) Escreva um programa em C que encontre o menor inteiro positivo n que atenda as seguintes condições :
n / 3 = x inteiro e resto 2
n / 5 = y inteiro e resto 3
n / 7 = z inteiro e resto 4 
*/

#include <stdio.h>

int main(void)
{
    int n = 1;

    while (n > 0)
    {
        if ((n % 3 == 2) && (n % 5 == 3) && (n % 7 == 4))
        {
            printf("%d\n", n);
            break;
        }
        n++;
    }
    
    return (0);
}