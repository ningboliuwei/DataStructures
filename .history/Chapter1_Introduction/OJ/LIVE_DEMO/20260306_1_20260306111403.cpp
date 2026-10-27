#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

typedef int datatype;

typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *CreateList_Seq() {
    SeqList *Lq = new SeqList;

    Lq->last = -1;
    return Lq;
}

int Inst_Seq(SeqList *Lq, int i, datatype x) {
    for (int j = Lq->last; j >= i - 1; j--) {
        Lq->data[j + 1] = Lq->data[j];
    }

    Lq->data[i - 1] = x;
    Lq->last++;

    return 1;
}

int main() {
    SeqList *L = CreateList_Seq();
    L->data[0] = 6;
    L->data[1] = 1;
    L->data[2] = 8;
    L->data[3] = 3;
    L->data[4] = 5;

    L->last = 4;

    Inst_Seq(L, 6, 7);
}