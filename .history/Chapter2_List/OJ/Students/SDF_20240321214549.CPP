#include <stdio.h>
#include <stdlib.h>
#include "iostream"

typedef struct Node {
    int m;
    int n;
    struct Node *next;
} Node;

Node *createPolyTerm() {
    int m, n;
    Node *head = NULL, *p, *q;
    while (1) {
        scanf("%d%d", &m, &n);
        if (m == 0 && n == 0)
            break;
        p = new Node;
        p->m = m;
        p->n = n;
        p->next = NULL;
        if (head == NULL) {
            head = p;
            q = p;
        } else {
            q->next = p;
            q = p;
        }
    }
    return head;
}
Node *AddPolyNomial(Node *A, Node *B) {
    Node *head = NULL, *term1 = A, *term2 = B, *p, *x;
    while (term1 != NULL && term2 != NULL) {
        p = new Node;
        if (head == NULL) {
            head = p;
            x = p;
        } else {
            x->next = p;
            x = p;
        }
        if (term1->n > term2->n) {
            p->m = term1->m;
            p->n = term1->n;
            term1 = term1->next;
        } else if (term1->n == term2->n) {
            p->m = term1->m + term2->m;
            p->n = term1->n;
            term1 = term1->next;
            term2 = term2->next;
        } else {
            p->m = term2->m;
            p->n = term2->n;
            term2 = term2->next;
        }
        p->next = NULL;
    }
    if (p == NULL) {
        if (A == NULL) {
            head = term2;
        } else {
            p->next = term2;
        }
    } else if (x == NULL) {
        if (B == NULL) {
            head = term1;
        } else {
            p->next = term1;
        }
    }
    while (term1 != NULL) {
        p = new Node;
        x->next = p;
        x = p;
        p->m = term1->m;
        p->n = term1->n;
        p->next = NULL;
        term1 = term1->next;
    }
    while (term2 != NULL) {
        p = new Node;
        x->next = p;
        x = p;
        p->m = term2->m;
        p->n = term2->n;
        p->next = NULL;
        term2 = term2->next;
    }
    return head;
}
void trave(Node *L) {
    Node *p = L;
    while (p != NULL) {
        if (p->m != 0)
            printf("%d %d\n", p->m, p->n);
        p = p->next;
    }
}
void del(Node *L) {
    Node *p;
    while (L != NULL) {
        p = L;
        L = L->next;

        free(p);
    }
}
int main() {
    Node *a, *b, *c;
    a = createPolyTerm();
    b = createPolyTerm();
    c = AddPolyNomial(a, b);
    trave(c);
    del(c);
    getchar();
    getchar();
    getchar();
    return 1;
}