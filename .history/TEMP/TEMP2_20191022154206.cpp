#include <stdio.h>
#include "stdlib.h"

#define MAXLEN 100

typedef int datatype;
typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *CreatList() {
    SeqList *Lq;
    Lq = (SeqList *)malloc(sizeof(SeqList));
    Lq->last = -1;
    return Lq;
}

int InsList_Seq(SeqList *Lq, int i, datatype x) {
    Lq->data[i] = x;
    return 0;
}

int SearchList_Seq(SeqList *Lq, datatype x) {
    int i;
    for (i = 0; i <= Lq->last; i++) {
        if (Lq->data[i] == x)
            return 1;
        else
            return 0;
    }
}

void ShowList_Seq(SeqList *Lq) {
    int i;
    for (i = 0; i <= Lq->last; i++)
        printf("%d", Lq->data[i]);
}

datatype Getdata(SeqList *h, int i) {
    return h->data[i];
}

void common(SeqList *a, SeqList *b, SeqList *c) {
    int i, k = 0, t;
    for (i = 0; i <= a->last; i++) {
        t = Getdata(a, i);
        if (SearchList_Seq(b, t) == 1) {
            InsList_Seq(c, k, t);
            k++;
        }
    }
}

int main() {
    SeqList *a, *b, *c;
    datatype x;

    a = CreatList();
    b = CreatList();
    c = CreatList();
    while (1) {
        scanf("%d", &x);
        if (x == -1)
            break;
        a->data[a->last] = x;
        a->last++;
    }
    while (1) {
        scanf("%d", &x);
        if (x == -1)
            break;
        b->data[b->last] = x;
        b->last++;
    }

    common(a, b, c);
    ShowList_Seq(c);
}