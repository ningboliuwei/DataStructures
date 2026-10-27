#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct LinkNode {
    datatype data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList_F() {
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;

    LinkList H = node;
}

int main() {
    LinkList L = CreateList_F();
}