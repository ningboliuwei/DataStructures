#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList() {
    LinkList head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    Node *tail = head;

    for (int i = 0; i < 4; i++) {
        int element;
        scanf("%d", &element);

        Node *s = (Node *)malloc(sizeof(Node));
        s->data = element;
        s->next = NULL;

        tail->next = s;
        tail = s;
    }

    return head;
}

int main() {
    LinkList list1 = CreateList();
}