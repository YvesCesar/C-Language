#include <stdlib.h>
#include <stdio.h>

int main() {
    int A[5], maior = 0;

    for (int i =0; i < 5; i++) {
        printf("Digite o %iº valor: ", i+1);
        scanf("%i", &A[i]);

        if(A[i] > maior) {
            maior = A[i];
        }
    }

    printf("O maior valor digitado foi: %d\n", maior);
    printf("O endereco do ultimo valor eh %d \n", (A + 4));
    printf("O endereco do ultimo valor eh %d \n", &A[4]);
    printf("O valor do endereco eh %d \n", *(A+4));
    //system("pause");
    return 0;
}
