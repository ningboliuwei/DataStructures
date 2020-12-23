
#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[15][10][5];

    for (int k = 0; k < 15; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                array[k][i][j] = k * (i * 5) + i * 5 + j + 1;
            }
        }
    }
    for (int k = 0; k < 15; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                // printf("%d(%d)\t", array[i][j], &(array[i][j]));
                printf("%d\t", array[k][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    int x;
    scanf("%d", &x);
}
