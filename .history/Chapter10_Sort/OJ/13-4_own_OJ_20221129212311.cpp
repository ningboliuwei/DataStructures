//
// Created by 慰 on 2018/12/13.
// 问题 B: 【数据结构10-4】改进的冒泡排序
// ID: 1659
// 输入数据：
// 6
// 3 45 82 36 100 12
// 11
// 40 24 30 13 39 19 15 34 27 28 1

#include <stdio.h>
#include <math.h>
#define MAX_LENGTH 20

void InputArray(int array[], int length) {
    int number;
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

void BubbleSort(int array[], int length) {
    for (int i = 0; i < length - 1; i++) {
        // 本趟排序交换的次数，若某趟没交换过，则直接退出 for 循环
        int swapCount = 0;

        for (int j = 1; j <= length; j++) {
            if (array[j] < array[j + 1]) {
                array[0] = array[j + 1];
                array[j + 1] = array[j];
                array[j] = array[0];
                swapCount++;
            }
        }
        if (swapCount == 0) {
            break;
        }
        ShowArray(array, length);
    }
}

int main() {
    int count = 0;
    int array[MAX_LENGTH];

    scanf("%d\n", &count);
    InputArray(array, count);
    BubbleSort(array, count);

    getchar();
    getchar();
}
