
#include <stdio.h>
#include <stdlib.h>

int *GetMatrix() { return array; }

int main() {
    int array[10][5];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            array[i][j] = i * 10 + j;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d, ", array[i][j]);
        }
    }
}
