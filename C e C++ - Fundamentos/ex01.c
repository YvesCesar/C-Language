#include <stdio.h>
#include <stdlib.h>

int main() {
    //declara��o de variaveis
    float valortotal, taxa, v1, v2, v3;
    //Dados de entrada
    printf("Digite o valor do deposito: R$");
    scanf("%f", valortotal);
    printf("A taxa de juros por mes e de 6%%");
    taxa = 6/100;
    
    //processamento
    v1 = (valortotal * taxa) + valortotal;
    v2 = (v1 * taxa) + v1;
    v3 = (v2 * taxa) + v2;
    
    //dados de sa�da
    printf("O valor R$ %f", valortotal, " ap�s tr�s meses, fica no total de: R$ %f", v3);
	return 0;
}
