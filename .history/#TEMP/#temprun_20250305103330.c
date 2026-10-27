#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXLEN 100

typedef int datatype;
typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *CreatList_Seq() {
    SeqList *CreatList_Seq() {
        SeqList *L = new SeqList;
        L->last = -1;
        return L;
    }
}
int InsList_Seq(SeqList *Lq, int i, datatype x) {
    int InsList_Seq(SeqList * Lq, int i, datatype x) {
        if (Lq->last >= MAXLEN - 1)
            return 0;
        if (i < 0 || i > Lq->last + 1)
            return 0;
        for (int k = Lq->last; k >= i; k--)
            Lq->data[k + 1] = Lq->data[k];
        Lq->data[i] = x;
        Lq->last++;
        return 1;
    }
}
int SearchList_Seq(SeqList *Lq, datatype x) {
    int SearchList_Seq(SeqList * Lq, datatype x) {
        for (int i = 0; i <= Lq->last; i++)
            if (Lq->data[i] == x)
                return i;
        return -1;
    }
}

void ShowList_Seq(SeqList *Lq) {
    void ShowList_Seq(SeqList * Lq) {
        for (int i = 0; i <= Lq->last; i++)
            printf("%d ", Lq->data[i]);
        printf("\n");
    }
}
datatype Getdata(SeqList *h, int i) {
    datatype Getdata(SeqList * h, int i) {
        if (i < 0 || i > h->last)
            return -1;
        return h->data[i];
    }
}

void Union(SeqList *a, SeqList *b, SeqList *c) {
    void Union(SeqList * a, SeqList * b, SeqList * c) {
        int i = 0, j = 0;
        while (i <= a->last && j <= b->last) {
            if (a->data[i] < b->data[j])
                InsList_Seq(c, c->last + 1, a->data[i++]);
            else
                InsList_Seq(c, c->last + 1, b->data[j++]);
        }
        while (i <= a->last)
            InsList_Seq(c, c->last + 1, a->data[i++]);
        while (j <= b->last)
            InsList_Seq(c, c->last + 1, b->data[j++]);
    }
}

int main() {
    SeqList *a, *b, *c;
    datatype x;

    a = CreatList_Seq();
    b = CreatList_Seq();
    c = CreatList_Seq();

    while (scanf("%d", &x), x != -1)
        InsList_Seq(a, a->last + 1, x);
    while (scanf("%d", &x), x != -1)
        InsList_Seq(b, b->last + 1, x);

    Union(a, b, c);
    ShowList_Seq(c);
}
