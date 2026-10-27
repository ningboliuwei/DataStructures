#include <stdio.h>
#include <stdlib.h>
// 不带头结点头插法
typedef char datatype;

typedef struct LinkNode {
    datatype data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList_F() {
    LinkList H = NULL;

    datatype c;
    scanf("%c", &c);
    getchar();
    while (c != 'x') {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->next = H;
        newNode->data = c;
        H = newNode;

        scanf("%c", &c);
        getchar();
    }

    return H;
}

int main() {
    LinkList L = CreateList_F();
}