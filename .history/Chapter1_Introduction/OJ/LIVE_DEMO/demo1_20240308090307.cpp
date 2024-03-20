#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType {
    int key;
    int value;
} node;

void main() {
    // struct nodeType x;
    // node y;

    struct nodeType {
        int key;
        int value;
    } z;
    z.key = 1;
    z.value = 2;

    printf("%d", z.key);
}