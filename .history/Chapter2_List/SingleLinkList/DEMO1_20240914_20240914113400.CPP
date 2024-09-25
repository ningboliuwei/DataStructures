#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct {
    datatype data[100];
    int last;
} SeqListType;

SeqListType *CreateList() {
    SeqListType *list;
    list = (SeqListType *)malloc(sizeof(SeqListType));
    list->last = -1;
    return list;
}

int SearchList(SeqListType *list, datatype x) {
    int i = 0;
    while (list->data[i] != x) {
        i++;
    }

    if (i < list->last)
        return i;
    else
        return -1;
}

int main() {
    int x;

    SeqListType *list;
    list = CreateList();
    list->data[0] = 6;
    list->data[1] = 1;
    list->data[2] = 8;
    list->data[3] = 3;
    list->data[4] = 5;
    list->last = 4;

    int pos = SearchList(list, 8);
    printf("The position of 8 is %d\n", pos);

    scanf("%d", &x);
}
