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
    L->last = -1;
    int x;
    while (1) {
        scanf("%d", &x);
        if (x == -1)
            break;
        L->data[++L->last] = x;
    }
    return L;
}

void ShowSeqList(SeqList *L) {
    int i;
    for (i = 0; i <= L->last; ++i) {
        printf("%d ", L->data[i]);
    }
}

int main() {
    printf("%d", 123);
    SeqList *L;
    L = CreatSeqList();
    ShowSeqList(L);
    return 1;
}