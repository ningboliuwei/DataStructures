#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList() {
    LinkList list;

    list->data = 5;
}

int main() {
    LinkList list1 = CreateList();
}
