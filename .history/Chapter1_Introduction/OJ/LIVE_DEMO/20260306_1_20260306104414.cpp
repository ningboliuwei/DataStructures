#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100

typedef int datatype;

typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *CreateList_Seq() {
    SeqList *Lq;

    Lq->last = -1;
    return Lq;
}

int main() {
    SeqList *L = CreateList_Seq();
}