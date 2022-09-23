#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *tailinsert();
void traverse(struct node *head);
void destroy(struct node *head);
void X(struct node *head, int i, int n);

main() {
    struct node *head;
    head = tailinsert();
    int i, n;
    scanf("%d %d", &i, &n);
    X(head, i, n);
    traverse(head);
    destroy(head);
    getchar();
}

struct node *tailinsert() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;

    struct node *s;
    s = (struct node *)malloc(sizeof(struct node));
    s->next = NULL;
    scanf("%d", &(s->data));

    struct node *p;
    p = head;
    while (s->data != -1) {
        p->next = s;
        p = s;
        s = (struct node *)malloc(sizeof(struct node));
        s->next = NULL;
        scanf("%d", &(s->data));
    }
    return head;
}

void traverse(struct node *head) {
    struct node *p;
    p = head->next;
    while (p->next != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d ", p->data);
}

void destroy(struct node *head) {
    struct node *p;
    while (head != NULL) {
        p = head;
        head = head->next;
        free(p);
    }
}

void X(struct node *head, int i, int n) {
    int ii = 0, nn = 0;
    struct node *p, *q;
    p = (struct node *)malloc(sizeof(struct node));
    q = (struct node *)malloc(sizeof(struct node));
    p = head;
    while (p->next != NULL && ii < i - 2) {
        p = p->next;
        ii++;
    }
    q = p;
    while (p->next != NULL && nn < n + 2) {
        q = q->next;
        nn++;
    }
    p->next = q;
}
