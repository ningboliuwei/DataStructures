#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, Node2, *LinkList;

int main() {
    LinkList list;
    Node *n1;
    Node2 n2;

    list = (LinkList)malloc(sizeof(Node2));
    n1 = (Node *)malloc(sizeof(Node2));
    // 以上一行为比较极端的情况
    n1->data = 3;
    printf("%d", n1->data);
    getchar();
}