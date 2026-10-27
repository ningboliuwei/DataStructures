#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList() {
    LinkList list;

    list = (Node *)malloc(sizeof(Node));
    list->next = NULL;

    int element1;
    scanf("%d", &element1);

    for (int i = 0; i < 4; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = element1;
        newNode->next = NULL;
    }

    return list;
}

int main() {
    LinkList list1 = CreateList();
}