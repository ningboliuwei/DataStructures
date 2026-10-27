#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef int datatype;

typedef struct {
    datatype data[MAX];
    int last;
} SeqList;

SeqList *CreateList_Seq() {
    SeqList *Lq;
    Lq = (SeqList *)malloc(sizeof(SeqList));
    Lq->last = -1;

    return Lq;
}

void main() {
    SeqList *L = CreateList_Seq();
}