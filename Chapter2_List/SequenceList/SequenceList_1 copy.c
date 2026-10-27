//
// Created by Liu Wei on 2018/9/6.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 20

typedef struct {
    int data[MAX_LENGTH];
    int last;
} SeqList;

SeqList *CreateList_Seq() {
    SeqList *list = (SeqList *)malloc(sizeof(SeqList));
    // 空表时，list->last 设为 -1
    list->last = -1;

    return list;
}

int InsList_Seq(SeqList *list, int pos, int newElement) {
    int index;

    // 当前线性表已满，不允许插入
    if (list->last == MAX_LENGTH - 1) {
        return 0;
    }
    // 判断插入位置（pos）是否合法
    if (pos < 1 || pos > list->last + 2) {
        return 0;
    }

    for (index = list->last; index >= pos - 1; index--) {
        list->data[index + 1] = list->data[index];
    }

    list->data[pos - 1] = newElement;
    list->last++;

    return 1;
}

int DelList_Seq(SeqList *list, int pos) {
    int index = 0;

    // 空表，不允许删除
    if (list->last == -1) {
        return 0;
    }
    // 判断删除位置（pos）是否合法
    if (pos < 1 || pos > list->last + 2) {
        return 0;
    }

    for (index = pos - 1; index < list->last; index++) {
        list->data[index] = list->data[index + 1];
    }

    list->last--;

    return 1;
}

// 得到顺序表的长度
int LengthList_Seq(SeqList *list) {
    return list->last + 1;
}

//显示带头结点的顺序表元素
void ShowList_Seq(SeqList *list) {
    for (int i = 0; i <= list->last; i++) {
        printf("%d ", list->data[i]);
    }
}

// 有问题的查找版本
int SearchListByElement_Seq(SeqList *list, int element) {
    int i = 0;

    while (list->data[i] != element) {
        i++;
    }

    if (i < list->last) {
        return i;
    } else {
        return -1;
    }
}

int main() {
    SeqList *list = CreateList_Seq();
    int data = 0;

    while (1) {
        printf("Input a number, 0 to exit.");
        scanf("%d", &data);

        if (data != 0) {
            // 注意下一行的 last + 2，也就是在当前最后一个元素的后面位置插入
            // InsList_Seq(list, list->last + 2, data);
            InsList_Seq(list, 1, data);
        } else {
            break;
        }
    }

    printf("\n");
    printf("The elements of the sequence list:");
    ShowList_Seq(list);
    printf("\n");

    printf("\n");
    printf("Input a element you want to search.");
    printf("\n");

    int pos = 0;
    int element = 0;
    scanf("%d", &element);
    pos = SearchListByElement_Seq(list, element);

    printf("\n");
    printf("The found position is %d", pos);
}