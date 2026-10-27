#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} node;

node *creatlink() {
    node *head = NULL;
    int c;
    node *p, *q;
    head = (node *)malloc(sizeof(node));
    head->next = NULL;
    while (1) {
        scanf("%d", &c);
        if (c == -1)
            break;

        //申请结点空间
        p = (node *)malloc(sizeof(node));

        //初始化结点数据域
        p->next = NULL;
        p->data = c;
        if (head->next == NULL) {
            head->next = p;
        } else {
            q->next = p;
        }
        q = p;
    }
    return head;
}
int traverse(node *head, int x, int k) {
    node *p = head, *q;
    int t;
    p = p->next;
    while (p) {
        p = p->next;
        t++;
    }
    if (x + k + 1 > t)
        return 0;

    p = head;
    int i;
    for (i = 0; i < x - 1; i++)
        p = p->next;

    q = p->next;
    for (i = 0; i < k; i++) {
        p->next = q->next;
        q = q->next;
    }

    p = head->next;

    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main() {
    node *head;
    int i, k;
    head = creatlink();
    scanf("%d%d", &i, &k);
    traverse(head, i, k);
}