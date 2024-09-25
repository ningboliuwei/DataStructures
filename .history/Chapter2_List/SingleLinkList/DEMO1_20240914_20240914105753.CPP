#include <stdio.h>
#include <stdlib.h>


typedef int datatype;

typedef struct {
    datatype data[100];
    int last;
} SeqListType;

SeqListType* CreateList() {
    SeqListType* list;
    list = (SeqListType*)malloc(sizeof(SeqListType));
    list->last = -1;
    return list;
}

void Foo(SeqListType list) {
    printf("in: %x\n", &list);
    list.last = 3;
}

int main() {
    int x;

    SeqListType* list;
    list = CreateList();
    // printf("out: %x\n", &list);

    // printf("before: list.last = %d\n", list.last);
    // Foo(list);
    // printf("after: list.last = %d\n", list.last);

    scanf("%d", &x);
}
