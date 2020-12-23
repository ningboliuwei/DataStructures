#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *creatlink() {
    node *head, *p, *tail;
    int x;
    head = (node *)malloc(sizeof(node));
    head->next = NULL;
    tail = head;
    while (1) {
        scanf("%d", &x);
        if (x == -1)
            break;
        p = (node *)malloc(sizeof(node));
        p->data = x;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
    return head;
}
node *del(node *head, int i, int n) {
    node *p = head, *s;
    int t = 0;
    if (head == NULL)
        return head;
    if (i != 1) {
        while (p->next) {
            t++;
            if (t == i)
                break;
            p = p->next;
        }
        if (p->next == NULL)
            return head;
    }
    s = p->next;
    for (i = 0; i < n - 1; i++) {
        s = s->next;
    }
    p->next = s->next;
    free(s);
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
void freelist(node *phead) {
    node *p = phead;
    while (p != NULL) {
        phead = phead->next;
        free(p);
        p = phead;
    }
}
int main() {
    node *head;
    int x, y;
    head = creatlink();
    scanf("%d %d", &x, &y);
    del(head, x, y);
    traverse(head);
    freelist(head);
}
