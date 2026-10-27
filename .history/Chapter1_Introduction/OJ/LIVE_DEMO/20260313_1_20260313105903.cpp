#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNodeType *next;
} Node, *LinkList;

LinkList CreateList() {
    LinkList head;

    head = (LinkList)malloc(sizeof(LinkList));
    head->next = NULL;
}

int main() {
    LinkList list = CreateList();
}