#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10

typedef int datatype;

typedef struct {
    datatype data[MAX_LENGTH];
    int last;
} SeqList;

SeqList CreateList_Seq() {
    SeqList list;
    list.last = -1;

    return list;
}

int main() {
    SeqList list = CreateList_Seq();

    list.data[0] = 10;
}