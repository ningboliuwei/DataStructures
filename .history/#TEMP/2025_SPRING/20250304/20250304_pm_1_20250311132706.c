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

    while (1) {
        int element;
        scanf("%d", &element);

        if (element == -1) {
            break;
        }

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = element;
        newNode->next = list->next;
        list->next = newNode;
    }

    return list;
}

int main() {
    LinkList list1 = CreateList();
}