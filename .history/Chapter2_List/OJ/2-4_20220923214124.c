//
// Created by Liu Wei on 2018/9/29.
// 【2-4】顺序表应用——删除
// OJ PASSED

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
#define MAXLEN 100

typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

// @@1
int DelList(SeqList *list, int pos, int length) {
    if (list->last == -1) {
        return 0;
    }

    if (pos < 1 || pos > list->last + 1) {
        return 0;
    }

    if (length < 0 || length > list->last + 2 - pos) {
        return 0;
    }

    for (int i = pos + length - 1; i <= list->last; i++) {
        list->data[i - length] = list->data[i];
    }

    list->last = list->last - length;

    return 1;
}

void ShowList_Seq(SeqList *list) {
    for (int i = 0; i <= list->last; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

SeqList *CreatList() {
    SeqList *list = (SeqList *)malloc(sizeof(SeqList));
    list->last = -1;

    int value = 0;
    while (scanf("%d", &value) && value != -1) {
        list->last++;
        list->data[list->last] = value;
    }

    return list;
}

// @@1
int main() {
    SeqList *L;
    int pos, len;
    L = CreatList();
    scanf("%d %d", &pos, &len);
    if (DelList(L, pos, len) == 0)
        printf("删除失败\n");
    ShowList_Seq(L);
    return 0;
}