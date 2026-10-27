#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 10

typedef int datatype;

typedef struct {
    datatype data[MAX_LEN];
    int last;
} SeqList;

SeqList *CreateList() {
    SeqList *Lq = (SeqList *)malloc(sizeof(SeqList));
    Lq->last = -1;

    return Lq;
}
int main() {
    SeqList *list1 = CreateList();

    return 0;
}
