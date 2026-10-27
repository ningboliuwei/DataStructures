#include <stdio.h>
#include <stdlib.h>
// 带头结点尾插法
typedef char datatype;

typedef struct LinkNode {
    datatype data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList_F() {
    LinkList H = NULL;
    Node *tail = NULL;

    datatype c;
    scanf("%c", &c);
    getchar();
    while (c != 'x') {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->next = NULL;
        newNode->data = c;

        if (H == NULL) {
            H = newNode;
            tail = newNode;
        } // 插入前是空表
        else {
            tail->next = newNode;
            tail = newNode;
        } // 插入前不是空表

        scanf("%c", &c);
        getchar();
    }

    return H;
}

int main() {
    LinkList L = CreateList_F();
}