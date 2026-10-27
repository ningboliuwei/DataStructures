#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10

typedef int datatype;

typedef struct {
    datatype data[MAX_LENGTH];
    int last;
} SeqList;

SeqList *CreateList_Seq() {
    SeqList *list = (SeqList *)malloc(sizeof(SeqList));
    list->last = -1;

    return list;
}

int main() {
    SeqList *L = CreateList_Seq();
    L->data[0] = 5;

    int x;
    scanf("%d", &x);
}
