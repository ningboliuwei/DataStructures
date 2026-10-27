#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList() {
    LinkList head;
    head = NULL;

    int x;

    while (1) {
        scanf("%d", &x);
        getchar();

        if (x == -1) {
            break;
        }

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = NULL;

        Node *tail;

        if (head == NULL) {
            head = newNode;

        } else {
            tail->next = newNode;
        }

        tail = newNode;
    }
}

int main() {
    LinkList list = CreateList();
}