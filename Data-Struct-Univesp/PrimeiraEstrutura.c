#include <stdio.h>
#include <stdlib.h>
#define alturaMaxima 225

int main() {
    typedef struct {
        int peso;
        int altura;
    } PesoAltura;

    PesoAltura pessoa1;
    pessoa1.peso = 80;
    pessoa1.altura = 185;

    printf("Peso: %i, Altura %i. ", pessoa1.peso, pessoa1.altura);

    if(pessoa1.altura > alturaMaxima) printf("Altura acimada maxima.\n");
    else printf("Altura abaixo da maxima");
//system("pause");
return 0;
}
