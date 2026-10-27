#include <stdio.h>
#include <stdlib.h>

typedef char datatype;

typedef struct LinkNode {
    datatype data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList_F() {
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;

    LinkList H = node;
    Node *tail = H;

    datatype c;
    scanf("%c", &c);
    getchar();
    while (c != 'x') {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->next = NULL;
        newNode->data = c;
        tail->next = newNode;
        tail = newNode;

        scanf("%c", &c);
        getchar();
    }

    return H;
}

int main() {
    LinkList L = CreateList_F();
}