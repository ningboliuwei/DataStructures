#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList() {
    LinkList list = (Node *)malloc(sizeof(Node));
    list->next = NULL;

    int element;
    scanf("%d", &element);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;

    list->next = newNode;
}

int main() {
    LinkList list1 = CreateList();
}
