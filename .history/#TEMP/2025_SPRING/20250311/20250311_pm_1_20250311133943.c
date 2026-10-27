#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList() {
    LinkList head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < 1; i++) {
        int element;
        scanf("%d", &element);

        Node* s = (Node*)malloc(sizeof(Node));
        s->data = element;
        s->next = NULL;

        if (head == NULL) { // 意味着当前是空表
            head = s;
        }
        else {
            head->next = s;
        }

        tail = s;
    }

    return head;
}

int main() {
    LinkList list1 = CreateList();
}