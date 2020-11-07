#include <stdlib.h>
#include <stdio.h>

void altera(int *px, int *py) {
    *px += 3;
    *py += 5;
}

int main() {
    int x, y;

    x = 10;
    y = 20;

    printf("X = %d, Y = %d \n", x, y);

    //altera(&x, &y);
    altera(&x, &y);

    printf("X = %d, Y = %d \n", x, y);
return 0;
}
