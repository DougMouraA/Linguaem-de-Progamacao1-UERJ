/* 
6) Um motorista acaba de retornar de um feriado prolongado. Em cada parada de reabastecimento ele
registrou a leitura de seu odômetro, a quantidade de gasolina comprada (suponha que ele tenha enchido o
tanque cada vez) e o preço pago. Além disso, suponha também que ele tenha enchido o tanque antes de
partir e imediatamente após retornar. Escreva um programa em C para ler, em primeiro lugar, o número total
de reabastecimentos feitos (incluindo o primeiro e o último) e, a seguir, os dados relativos à compra de
gasolina e calcular :
a) a quilometragem obtida por litro de gasolina entre cada par de paradas de reabastecimento;
b) a quilometragem obtida por litro de gasolina em toda a viagem
c) custo do combustível por quilometro rodado em toda a viagem

*/

#include <stdio.h>

typedef struct odometro
{
    float litros;
    float km;
    float valor;
}               t_odo;

void km_por_litro(t_odo parada[], int abastecimento)
{
    float diferencakm;
    float kmpl;

    for (int i = 0; i < abastecimento - 1; i ++)
    {
        diferencakm = parada[i + 1].km - parada[i].km;
        kmpl = diferencakm / parada[i + 1].litros;
        printf("Quilometragem por litro entre a parada %d e %d: %.2f km por litro.\n", i, i + 1, kmpl);
    }
}

void km_litro_total(t_odo parada[], int abastecimento)
{
    float litros_total;
    float total = 0;
    float km_total;

    for (int i = 1; i < abastecimento; i++)
        litros_total += parada[i].litros;
    km_total = parada[abastecimento - 1].km - parada[0].km;
    total = km_total / litros_total;
    printf("A quilometragem obtida por litro de gasolina em toda a viagem: %.2f km por litro.\n", total);
}

void custo_total(t_odo parada[], int abastecimento)
{
    float valor_total;
    float km_total = parada[abastecimento - 1].km - parada[0].km;

    for (int i = 1; i < abastecimento; i++)
        valor_total += parada[i].valor;
    float total = km_total / valor_total;
    printf("Custo do combustível por quilometro rodado em toda a viagem: R$ %.2f/km.\n", total);
}

int main(void)
{
    int abastecimento;

    printf("Digite quantas paradas foram feitas: ");
    scanf("%d", &abastecimento);
    t_odo paradas[abastecimento];
    for (int i = 0; i < abastecimento; i++)
    {
        printf("Quantos litros de gasolina foram abastecidos na parada %d? ", i + 1);
        scanf("%f", &paradas[i].litros);
        printf("Quantos quilometros rodados ? ");
        scanf("%f", &paradas[i].km);
        printf("Qual foi valor desse abastecimento na parada %d? ", i + 1);
        scanf("%f", &paradas[i].valor);
    }
    km_por_litro(paradas, abastecimento);
    km_litro_total(paradas, abastecimento);
    custo_total(paradas, abastecimento);
    return (0);
}
