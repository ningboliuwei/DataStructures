
#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
} PointType;

typedef struct node {
    int data;
    struct node *next;
} aNode, *aLinkList;

main() {
    PointType p1;
    p1.x = 3;
    p1.y = 5;

    aLinkList l;
    l->data = 3;

    struct node node1;
    struct node *node2;

    node1.data = 3;
    node2->data = 3;
}