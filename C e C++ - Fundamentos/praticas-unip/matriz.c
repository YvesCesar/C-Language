#include <stdlib.h>
#include <stdio.h>

int main() {

    float a[2][3] = {1.0, 2.0, 3.5, 4.7, 5.2, 6.0},
    b[2][3] = {7.1, 8.8, 9.0, 10.0, 11.1, 12.0};
    float results[2][3];

    //Efetuando a operação de soma entre as duas matrizes:
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            results[i][j] = a[i][j] + b[i][j];
    }}

    //Exibindo a matriz resultante:
    printf("Resultado da soma entre as matrizes A e B:\n");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %5.1f ", results[i][j]);
        }
        printf("\n");
    }

//system("pause");
return 0;
}