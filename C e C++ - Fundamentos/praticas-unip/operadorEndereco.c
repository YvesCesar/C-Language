#include <stdio.h>
#include <stdlib.h>

int main() {
	int x, y;
	int *px, *py;

	x = 10;
	y = 20;

	printf("Valor de x: %d \n", x);
	printf("Valor de y: %d \n", y);

	px = &x;
	py = &y;

	printf("Conteudo apontado por px: %d \n", *px);
	printf("Conteudo apontado por py: %d \n", *py);

	*px = 3;
	*py = 5;

	printf("Conteudo apontado por px: %d \n", *px);
	printf("Conteudo apontado por py: %d \n", *py);

	printf("Valor de x: %d \n", x);
	printf("Valor de y: %d \n", y);


//system("pause");
return 0;
}