#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double coef; //系数
    int exp;     //指数
} Item;

typedef struct ItemNode {
    Item data;
    struct ItemNode *next;
} PolyLinkNode;

// 编写程序，使其能够实现基于Item类型的多项式相加，用链表存储多项式
PolyLinkNode *AddPoly(PolyLinkNode *poly1, PolyLinkNode *poly2) {
    PolyLinkNode *p1 = poly1->next;
    PolyLinkNode *p2 = poly2->next;
    PolyLinkNode *poly = (PolyLinkNode *)malloc(sizeof(PolyLinkNode));
    PolyLinkNode *p = poly;
    while (p1 && p2) {
        if (p1->data.exp > p2->data.exp) {
            p->next = p1;
            p1 = p1->next;
        } else if (p1->data.exp < p2->data.exp) {
            p->next = p2;
            p2 = p2->next;
        } else {
            p->next = p1;
            p1->data.coef += p2->data.coef;
            p1 = p1->next;
            p2 = p2->next;
        }
        p = p->next;
    }
    if (p1) {
        p->next = p1;
    }
    if (p2) {
        p->next = p2;
    }
    return poly;
}

// 实现main函数，实现 x^2 + 2x + 1 和 2x^3 + 3x^2 + 4x + 5 的相加
int main() {
    PolyLinkNode *poly1 = (PolyLinkNode *)malloc(sizeof(PolyLinkNode));
    PolyLinkNode *poly2 = (PolyLinkNode *)malloc(sizeof(PolyLinkNode));
    PolyLinkNode *p1 = poly1;
    PolyLinkNode *p2 = poly2;
    Item item1[] = {{1, 2}, {2, 1}, {1, 0}};
    Item item2[] = {{2, 3}, {3, 2}, {4, 1}, {5, 0}};
    for (int i = 0; i < 3; i++) {
        PolyLinkNode *node = (PolyLinkNode *)malloc(sizeof(PolyLinkNode));
        node->data = item1[i];
        p1->next = node;
        p1 = p1->next;
    }
    for (int i = 0; i < 4; i++) {
        PolyLinkNode *node = (PolyLinkNode *)malloc(sizeof(PolyLinkNode));
        node->data = item2[i];
        p2->next = node;
        p2 = p2->next;
    }
    PolyLinkNode *poly = AddPoly(poly1, poly2);
    PolyLinkNode *p = poly->next;
    while (p) {
        printf("%dx^%d ", p->data.coef, p->data.exp);
        p = p->next;
    }
    printf("\n");
    return 0;
}
