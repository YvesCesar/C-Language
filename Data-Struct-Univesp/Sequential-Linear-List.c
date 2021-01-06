#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define ERROR -1
#define TRUE 1
#define FALSE 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    //Others fields
} REGISTRO;

typedef struct {
    REGISTRO A[MAX + 1];
    int nroElem;
} LISTA;

// Initializing list
void inicializarLista(LISTA* l) {
    l -> nroElem = 0;
}

// Printing list:
void exibirLista(LISTA* l) {
    printf("Lista: \" ");
    for (int i = 0; i < l -> nroElem; i++) {
        printf("%i ", l -> A[i].chave);
    }
    printf("\"\n");
}

// Return vector size:
int tamanho(LISTA* l) {
    return l -> nroElem;
}

// Return LISTA size in bytes:
int tamanhoEmBytes(LISTA* l) {
    return sizeof(LISTA);
}

// First element of LISTA
TIPOCHAVE primeiroElem(LISTA* l) {
    if (l -> nroElem > 0) return l -> A[0].chave;
    else return ERROR;
}

// Last element of LISTA
TIPOCHAVE ultimoElem(LISTA* l) {
    if (l -> nroElem > 0) return l -> A[l -> nroElem - 1].chave;
    else return ERROR;
}

// return N element of LISTA(Indexes: 0 to MAX - 1)
TIPOCHAVE anesimoElem(LISTA* l, int n) {
    if ( (n >= 0) && (n < l -> nroElem)) return l -> A[n].chave;
    else return ERROR;
}

// Reinitializing LISTA
void reinicializarLista(LISTA* l) {
    l -> nroElem = 0;
}

// Direct insertion (Position A[i])
bool inserirElemLista(LISTA* l, REGISTRO reg, int i) {
    if((l -> nroElem >= MAX) || (i < 0) || (i > l -> nroElem))
        return FALSE; //full list or invalid index

    for (int j = l -> nroElem; j > i; j--) l -> A[j] = l -> A[j - 1];
    l -> A[i] = reg;
    l -> nroElem++;
    return TRUE;
}

// Sequential search in ordered list or not:
int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
    int i = 0;
    while (i < l -> nroElem)
    {
        if(ch == l -> A[i].chave) return i;
        else i++;
    }
    return ERROR;
}

// Sequential search with array length MAX+1(Sentinela)
int buscaSentinela(LISTA* l, TIPOCHAVE ch) {
    int i = 0;
    l->A[l->nroElem].chave = ch; // sentinela
    while (l -> A[i].chave != ch) i++;
    if (i > l->nroElem -1) return ERROR; // not find
    else return i;
}

// Sequential search with order array length MAX+1(Sentinela)
int buscaSentinela(LISTA* l, TIPOCHAVE ch) {
    int i = 0;
    l->A[l->nroElem].chave = ch; // sentinela
    while (l -> A[i].chave < ch) i++;
    if (i == l->nroElem || l -> A[i].chave != ch) return ERROR; // not find
    else return i;
}

// Delete element when chave == ch
bool excluirEmLista(LISTA* l, TIPOCHAVE ch) {
    int pos;
    pos = buscaSequencial(l, ch);
    if(pos ==  ERROR) return FALSE; //No exists
    for(int j = pos; j < l -> nroElem - 1; j++) l -> A[j] = l -> A[j + 1];
    l -> nroElem--;
    return TRUE;
}

int main() {


return 0;
}
