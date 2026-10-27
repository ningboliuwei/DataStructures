#include <stdio.h>
#include <stdlib.h>
// 带头结点
typedef char datatype;

typedef struct LinkNode {
    datatype data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList() {
    LinkList head = NULL;
    Node *tail = NULL;

    datatype c;
    scanf("%c", &c);
    getchar();

    while (c != 'x') {
        Node *s = (Node *)malloc(sizeof(Node));
        s->data = c;
        s->next = NULL;

        // 插入一个空表
        if (head == NULL) {
            head = s;
        } else {
            tail->next = s;
        }

        tail = s;

        scanf("%c", &c);
        getchar();
    }

    return head;
}

int main() {
    LinkList L = CreateList();
}