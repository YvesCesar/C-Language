#ifndef LISTAESTATICA_H_INCLUDED
#define LISTAESTATICA_H_INCLUDED
#include "Item.h"

#define TAM 5

typedef struct lista_estatica LISTA_ESTATICA;

LISTA_ESTATICA * criar_lista();

void apagar_lista(LISTA_ESTATICA * lista) ;

int inserir_fim(LISTA_ESTATICA * lista, ITEM * item)  ;

int inserir_posicao(LISTA_ESTATICA * lista , int pos , ITEM * item) ;

int vazia(LISTA_ESTATICA * lista) ;

int cheia(LISTA_ESTATICA * lista) ;

int tamanho(LISTA_ESTATICA * lista) ;

void imprimir(LISTA_ESTATICA * lista) ;

#endif // LISTAESTATICA_H_INCLUDED
