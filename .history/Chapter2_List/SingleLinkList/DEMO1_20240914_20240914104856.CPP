#include <stdio.h>
#include <stdlib.h>


typedef int datatype;

typedef struct {
    datatype data[100];
    int last;
} SeqListType;

SeqListType CreateList() {
    SeqListType list;
    list.last = -1;
    return list;
}

int main() {
    int x;

    SeqListType list;
    list = CreateList();
    printf("list.last = %d\n", list.last);

    scanf("%d", &x);
}
