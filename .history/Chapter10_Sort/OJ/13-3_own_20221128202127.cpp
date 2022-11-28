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
    for (int i = 1; i <= length; i++) {
        scanf("%d", &number);
        array[i] = number;
    }
}

void ShowArray(int array[], int length) {
    for (int i = 1; i <= length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void ShellSort(int array[], int length) {
    // 第一个 gap 值为长度（元素个数）的一半
    int gap = length / 2;

    while (gap > 0) {
        for (int i = gap + 1; i <= length; i++) {
            int j = i - gap;

            while (j > 0) {
                if (array[j] < array[j - gap]) {
                    // 先把当前要排序的元素放入变量 currentKey 中
                    int currentKey = array[j];
                    // 有序序列中的最后一个元素（往前一个个看当前要排序的元素插入位置在哪里）
                    int pos = i - 1;

                    while (array[0] < array[pos]) {
                        // 只要当前需要排序的元素比当前元素小，则把当前元素往后移动一个（直到找到插入位置，有点像当前元素去找应该《挤进去》的位置）
                        array[pos + 1] = array[pos];
                        // 当前要和当前需要排序的元素
                        pos--;
                    }
                    array[pos + 1] = array[0];
                }
            }
        }
        // 每次 gap 减半
        gap = gap / 2;
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
