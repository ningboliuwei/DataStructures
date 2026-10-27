#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList() {
    LinkList list = (Node *)malloc(sizeof(Node));
    list->next = NULL;

    for (int i = 0; i < 4; i++) {
        int element;
        scanf("%d", &element);

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = element;
        newNode->next = list->next;
        list->next = newNode;
    }
}

int main() {
    LinkList list1 = CreateList();
}

