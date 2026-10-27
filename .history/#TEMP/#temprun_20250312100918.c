#include <stdio.h>
#include "stdlib.h"
#include <iostream>
using namespace std;

typedef int datatype;
#define MAXLEN 10

typedef struct linknode {
    datatype data;
    struct linknode *next;
} LinkNode, *LinkList;

LinkList CreatLinkList() {
    LinkNode *head = NULL, *tail, *p;
    int element;
    while (1) {
        scanf("%d", &element);
        if (element == -1) {
            break;
        }
        p = (LinkNode *)malloc(sizeof(LinkNode));
        p->data = element;
        p->next = NULL;
        if (head == NULL) {
            head = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }
    return head;
}

void ShowLinkList(LinkList L) {
    LinkNode *p;
    p = L;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void DeletLinkList(LinkList L, int start, int fianl) {
    LinkNode *p, *q;
    q = NULL;
    p = L;
    int i = 1, j;
    while (p != NULL) {
        if (i == start) {
            for (j = 0; j < fianl; j++) {
                p = p->next;
            }
            break;
        }
        q = p;
        p = p->next;
        i++;
    }
    if (q == NULL) {
        L = p;

    } else {
        q->next = p;
    }
}
int main() {
    LinkList L;
    int x, y;
    L = CreatLinkList();
    scanf("%d %d", &x, &y);
    DeletLinkList(L, x, y);
    ShowLinkList(L);

    return 1;
}