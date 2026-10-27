#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

typedef int datatype;

typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *CreateList() {
    SeqList *list;
    list = (SeqList *)malloc(sizeof(SeqList));

    return list;
}

int main() {
    SeqList *list1 = CreateList();

    list1->data[0] = 5;
    list1->last = 3;
}