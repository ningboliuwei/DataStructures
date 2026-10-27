#include <stdio.h>
#include <stdlib.h>
// 带头结点尾插法
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

int InsertList_F(LinkList L, int i, datatype x) {
    Node *p = L;
    int j = 0;

    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p == NULL || j > i - 1) {
        return 0;
    } else {
        Node *s = (Node *)malloc(sizeof(Node));
        s->data = x;
        s->next = p->next;
        p->next = s;
    }

    return 1;
}

int main() {
    LinkList L = CreateList_F();
    InsertList_F(L, 3, 9);
}