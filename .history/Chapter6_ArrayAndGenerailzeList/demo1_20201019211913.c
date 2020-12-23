
#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[10][5];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            array[i][j] = i * 10 + j;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    int x;
    scanf("%d", &x);
}
