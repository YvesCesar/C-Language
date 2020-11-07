#include <stdio.h>
#include <stdlib.h>
#include "listaestatica.h"
#define TAM2 10

typedef struct lista_estatica {
    ITEM *itens[TAM];
    int fim;
} LISTA_ESTATICA;

LISTA_ESTATICA * criar_lista() {
    LISTA_ESTATICA * lista = (LISTA_ESTATICA *) malloc (sizeof(LISTA_ESTATICA));
    lista -> fim =- 1 ;
return lista ;
}
void apagar_lista(LISTA_ESTATICA * lista) {}
int vazia(LISTA_ESTATICA * lista) {}
int cheia(LISTA_ESTATICA * lista) {}
int tamanho(LISTA_ESTATICA * lista) {}
void imprimir(LISTA_ESTATICA * lista) {}
int inserir_fim(LISTA_ESTATICA * lista , ITEM *item ) {}

int inserir_posicao(LISTA_ESTATICA * lista , int pos , ITEM *item ) {
    lista->itens[pos] = item;
}

ITEM* criar_item(int chave, int valor) {
    ITEM* item = (ITEM*) malloc(sizeof(ITEM));
    item -> chave = chave;
    item -> valor = valor;
return item;
}

void apagar_item(ITEM *item) {
    item->valor=0;
}
void imprimir_item(ITEM *item) {
    printf("%d", item->valor);
}

// Resolução de Exercícios:

// Verificar se a lista L está ordenada (crescente ou decrescente)
int isOrdered(LISTA_ESTATICA* lista) {
    int ascendingOrder[TAM];
    int descendingOrder[TAM];

    for(int i = 0; i < TAM; i++) {
        ascendingOrder[i] = lista -> itens[i] -> valor;
        descendingOrder[i] = lista -> itens[i] -> valor;
    }

    // Algoritmo Bubblesort:
    for (int i = 1; i < TAM; i++) {
        for (int j = 0; j < TAM - 1; j++) {
            if(ascendingOrder[j] > ascendingOrder[j + 1]) {
                int aux = ascendingOrder[j];
                ascendingOrder[j] = ascendingOrder[j + 1];
                ascendingOrder[j + 1] = aux;
            }
        }
    }

    for (int i = 1; i < TAM; i++) {
        for (int j = 0; j < TAM - 1; j++) {
            if(descendingOrder[j] < descendingOrder[j + 1]) {
                int aux = descendingOrder[j];
                descendingOrder[j] = descendingOrder[j + 1];
                descendingOrder[j + 1] = aux;
            }
        }
    }

    // Analisando equivalências:
    int ascERROR = 0;
    int descERROR = 0;
    for(int i = 0; i < TAM; i++) {
        if (ascendingOrder[i] != lista->itens[i]->valor) ascERROR++;
        if (descendingOrder[i] != lista->itens[i]->valor) descERROR++;
    }

    if (ascERROR > 0 && descERROR > 0) return 0;

return 1;
}

// Fazer uma cópia da Lista L1 em outra L2
LISTA_ESTATICA* copyList(LISTA_ESTATICA* source) {
    LISTA_ESTATICA* destiny = criar_lista();
    for (int i = 0; i < TAM; i++) {
        destiny->itens[i] = source -> itens[i];
    }
return destiny;
}

// Fazer uma cópia da Lista L1 em L2, eliminando repetidos

int searchItem(LISTA_ESTATICA* list, ITEM* item) {
    int i = 0, j = 0;
    while (i < TAM)
    {
        if(item->valor == list -> itens[i]-> valor) j++;

        i++;
    }
    return j;
}
LISTA_ESTATICA* copyListWithoutRepeat(LISTA_ESTATICA* source) {
    LISTA_ESTATICA* destiny = criar_lista();
    ITEM* item;

    for (int i = 0; i < TAM; i++) {
        //destiny -> itens[i] = source -> itens[i];
        int key = i;
        int value = source -> itens[i] -> valor;
        item = criar_item(key, value);
        int EQUALS = searchItem(source, item);
        if (EQUALS > 1) {
            deleteItemFromList(source, item);
        }
    }

    for (int i = 0; i < TAM; i++) {
        destiny -> itens[i] = source -> itens[i];
    }

return destiny;
}

// Inverter L1, colocando o resultado em L2
LISTA_ESTATICA* copyInverseList(LISTA_ESTATICA* source) {
    LISTA_ESTATICA* destiny = criar_lista();
    for (int i = 0; i < TAM; i++) {
        destiny->itens[i] = source -> itens[TAM - i - 1];
    }
return destiny;
}

// Inverter a própria L1
LISTA_ESTATICA* inverseList(LISTA_ESTATICA* L1) {
    L1 = copyInverseList(L1);
return L1;
}

// Intercalar L1 com L2, gerando L3 ordenada (considere L1 e L2 ordenadas)
typedef struct l4 {
    ITEM *itens[TAM+TAM];
    int fim;
} L4;

L4* newListL4(LISTA_ESTATICA* L1, LISTA_ESTATICA* L2) {

    L4* l4 = (L4*) malloc (sizeof(L4));
    l4 -> fim =- 1 ;

    int i = 0, j = 0;
    while (i < 5) {
        l4 ->itens[i] = L1 ->itens[i];
        i++;
    }
    while (i < 10) {
        l4 ->itens[i] = L2 ->itens[j];
        j++;
        i++;
    }
return l4;
}

// Eliminar de L1 todas as ocorrências de um dado item (L1 está ordenada)
void deleteItemFromList(LISTA_ESTATICA* list, ITEM* item) {
    for(int i = item->chave; i < TAM - 1; i++) list -> itens[i] = list -> itens[i + 1];
}

int main()
{
    printf("Hello world!\n");

    LISTA_ESTATICA* lista;
    lista = criar_lista();


    int key=0, value = 0;

    for(int i = 0; i < TAM; i++) {
        printf("%dº Registro:\n", i+1);
        printf("Insira a chave: ");
        scanf("%d", &key);
        printf("Insira o valor: ");
        scanf("%d", &value);

        ITEM* item = criar_item(key, value);
        inserir_posicao(lista , i , item);
    }
    int n = isOrdered(lista);
    printf("\n");
    printf("Is Ordered? %d", n);

    printf("\n");
    LISTA_ESTATICA* L2 = copyList(lista);
    printf("L2:\n");
    for(int i = 0; i < TAM; i++) {
        printf(" %d ", L2->itens[i]->valor);
    }

    LISTA_ESTATICA* L3 = copyInverseList(L2);

    printf("\n");
    printf("L3: \n");

    for(int i = 0; i < TAM; i++) {
        printf(" %d ", L3->itens[i]->valor);
    }

    printf("\n");
    printf("L3 inverse: \n");

    L3 = inverseList(L3);
    for(int i = 0; i < TAM; i++) {
        printf(" %d ", L3->itens[i]->valor);
    }

    L4* l4 = newListL4(L2, L3);

    printf("\n");
    printf("L4: \n");
    for(int i = 0; i < TAM+TAM; i++) {
        printf(" %d ", l4->itens[i]->valor);
    }
    return 0;
}
