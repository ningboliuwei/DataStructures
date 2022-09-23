//
// Created by Liu Wei on 2018/9/29.
// 顺序表应用——合并顺序表(2)

#include <iostream>
#include <stdio.h>

// using namespace std;

#define MAXLEN 15

typedef int datatype;
typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *CreatList() {
    // @@1
    SeqList *list = new SeqList();
    list->last = -1;

    return list;
    // @@1
}

int InsList_Seq(SeqList *Lq, int i, datatype x) {
    // @@2
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
    // @@2
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
    // @@4
}

int GetData(SeqList *h, int i) {
    // @@7
    return h->data[i];
    // @@7
}

void Union(SeqList *a, SeqList *b, SeqList *c) {
    // @@5
    int nextBeginning = 0;

    for (int i = 0; i <= a->last; i++) {
        for (int j = nextBeginning; j <= b->last; j++) {
            if (b->data[j] < a->data[i]) {
                c->last++;
                c->data[c->last] = b->data[j];
                nextBeginning = j + 1;
            } else if (b->data[j] == a->data[i]) {
                // 防止重复
                nextBeginning++;
            }
        }

        c->last++;
        c->data[c->last] = a->data[i];
    }

    for (int i = nextBeginning; i <= b->last; i++) {
        int flagFoundSame = 0;
        for (int j = 0; j <= a->last; j++) {
            if (b->data[i] == a->data[j]) {
                flagFoundSame = 1;
                break;
            }
        }
        if (!flagFoundSame) {
            c->last++;
            c->data[c->last] = b->data[i];
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

    Union(a, b, c);
    ShowList_Seq(c);

    getchar();
}
