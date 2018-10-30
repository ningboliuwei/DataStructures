//
// Created by Liu Wei on 2018/10/30.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct link {
    int data;
    struct link *next;
} node;

node *creatlink() {
    node *head, *p, *s;
    int x;
    int z = 1, n = 0;
    head = NULL;
    p = head;
    while (z) {
        scanf("%d", &x);
        if (x != -1) {
            s = (node *) malloc(sizeof(node));
            s->data = x;
            s->next = NULL;
            if (!head) head = s;
            else p->next = s;
            p = s;
            n++;
        } else z = 0;
    }
    return head;
}

void showlist(node *head) {
    node *p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

node *Delete(node *head, int i, int k) {
    node *p, *q;
    int j;
    if (i == 1) {
        for (j = 1; j <= k; j++) {
            p = head;
            head = head->next;
            delete p;
        }
    } else {
        p = head;
        for (j = 1; j <= i - 2; j++) {
            p = p->next;
        }
        for (j = 1; j <= k; j++) {
            q = p->next;
            p->next = q->next;
            delete q;
        }
    }
    return head;
}

int main() {
    node *head, *phead;
    head = (node *) malloc(sizeof(node));
    phead = (node *) malloc(sizeof(node));
    head = NULL;
    phead = NULL;
    int i, k;
    head = creatlink();
    scanf("%d%d", &i, &k);
    phead = Delete(head, i, k);
    showlist(phead);
    scanf("%d", &k);

}