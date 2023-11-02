/*
9) Escrever um programa em C que calcule e imprima o número de caracteres distintos presentes em uma
cadeia de caracteres dada. Considerar o tamanho máximo da cadeia como sendo de 80 colunas. 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str[80];
    int cont = 0;

    printf("Insira uma cadeia de caracteres: ");
    scanf(" %80[^\n]", str);
    int tam = strlen(str);
    for (int i = 0; i < tam; i++)
    {
        str[i] = tolower(str[i]);
        int repetidos = 0;
        for (int j = 0; j < tam; j++)
        {
            if (str[i] == str[j])
                repetidos++;
        }
        if (repetidos == 1)
            cont++;
    }
    printf("O numero de caracteres distintos: %d\n", cont);
    return(0);
}