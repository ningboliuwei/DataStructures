#include <stdio.h>
#include <stdlib.h>

int main() {
    char c = '@';
    int count = 0;

    while (c != '#') {
        scanf("%c", c);
        printf("%c ", c);
        printf("%d", c);
        count++;

        if (count == 8) {
            printf("\n");
            count = 0;
        }
    }

    getchar();
}