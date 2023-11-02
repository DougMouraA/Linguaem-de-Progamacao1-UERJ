/*
13) Dados três vetores com 10 posições cada um, preenchidos com números inteiros, fazer um programa
em C que, após a leitura dos vetores coloque-os em ordem crescente.
*/

#include <stdio.h>
#include <stdlib.h>

int *preencherVetor(int *vet)
{
    int n = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("Valor na posição %d:", i);
        scanf("%d", &n);
        vet[i] = n;
    }
    return (vet);
}

void sortVet(int *vet)
{
    int i = 0;
    while (i < 10)
    {
        int aux = 0;
        if (vet[i] > vet[i + 1])
        {
            aux = vet[i];
            vet[i] = vet[i + 1];
            vet[i + 1] = aux;
            i = 0;
        }
        else
            i++;
    }

    for (int j = 0; j < 10; j++)
    {
        printf("%d ", vet[j]);
    }
    printf("\n");
}

int main(void)
{
    int vet1[10];
    int vet2[10]; 
    int vet3[10];

    printf("Preencha o vetor 1\n");
    preencherVetor(vet1);
    printf("Preencha o vetor 2\n");
    preencherVetor(vet2);
    printf("Preencha o vetor 3\n");
    preencherVetor(vet3);

    printf("Vetor 1 ordenado:\n");
    sortVet(vet1);
    printf("Vetor 2 ordenado:\n");
    sortVet(vet2);
    printf("Vetor 3 ordenado:\n");
    sortVet(vet3);
    return (0);
}