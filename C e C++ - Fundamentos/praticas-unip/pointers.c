#include <stdlib.h>
#include <stdio.h>
#define TAM 5

void adconst(int * ptr, int num, int con) {
    for (int k = 0; k < num; k++) *(ptr) = *(ptr++) + con;
}

int main() {
    int matriz[TAM] = {3, 5, 7, 9, 11};
    int c = 10;

    adconst(matriz, TAM, c);

    for(int j = 0; j < TAM; j++) printf(" %d", *(matriz+j));

//system("pause");
return 0;
}
