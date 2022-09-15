#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

int main() {
    LinkList list;

    list = (LinkList)malloc(sizeof(LinkNode));
}