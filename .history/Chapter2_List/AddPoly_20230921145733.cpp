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

// Add Poly Pa and Pb, and store the result in Pa
void AddPolyn(PolyLinkNode &Pa, PolyLinkNode &Pb) {
    PolyLinkNode *ha, *hb, *qa, *qb;
    Item a, b, sum;
    ha = Pa.next;
    hb = Pb.next;
    qa = ha;
    qb = hb;
    while (qa && qb) {
        a = qa->data;
        b = qb->data;
        switch (a.exp - b.exp) {
        case -1: qa = qa->next; break;
        case 0:
            sum.coef = a.coef + b.coef;
            sum.exp = a.exp;
            if (sum.coef != 0) {
                qa->data = sum;
                ha = qa;
            } else {
                ha->next = qa->next;
                free(qa);
            }
            hb = qb->next;
            free(qb);
            qb = hb;
            qa = ha->next;
            break;
        case 1:
            hb = qb->next;
            qb->next = qa;
            ha->next = qb;
            qb = hb;
            ha = ha->next;
            break;
        } // switch
    }     // while
    if (!qa)
        ha->next = qb;
    free(hb);
} // AddPolyn

int main() {
    PolyLinkNode Pa, Pb;
    Pa.next = NULL;
    Pb.next = NULL;
    PolyLinkNode *p = &Pa;
    PolyLinkNode *q = &Pb;
    for (int i = 0; i < 3; i++) {
        PolyLinkNode *s = (PolyLinkNode *)malloc(sizeof(PolyLinkNode));
        s->data.coef = i;
        s->data.exp = i;
        s->next = NULL;
        p->next = s;
        p = s;
    }
    for (int i = 0; i < 3; i++) {
        PolyLinkNode *s = (PolyLinkNode *)malloc(sizeof(PolyLinkNode));
        s->data.coef = i;
        s->data.exp = i;
        s->next = NULL;
        q->next = s;
        q = s;
    }
    AddPolyn(Pa, Pb);
    PolyLinkNode *t = Pa.next;
    while (t) {
        printf("%lf %d\n", t->data.coef, t->data.exp);
        t = t->next;
    }
}

// void AddPolyn(PolyLinkNode &Pa, PolyLinkNode &Pb) {
//     ha = GetHead(Pa);
//     hb = GetHead(Pb);
//     qa = NextPos(Pa, ha);
//     qb = NextPos(Pb, hb);
//     while (qa && qb) {
//         a = GetCurElem(qa);
//         b = GetCurElem(qb);
//         switch (*cmp(a, b)) {
//         case -1: qa = NextPos(Pa, qa); break;
//         case 0:
//             sum = a.coef + b.coef;
//             if (sum != 0) {
//                 SetCurElem(qa, sum);
//                 ha = qa;
//             } else {
//                 DelFirst(ha, qa);
//                 FreeNode(qa);
//             }
//             DelFirst(hb, qb);
//             FreeNode(qb);
//             qb = NextPos(pb, hb);
//             qa = NextPos(Pa, ha);
//             break;
//         case 1:
//             DelFirst(hb, qb);
//             InsFirst(ha, qb);
//             qb = NextPos(pb, hb);
//             ha = NextPos(pa, ha);
//             break;
//         } // switch  }//while
//         if (!ListEmpty(pb))
//             Append(pa, qb);
//         FreeNose(hb);
//     } // AddPolyn
