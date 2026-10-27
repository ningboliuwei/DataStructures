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

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = element1;
    newNode->next = NULL;

    list->next = newNode; //插入第一个结点（8）

    int element2;
    scanf("%d", &element2);

    Node *newNode2 = (Node *)malloc(sizeof(Node));
    newNode2->data = element1;
    newNode2->next = list->next;

    list->next = newNode2;
    printf("%d", list->next->data);

    return list;
}

int main() {
    LinkList list1 = CreateList();
}