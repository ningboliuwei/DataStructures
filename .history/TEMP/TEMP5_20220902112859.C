#include <stdio.h>
#include <stdlib.h>

int main() {
    char x = 'a';

    // printf("%d", sizeof(x));

    int array[5] = {'a', 'b', 'c', 'd', 'e'};

    for (int i = 0; i < 5; i++) {
        printf("%x\n", &array[i]);
    }

    int a;
    scanf("%d", &a);
}