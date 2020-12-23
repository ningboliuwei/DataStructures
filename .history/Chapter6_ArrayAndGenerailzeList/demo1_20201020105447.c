
#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[15][10][5];

    for (int k = 0; k < 15; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                array[k][i][j] = k * (10 * 5) + i * 5 + j + 1;
            }
        }
    }
    for (int k = 0; k < 15; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%d(%d,%d,%d)\n", array[k][i][j], k, i, j);
            }
        }
    }

    int x;
    scanf("%d", &x);
}
