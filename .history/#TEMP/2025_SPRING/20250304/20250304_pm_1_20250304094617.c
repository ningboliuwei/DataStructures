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
    list = (SeqList*)malloc(sizeof(SeqList));
    list->last = -1;

    return list;
}

int main() {
    SeqList *list1 = CreateList();
}