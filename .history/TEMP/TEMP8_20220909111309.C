#include <stdio.h>
#include <stdlib.h>

struct LinkNode1 {
    int data;
    struct LinkNode1 *next;
} Node1, Node2;

typedef struct LinkNode2 {
    int data;
    struct LinkNode2 *next;
} Node3, Node4;

int main() {
    LinkNode1 n1;
    n1.data = 3;

    LinkNode2 n2;
    n2.data = 3;

    getchar();
}