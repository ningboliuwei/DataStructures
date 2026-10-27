#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

int main() {
    LinkNode *s1 = (LinkNode *)malloc(sizeof(LinkNode));
    LinkList s2 = (LinkList)malloc(sizeof(Node));

    getchar();
}