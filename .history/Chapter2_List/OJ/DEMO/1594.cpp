#include <stdio.h>
#include "stdlib.h"
#include <iostream>
using namespace std;

typedef int datatype;
#define MAXLEN @ #2

typedef struct linknode {
    datatype data;
    struct linknode *next;
} LinkNode, *LinkList;

LinkList CreatLinkList() {
    // @ @1
    LinkList list = new LinkNode;
    list->next = NULL;
    LinkNode *tail = list;

    int value;
    scanf("%d", &value);

    while (value != -1) {
        LinkNode *newNode = new LinkNode;
        newNode->data = value;
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
        scanf("%d", &value);
    }

    return list;
    // @ @1
}

void ShowLinkList(LinkList L) {
    // @ @2
    LinkNode *p = L->next;

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    // @ @2
}

int main() {
    LinkList L;
    L = CreatLinkList();
    ShowLinkList(L);

    getchar();
    getchar();
    return 1;
}