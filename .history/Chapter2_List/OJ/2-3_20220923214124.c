//
// Created by Liu Wei on 2018/9/29.
// 顺序表应用——查找公共元素(2)
// OJ PASSED

#include "stdlib.h"
#include <stdio.h>

#define MAXLEN 100

typedef int datatype;
typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *CreatList() {
    // @@1
    SeqList *list = (SeqList *)malloc(sizeof(SeqList));
    list->last = -1;

    return list;
    // @@1
}

int InsList_Seq(SeqList *Lq, int i, datatype x) {
    // @@1
    SeqList *p = Lq;
    int index = 0;

    if (Lq->last == MAXLEN - 1) {
        return 0;
    }

    if (i < 0 || i > Lq->last + 1) {
        return 0;
    }

    for (index = Lq->last + 1; index >= i; index--) {
        Lq->data[index] = Lq->data[index - 1];
    }

    Lq->data[i] = x;
    Lq->last++;
    // @@!
}
int SearchList_Seq(SeqList *Lq, datatype x) {
    // @@3
    for (int i = 0; i <= Lq->last; i++) {
        if (Lq->data[i] == x) {
            return i;
        }
    }
    return -1;
    // @@3
}

void ShowList_Seq(SeqList *Lq) {
    // @@4
    for (int i = 0; i <= Lq->last; i++) {
        printf("%d ", Lq->data[i]);
    }
    // @@$
}

datatype GetData(SeqList *h, int i) {
    // @@7
    return h->data[i];
    // @@7
}

void common(SeqList *a, SeqList *b, SeqList *c) {
    // @@5
    for (int i = 0; i <= a->last; i++) {
        for (int j = 0; j <= b->last; j++) {
            if (a->data[i] == b->data[j]) {
                c->last++;
                c->data[c->last] = a->data[i];
            }
        }
    }
    // @@5
}

int main() {
    SeqList *a, *b, *c;
    datatype x;

    a = CreatList();
    b = CreatList();
    c = CreatList();

    // @@6
    int value = 0;
    while (scanf("%d", &value) && value != -1) {
        InsList_Seq(a, a->last + 1, value);
    }

    while (scanf("%d", &value) && value != -1) {
        InsList_Seq(b, b->last + 1, value);
    }
    // @@6

    common(a, b, c);
    ShowList_Seq(c);
}
