//
// Created by 慰 on 2018/12/13.
// 问题 A: 【数据结构10-1】直接插入排序
// 输入数据：7 49 38 65 97 76 13 27

#include <stdio.h>

#define MAX_LENGTH 20

void InputArray(int array[], int length) {
    int number;
    // 带监视哨，array[0] 空着，用于存放当前要插入的元素

    for (int i = 1; i <= length; i++) {
        scanf("%d", &number);
        array[i] = number;
    }
}

void InsertSort(int array[], int length) {
    // 第一个（array[1]）默认已经是属于有序序列了，从第2个（array[2]）开始排序）
    for (int i = 2; i <= length; i++) {}
}

void ShowArray(int array[], int length) {
}

int main() {
    int count = 0;
    int array[MAX_LENGTH];

    scanf("%d\n", &count);
    int array[count];

    InputArray(array, count);

    getchar();
    getchar();
}
