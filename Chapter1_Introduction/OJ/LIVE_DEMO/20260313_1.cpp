#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList() {
    LinkList head;

    head = (LinkList)malloc(sizeof(Node));
    head->next = NULL;

    int x;

    while (1) {
        scanf("%d", &x);
        getchar();

        if (x == -1) {
            break;
        } else {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->data = x;
            newNode->next = head->next;
            head->next = newNode;
        }
    }

    return head;
}

int main() {
    LinkList list = CreateList();
}