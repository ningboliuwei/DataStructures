//
// Created by 慰 on 2018/9/24.
//【2-1】顺序表创建

#include <stdio.h>
#include <stdlib.h>

// @#1 int
typedef int datatype;
// @#2 10
#define MAXLEN 10

typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *CreatSeqList() {
    // @@1
    SeqList *list = (SeqList *)malloc(sizeof(SeqList));
    list->last = -1;

    int value = 0;
    scanf("%d", &value);

    while (value != -1) {
        list->last++;
        list->data[list->last] = value;
        scanf("%d ", &value);
    }

    return list;
    // @@1
}

void ShowSeqList(SeqList *L) {
    // @@2
    for (int i = 0; i <= L->last; i++) {
        printf("%d ", L->data[i]);
    }
    // @@2
}

int main() {
    SeqList *L;
    L = CreatSeqList();
    ShowSeqList(L);
    return 1;
}
