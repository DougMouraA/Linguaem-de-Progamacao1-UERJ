/*
7) Escreva um programa em C onde, se possa representar os nomes e as notas de alunos de um curso da
universidade. O programa deverá imprimir os nomes dos cinco alunos que obtiverem as maiores notas
acima da média da turma. Considerar que a turma tenha 50 alunos. Usar a estrutura multivalorada vista em
sala de aula.
 */

#include <stdio.h>
#include <string.h>

typedef struct turma
{
    char nome[50];
    float nota;
}               t_turma;

float media_notas(t_turma avaliacao[10])
{
    float media = 0;
    float soma = 0;
    for (int i = 0; i < 10; i++)
        soma += avaliacao[i].nota;
    media = soma / 10;
    return (media);
}

void melhores_alunos(float media, t_turma avaliacao[10])
{
    t_turma maiores_notas[5];

    for (int i = 0; i < 10; i++)
    {
        if (avaliacao[i].nota > media)
        {
            for (int j = 0; j < 5; j++)
            {
                if (avaliacao[i].nota > maiores_notas[j].nota)
                {
                    strcpy(maiores_notas[j].nome, avaliacao[i].nome);
                    maiores_notas[j].nota = avaliacao[i].nota;
                    break;              
                }
            }
        }
    }
    for (int k = 0; k < 5; k++)
        printf("%s\n", maiores_notas[k].nome);
}

int main (void)
{
    t_turma avalicao[10];
    float media = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Nome do aluno %d: ", i + 1);
        scanf(" %49[^\n]", avalicao[i].nome);
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &avalicao[i].nota);
    }
    media = media_notas(avalicao);
    melhores_alunos(media, avalicao);
    return (0);
}