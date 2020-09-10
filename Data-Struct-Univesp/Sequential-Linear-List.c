#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    //Others camps
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int nroElem;
} LISTA;

//Initializing list
void inicializarLista(LISTA* l) {
    l -> nroElem = 0;
}

//Return veector size:
int tamanho(LISTA* l) {
    return l -> nroElem;
}

//Printing list:
void exibirLista(LISTA* l) {
    printf("Lista: \" ");
    for (int i = 0; i < l -> nroElem; i++) {
        printf("%i ", l -> A[i].chave);
    }
    printf("\"\n");
}

int main() {
    LISTA* l;
    
    inicializarLista(l);
return 0;
}