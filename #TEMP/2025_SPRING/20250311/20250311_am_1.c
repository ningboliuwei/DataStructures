#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList() {
    LinkList head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < 4; i++) {
        Node *s = (Node *)malloc(sizeof(Node));

        int element;
        scanf("%d", &element);
        s->data = element;
        s->next = NULL;

        if (head == NULL) {
            head = s;
            tail = s;
        } else {
            tail->next = s;
            tail = s;
        }
    }
}

int main() {
    LinkList list1 = CreateList();
}
