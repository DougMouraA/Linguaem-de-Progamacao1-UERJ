/*
15) O Departamento de trânsito do estado anotou dados de acidentes de trânsito no último ano. Para cada
motorista envolvido no acidente, tem-se as seguintes informações:
- Ano de nascimento;
- Sexo (M - Masculino, F - Feminino)
- Procedência ( 0 - Capital, 1 - Interior, 2 - Outro estado);
Faça um programa em C que :
a) Calcule a porcentagem de motoristas com menos de 21 anos;
b) Calcule quantas mulheres são da capital;
c) Calcule quantos motoristas do interior do estado tem idade maior que 60 anos;
d) Verifique se existe alguma mulher com idade maior que 60 anos;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct motorista
{
    int ano;
    char sexo;
    int origem;
}              t_dados;


void porcentagemIdade(int acidentes, int anoAtual, t_dados motorista[])
{
    int cont = 0;
    for (int i = 0; i < acidentes; i++)
    {
        if ((anoAtual - motorista[i].ano) < 21)
            cont++;
    }

    float porcentagem = (cont / acidentes) * 100;
    printf("%.2f %% dos motoristas tem menos de 21 anos\n", porcentagem);
}

void mulheresCapital(int acidentes, t_dados motorista[])
{
    int cont = 0;
    for (int i = 0; i < acidentes; i++)
    {
        if (motorista[i].sexo == 'F' && motorista[i].origem == 0)
            cont++;
    }
    printf("%d mulheres sao da capital\n", cont);
}

void interiorIdosos(int acidentes, int anoAtual, t_dados motorista[])
{
    int cont = 0;
    for (int i = 0; i < acidentes; i++)
    {
        if ((anoAtual - motorista[i].ano) > 60 && motorista[i].origem == 1)
            cont++;
    }
    printf("%d motoristas tem idade maior que 60 anos e moram no interior\n", cont);
}

void mulherIdosa(int acidentes, int anoAtual, t_dados motorista[])
{
    int cont = 0;
    for (int i = 0; i < acidentes; i++)
    {
        if ((anoAtual - motorista[i].ano) > 60 && motorista[i].sexo == 'F')
            cont++;
    }
    printf("Existem %d mulheres maiores de 60 anos\n", cont); 
}

int main(void)
{
    int acidentes = 0;
    int anoAtual = 0;
    printf("Qual o ano que deseja buscar informacoes: ");
    scanf("%d", &anoAtual);
    printf("Quantos acidentes ocorreram em %d: ", anoAtual);
    scanf("%d", &acidentes);
    t_dados motorista[acidentes];

    for (int i = 0; i < acidentes; i++)
    {
        printf("Ano de nascimento do(a) motorista %d: \n", i + 1);
        scanf(" %d", &motorista[i].ano);
        printf("Sexo do(a) motorista %d? M - Masculino, F - Feminino: \n", i + 1);
        scanf(" %c", &motorista[i].sexo);
        printf("Qual a procedencia do(a) motorista %d? 0 - Capital, 1 - Interior, 2 - Outro estado: \n", i + 1);
        scanf(" %d", &motorista[i].origem);
    }

    porcentagemIdade(acidentes, anoAtual, motorista);
    mulheresCapital(acidentes, motorista);
    interiorIdosos(acidentes, anoAtual, motorista);
    mulherIdosa(acidentes, anoAtual, motorista);
    return(0);
}
