//
// Created by Liu Wei on 2018/9/29.
// 【2-4】顺序表应用——删除
// OJ PASSED
// #1897

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
#define MAXLEN 100

typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

// 删除顺序表中的元素
int DelList(SeqList *list, int pos, int length) {
    // 如果顺序表为空，返回 0
    if (list->last == -1) {
        return 0;
    }

    // 如果删除位置不合法，返回 0
    if (pos < 1 || pos > list->last + 1) {
        return 0;
    }

    // 如果删除长度不合法，返回 0
    if (length < 0 || length > list->last + 2 - pos) {
        return 0;
    }

    // 将删除位置后面的元素向前移动
    for (int i = pos + length - 1; i <= list->last; i++) {
        list->data[i - length] = list->data[i];
    }

    // 更新最后一个元素的下标
    list->last -= length;

    // 返回删除的元素个数
    return length;
}

int main() {
    // 创建顺序表
    SeqList list;
    list.last = -1;

    // 向顺序表中添加元素
    for (int i = 0; i < 10; i++) {
        list.data[i] = i + 1;
        list.last++;
    }

    // 删除顺序表中的元素
    int del_num = DelList(&list, 3, 4);

    // 输出删除的元素个数和删除后的顺序表
    printf("del_num=%d\n", del_num);
    for (int i = 0; i <= list.last; i++) {
        printf("%d ", list.data[i]);
    }
    printf("\n");

    return 0;
}