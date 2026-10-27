//
// Created by Liu Wei on 2019-10-11.
//
#include "stdio.h"
#include "stdlib.h"

#define MAXLEN 100

typedef int datatype;

typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *CreateList_Seq() {
    SeqList *L = (SeqList *) malloc(sizeof(SeqList));
    L->last = -1;

    return L;
}

int InsList_Seq(SeqList *L, int pos, datatype x) {
    for (int i = L->last; i >= pos; i--) {
        L->data[i + 1] = L->data[i];
    }

    L->data[pos] = x;
    L->last++;

    return 1;
}

int DelList_Seq(SeqList *L, int pos) {
    for (int i = pos; i < L->last; i++) {
        L->data[i] = L->data[i + 1];
    }
    L->last--;
}


int LengthList_Seq(SeqList *L) {
    return L->last + 1;
}

void ShowList_Seq(SeqList *L) {
    for (int i = 0; i <= L->last; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int main() {
    SeqList *list = CreateList_Seq();

//    printf("%d\n", list->last);
//    printf("%d\n", LengthList_Seq(list));

    InsList_Seq(list, 0, 1);
    InsList_Seq(list, 0, 2);
    InsList_Seq(list, 0, 3);

    ShowList_Seq(list);
    DelList_Seq(list, 0);
    ShowList_Seq(list);

    getchar();
}
