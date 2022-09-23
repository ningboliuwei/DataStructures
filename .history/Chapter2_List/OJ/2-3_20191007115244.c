//
// Created by Liu Wei on 2018/9/29.
// 顺序表应用——查找公共元素(2)

#include <stdio.h>
#include "stdlib.h"
#define MAXLEN 100

typedef int datatype;
typedef struct
{
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *CreatList() {
    SeqList *list = (SeqList *)malloc(sizeof(SeqList));
    list->last = -1;

    return list;
}

int InsList_Seq(SeqList *Lq, int i, datatype x) {
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
}
int SearchList_Seq(SeqList *Lq, datatype x) {
    for (int i = 0; i <= Lq->last; i++) {
        if (Lq->data[i] == x) {
            return i;
        }
    }
    return -1;
}

void ShowList_Seq(SeqList *Lq) {
    for (int i = 0; i <= Lq->last; i++) {
        printf("%d ", Lq->data[i]);
    }
}

datatype Getdata(SeqList *h, int i) {
    return h->data[i];
}

void common(SeqList *a, SeqList *b, SeqList *c) {
    for (int i = 0; i <= a->last; i++) {
        for (int j = 0; j <= b->last; j++) {
            if (a->data[i] == b->data[j]) {
                c->last++;
                c->data[c->last] = a->data[i];
            }
        }
    }
}

int main() {
    SeqList *a, *b, *c;
    datatype x;

    a = CreatList();
    b = CreatList();
    c = CreatList();

    int value = 0;
    while (scanf("%d", &value) && value != -1) {
        InsList_Seq(a, a->last + 1, value);
    }

    while (scanf("%d", &value) && value != -1) {
        InsList_Seq(b, b->last + 1, value);
    }

    common(a, b, c);
    ShowList_Seq(c);
}
