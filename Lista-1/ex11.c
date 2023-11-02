/*
11) Escrever um programa em C que leia uma cadeia de caracteres e imprima todas as palavras que
contenham três ou mais vogais.
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
    printf("Insira uma cadeia de caracteres: ");
    scanf(" %80[^\n]", cadeia);
    int tam = contPalavra(cadeia);
    char **palavra = arrayPalavras(cadeia);

    for (int i = 0; i < tam; i++)
    {
        int contVogais = 0;
        int tamPalavra = strlen(palavra[i]);
        for (int j = 0; j < tamPalavra; j++)
        {
            if (palavra[i][j] == 'a' || palavra[i][j] == 'e' || \
            palavra[i][j] == 'i' || palavra[i][j] == 'o' || \
            palavra[i][j] == 'u'){
                contVogais++;
            }
            if (palavra[i][j] == 'A' || palavra[i][j] == 'E' || \
            palavra[i][j] == 'I' || palavra[i][j] == 'O' || \
            palavra[i][j] == 'U'){
                contVogais++;
            }
        }
        if (contVogais >= 3)
            printf("%s\n", palavra[i]);
    }
    for (int i = 0; i < tam; i++)
    {
        free(palavra[i]);
    }
    free(palavra);
    return (0);
}