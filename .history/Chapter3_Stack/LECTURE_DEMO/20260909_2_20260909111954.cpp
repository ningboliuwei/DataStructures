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

void Change(SeqList L) {
    L.data[0] = 4;

    printf("%h", &L);
}

int main() {
    SeqList L = CreateList_Seq();
    // L.data[0] = 10;
    // Change(L);
    printf("%h", &L);
}
