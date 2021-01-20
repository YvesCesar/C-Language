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

typedef struct{
  REGISTRO reg;
  int prox;
} ELEMENTO;

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
int buscaSentinelaOrdenada(LISTA* l, TIPOCHAVE ch) {
    int i = 0;
    l->A[l->nroElem].chave = ch; // sentinela
    while (l -> A[i].chave < ch) i++;
    if (i == l->nroElem || l -> A[i].chave != ch) return ERROR; // not find
    else return i;
}

// Binary Search
int buscaBinaria(LISTA* l, TIPOCHAVE ch) {
    int esq, dir, meio;
    esq = 0;
    dir = l->nroElem - 1;
    while (esq <= dir) {
        meio = ((esq + dir) / 2);
        if (l -> A[meio].chave == ch) return meio; // found
        else {
            if (l ->A[meio].chave < ch) esq = meio + 1;
            else dir = meio - 1;
        }
        return ERROR;
    }
}

// Delete element when chave == ch in an ordered list
bool excluirElemLista(LISTA* l, TIPOCHAVE ch) {
    int pos;
    pos = buscaSequencial(l, ch);
    if(pos ==  ERROR) return FALSE; // No exists
    for(int j = pos; j < l -> nroElem - 1; j++) l -> A[j] = l -> A[j + 1];
    l -> nroElem--;
    return TRUE;
}

// Delete element when chave == ch in an ordered list
bool excluirElemListaOrd(LISTA* l, TIPOCHAVE ch) {
    int pos, j;
    pos = buscaBinaria(l, ch);
    if (pos == ERROR) return FALSE; // No exists
    for(j = pos; j < l->nroElem - 1; j++) l->A[j] = l->A[j+1];
    l->nroElem--;
    return TRUE;
}

// Ordered list insertion using binary search allowing duplication
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
    if (l->nroElem >= MAX) return FALSE; // full list
    int pos = l->nroElem;
    while (pos > 0 && l->A[pos - 1].chave > reg.chave) {
        l->A[pos] = l->A[pos - 1];
        pos--;
    }
    l->A[pos] = reg;
    l->nroElem++;
    return TRUE;
}

// Ordered list insertion using binary search without duplication
bool inserirElemListaOrdSemDup(LISTA* l, REGISTRO reg) {
    if(l->nroElem >= MAX) return FALSE; // full list
    int pos;
    pos = buscaBinaria(l,reg.chave);
    if(pos != ERROR) return FALSE; // element already exists
    pos = l->nroElem-1;
    while(pos>0 && l->A[pos].chave > reg.chave) {
        l->A[pos+1] = l->A[pos];
        pos--;
    }
    l->A[pos+1] = reg;
    l->nroElem++;
    return TRUE;
}
int main() {
    LISTA lista;
    inicializarLista(&lista);
    exibirLista(&lista);
    printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
    printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
    REGISTRO reg;
    reg.chave = 9;
    inserirElemListaOrd(&lista,reg);
    exibirLista(&lista);
    reg.chave=3;
    inserirElemListaOrd(&lista,reg);
    reg.chave=4;
    inserirElemListaOrd(&lista,reg);
    reg.chave=1;
    inserirElemListaOrd(&lista,reg);
    reg.chave=12;
    inserirElemListaOrd(&lista,reg);
    exibirLista(&lista);
    printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
    printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
    printf("Chave 4 encontrada na posicao: %i do arranjo A.\n",buscaSequencial(&lista,4));
    printf("Chave 4 encontrada na posicao: %i do arranjo A.\n",buscaBinaria(&lista,4));
    printf("Chave 4 encontrada na posicao: %i do arranjo A.\n",buscaSentinela(&lista,4));
    if (excluirElemLista(&lista,4)) printf("Exclusao bem sucedida: 4.\n");
    if (excluirElemLista(&lista,8)) printf("Exclusao bem sucedida: 8.\n");
    if (excluirElemLista(&lista,9)) printf("Exclusao bem sucedida: 9.\n");
    exibirLista(&lista);
    printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
    printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
    reinicializarLista(&lista);
    exibirLista(&lista);
    printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
    printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
return 0;
}
