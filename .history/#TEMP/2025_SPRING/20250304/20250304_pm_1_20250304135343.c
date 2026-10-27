#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList() {
    LinkList list;

    list = (Node*)malloc(sizeof(Node));

    return list;
}

int main() {
    LinkList list1 = CreateList();
}