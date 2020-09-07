#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 25;
    int* y = &x; // & coleta o endereço da memória da variável x.
    *y = 30; //Atribui-se, ao endereço que y está apontando, o valor de 30.

    printf("Valor atual de x: %i\n", x);

//system("pause");
return 0;
}