#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define alturaMaxima 225

int main() {
    typedef struct
    {
        int peso;
        int altura;
    } PesoAltura;
    
    PesoAltura* pessoa1 = (PesoAltura*) malloc(sizeof(PesoAltura));

    // -> para acessar o campo da memória onde está apontando.
    pessoa1 -> peso = 80;
    pessoa1 -> altura = 185;

    printf("Peso: %i, Altura: %i. ", pessoa1 -> peso, pessoa1 -> altura);

    if (pessoa1 -> altura > alturaMaxima) printf("Altura acima da maxima.\n");
    else printf("Altura abaixo da maxima.\n");

//system("pause");
return 0;
}