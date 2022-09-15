#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, Node2, *LinkList;

int main() {
    LinkList list;

    list = (LinkList)malloc(sizeof(Node));
}