#include <stdio.h>
#include <stdlib.h>
// 带头结点
typedef char datatype;

typedef struct LinkNode {
    datatype data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList() {
    LinkList head = (LinkList)malloc(sizeof(Node));
    head->next = NULL;

    datatype c;
    scanf("%c", &c);
    getchar();

    while (c != 'X') {
        Node *s = (Node *)malloc(sizeof(Node));
        s->next = NULL;
        head->next = s;

        scanf("%c", &c);
        getchar();
    }

    return head;
}

int main() {
    LinkList L = CreateList();
}