/*
10)Escrever um programa em C que calcule a frequência de uso de cada palavra dentro de uma cadeia de
caracteres que possui diversas palavras. Considerar o tamanho máximo da cadeia como sendo de 80
colunas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contPalavra(char *str)
{
    int cont = 0;
    int tam = strlen(str);
    for (int i = 0; i < tam; i++)
    {
        if (str[i] != ' ')
        {
            int j = i;
            while (str[j] != ' ' && str[j] != '\0')
                j++;
            cont++;
            i = j - 1;
        }
    }
    return (cont);
}

char **arrayPalavras(char *str)
{
    int i = 0;
    int tam = contPalavra(str);
    char **novaStr = (char **) malloc(tam * sizeof(char *));
    char *palavra = strtok(str, " ");
    while (i < tam && palavra != NULL)
    {
        novaStr[i] = strdup(palavra);
        palavra = strtok(NULL, " ");
        i++;
    }
    return (novaStr);
}

int main(void)
{
    char cadeia[80];
    char **palavra;
    int tam;

    printf("Insira uma cadeia de caracteres: ");
    scanf(" %80[^\n]", cadeia);
    tam = contPalavra(cadeia);
    palavra = arrayPalavras(cadeia);
    for (int i = 0; i < tam; i++)
    {
        int cont = 0;
        for (int j = 0; j < i; j++)
        {
            if (strcmp(palavra[i], palavra[j]) == 0)
                cont++;
        }
        if (cont == 0)
        {
            int numPalavra = 0;
            for (int k = 0; k < tam; k++)
            {
                if (strcmp(palavra[i], palavra[k]) == 0)
                    numPalavra++;
            }
            printf("A palavra %s aparece %d vezes.\n", palavra[i], numPalavra);
        }
    }

    for (int i = 0; i < tam; i++)
    {
        free(palavra[i]);
    }
    free(palavra);
    return (0);
}