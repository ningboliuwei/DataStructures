#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
#define MAXLEN 100

typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *CreatSeqList() {
    SeqList *L = (SeqList *)malloc(sizeof(SeqList));
    if (L == NULL) {
        exit(1);
    }
    L->last = -1;
    return L;
}

void ShowSeqList(SeqList *L) {
    if (L->last == -1) {
        return;
    }
    for (int i = 0; i <= L->last; i++) {
        printf("%d", L->data[i]);
    }
    printf("\n");
}

int main() {
    SeqList *L;
    L = CreatSeqList();
    ShowSeqList(L);
    return 1;
}