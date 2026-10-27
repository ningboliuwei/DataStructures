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

    datatype c;
    scanf("%c", &c);
    getchar();

    while (c != 'x') {
        Node *s = (Node *)malloc(sizeof(Node));
        s->data = c;
        s->next = NULL;

        // 空表
        if (head == NULL) {
        } else {
            s->next = head;
        }

        head = s;

        scanf("%c", &c);
        getchar();
    }

    return head;
}

int main() {
    LinkList L = CreateList();
}