#include <stdio.h>
#include <stdlib.h>
// 带头结点
typedef char datatype;

typedef struct LinkNode {
    datatype data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList() {
    LinkList head;
    // LinkList head = (struct LinkNode *)malloc(sizeof(struct LinkNode));
}

int main() {
    LinkList L = CreateList();
}