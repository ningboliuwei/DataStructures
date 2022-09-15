//
// Created by 慰 on 2018/9/24.
//【2-1】顺序表创建

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
#define MAXLEN 10

typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *CreatSeqList() {

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
}

void ShowSeqList(SeqList *L) {

    for (int i = 0; i <= L->last; i++) {
        printf("%d ", L->data[i]);
    }
}

int main() {
    SeqList *L;
    L = CreatSeqList();
    ShowSeqList(L);
    return 1;
}
