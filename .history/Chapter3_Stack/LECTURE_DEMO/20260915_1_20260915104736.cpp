#include <stdio.h>
#include <stdlib.h>

// 带头结点头插法
typedef char datatype;

typedef struct LinkNode {
    datatype data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList_F() {
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;

    LinkList H = node;

    datatype c;
    scanf("%c", &c);
    getchar();
    while (c != 'x') {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->next = H->next;
        newNode->data = c;

        H->next = newNode;
        scanf("%c", &c);
        getchar();
    }

    return H;
}

int main() {
    LinkList L = CreateList_F();
}