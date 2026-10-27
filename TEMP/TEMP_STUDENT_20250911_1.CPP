#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} node;

node *creatlink() {
    struct Node *head = (struct Node *)malloc(sizeof(Node));
    head->next = NULL;
    int x;
    while (scanf("%d", &x) == 1 && x != -1) {
        struct Node *p = (struct Node *)malloc(sizeof(Node));
        p->data = x;
        struct Node *pre = head, *q = head->next;
        while (q && q->data < x) {
            pre = q;
            q = q->next;
        }
        p->next = pre->next;
        pre->next = p;
    }

    return head;
}
void traverse(node *head) {
    node *p;
    if (head == NULL)
        return;
    p = head->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main() {
    node *head;
    head = creatlink();
    traverse(head);
}