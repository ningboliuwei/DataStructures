#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

typedef int datatype;

typedef struct {
    datatype data[MAX_LEN];
    int last;
} SeqList;

SeqList *CreateList() {
    SeqList *Lq;

    return Lq;
}
int main() {
    SeqList *list1 = CreateList();
    list1->data[0] = 3;

    return 0;
}
