#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList() {
    LinkList list = (Node *)malloc(sizeof(Node));
    list->next = NULL;

    int element1;
    scanf("%d", &element1);

    Node *newNode1 = (Node *)malloc(sizeof(Node));
    newNode1->data = element1;
    newNode1->next = NULL;

    list->next = newNode1;

    int element2;
    scanf("%d", &element2);

    Node *newNode2 = (Node *)malloc(sizeof(Node));
    newNode2->data = element2;
    newNode2->next = NULL;

    newNode2->next = list->next;
    list->next = newNode2;
}

int main() {
    LinkList list1 = CreateList();
}
