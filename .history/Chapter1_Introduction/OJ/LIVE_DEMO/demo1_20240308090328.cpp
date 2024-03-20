#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType {
    int key;
    int value;
} node;

int main() {
    // struct nodeType x;
    // node y;

    struct nodeType {
        int key;
        int value;
    } z;
    z.key = 1;
    z.value = 2;

    return 0;

    printf("%d", z.key);
}