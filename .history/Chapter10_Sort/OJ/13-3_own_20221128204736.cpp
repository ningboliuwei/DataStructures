//
// Created by 慰 on 2018/12/13.
// 问题 B: 【数据结构10-2】二分插入排序
// ID: 1658
// 输入数据：
// 10
// 49 38 65 97 76 13 27 48 55 4

#include <stdio.h>
#include <math.h>
#define MAX_LENGTH 20

void InputArray(int array[], int length) {
    int number;
    // 带监视哨，array[0] 空着，用于存放当前要插入的元素
    for (int i = 0; i < length; i++) {
        scanf("%d", &number);
        array[i] = number;
    }
}

void ShowArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void ShellSort(int array[], int length) {
    // 第一个 gap 值为长度（元素个数）的一半
    int gap = length / 2;

    while (gap > 0) {
        for (int i = gap; i < length; i += gap) {
            if (array[i] < array[i - gap]) {
                int j = i - gap;
                int key = array[i];
                while (j >= 0) {
                    if (array[i] > key) {
                        array[i + gap] = array[i];
                        i -= gap;
                    }
                }
                array[i] = key;
            }
        }
        // 每次 gap 减半
        gap = gap / 2;
        ShowArray(array, length);
    }
}

int main() {
    int count = 0;
    int array[MAX_LENGTH];

    scanf("%d\n", &count);
    InputArray(array, count);
    ShellSort(array, count);

    getchar();
    getchar();
}
