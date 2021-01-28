#include <stdio.h>
#define MAX 50
#define INVALIDO -1
#define true 1
#define false 0
typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
  TIPOCHAVE chave;
  // other fields...
} REGISTRO;

typedef struct{
  REGISTRO reg;
  int prox;
} ELEMENTO;

typedef struct {
  ELEMENTO A[MAX];
  int inicio;
  int dispo;
} LISTA;

/* Sequential list initialization (the list is already created and is indicated by the address in l) */
void inicializarLista(LISTA* l){
  int i;
  l->inicio=INVALIDO;
  l->dispo=0;
  for (i=0; i<MAX-1; i++)
    l->A[i].prox = i + 1;
  l->A[MAX-1].prox = INVALIDO;
} 

/* Sequential list display */
void exibirLista(LISTA* l){
  int i = l->inicio;
  printf("Lista: \" ");
  while (i != INVALIDO){
    printf("%d ", l->A[i].reg.chave); // TIPOCHAVE = int
    i = l->A[i].prox;
  }
  printf("\"\n");
} 

/* Return list size (number of "valid" elements) */
int tamanho(LISTA* l) {
  int i = l->inicio;
  int tam = 0;
  while (i != INVALIDO){
    tam++;
    i = l->A[i].prox;
  }
  return tam;
}

/* Return the size in bytes of the list. In this case, it does not depend on the number
   of elements that are being used, since the memory allocation is static.
   At first, we wouldn't need the pointer to the list, we'll just use it
   because we will have the same functions for lists linked to non-static implementation.
*/
int tamanhoEmBytes(LISTA* l) {
  return sizeof(LISTA);
}

/* Sequential search (ordered list or not) */
int buscaSeq(LISTA* l, TIPOCHAVE ch){
  int i = l->inicio;
  while (i != INVALIDO){
    if (l->A[i].reg.chave == ch) return i;
    i = l->A[i].prox;
  }
  return INVALIDO;
}

/* Sequential search - exclusion function (returns address * before the index of the
   element prior to the element being searched for [ant receives the element
   previous regardless of whether the element sought is found or not]) */
int buscaSeqExc(TIPOCHAVE ch, LISTA* l, int *ant){
  *ant = INVALIDO;
  int i = l->inicio;
  while ((i != INVALIDO) && (l->A[i].reg.chave<ch)){
    *ant = i;
    i = l->A[i].prox;
  }
  if ((i != INVALIDO) && (l->A[i].reg.chave == ch)) return i;
  return INVALIDO;
} 

/* Get available node and mark it as unavailable - this operation will be used
  along with inserts, for example */
int obterNo(LISTA* l){
  int resultado = l->dispo;
  if (l->dispo != INVALIDO) l->dispo = l->A[l->dispo].prox;
  return resultado;
} 

/* Return node from position j to the list of available nodes - place node j first in the list of available */
void devolverNo(LISTA* l, int j){
     l->A[j].prox = l->dispo;
     l->dispo = j;
} 

bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
  int ant = INVALIDO;
  int i = l->inicio;
  while ((i != INVALIDO) && (l->A[i].reg.chave<ch)){
    ant = i;
    i = l->A[i].prox;
  }
  if (i==INVALIDO || l->A[i].reg.chave!=ch) return false;
  if (ant == INVALIDO) l->inicio = l->A[i].prox;
  else l->A[ant].prox = l->A[i].prox;
  devolverNo(l,i);
  return true;
} 


/* Deleting the indicated key element */
bool excluirElemLista2(LISTA* l, TIPOCHAVE ch){
  int ant, i;
  i = buscaSeqExc(ch, l, &ant);
  if (i == INVALIDO) return false;
  if (ant == INVALIDO) l->inicio = l->A[i].prox;
  else l->A[ant].prox = l->A[i].prox;
  devolverNo(l,i);
  return true;
}


/* Destruction of the sequential list */
void reinicializarLista(LISTA* l) {
  inicializarLista(l);
}


/* Ordered list insertion without duplication */
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  if (l->dispo == INVALIDO) return false; // if full list, it is not possible to insert
   int ant, i;
  i = buscaSeqExc(reg.chave, l, &ant);
  if (i!=INVALIDO) return false;
  i = obterNo(l);
  l->A[i].reg = reg;
  if (ant == INVALIDO) { // the new element will be the 1st in the list (the list could be empty or not)
    l->A[i].prox = l->inicio;
    l->inicio = i;
  } else {  // insertion after an existing element
    l->A[i].prox = l->A[ant].prox;
    l->A[ant].prox = i;
  }  
  return true;
}


/* Ordered list insertion without duplication - do not use the auxiliary method */
bool inserirElemListaOrd2(LISTA* l, REGISTRO reg) {
  if (l->dispo == INVALIDO) return false; // if full list, it is not possible to insert
  int ant = INVALIDO;
  int i = l->inicio;
  while ((i != INVALIDO) && (l->A[i].reg.chave<reg.chave)){
    ant = i;
    i = l->A[i].prox;
  }
  if (i!=INVALIDO && l->A[i].reg.chave==reg.chave) return false;
  i = obterNo(l);
  l->A[i].reg = reg;
  if (ant == INVALIDO) { // the new element will be the 1st in the list (the list could be empty or not)
    l->A[i].prox = l->inicio;
    l->inicio = i;
  } else {  // insertion after an existing element
    l->A[i].prox = l->A[ant].prox;
    l->A[ant].prox = i;
  }  
  return true;
} 