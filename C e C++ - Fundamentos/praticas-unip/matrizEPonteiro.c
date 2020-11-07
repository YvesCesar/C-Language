#include <stdio.h>
#include <stdlib.h>

int main() {
    int nums[] = {92, 81, 70, 69, 58};
    for(int d = 0; d < 5; d++) printf(" %d ", nums[d]);

    printf("\n");
    for(int d = 0; d < 5; d++) printf(" %d ", *(nums + d));

    printf("\n");
    for(int d = 0; d < 5; d++) printf(" %d ", &nums[d]);

//system("pause");
return 0;
}
