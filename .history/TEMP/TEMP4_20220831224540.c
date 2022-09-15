#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[5] = {'a', 'b', 'c', 'd', 'e'};

    for (int i = 0; i < 5; i++) {
        printf("%x", &array[i]);
    }

    int x;
    scanf("%d", &x);
}