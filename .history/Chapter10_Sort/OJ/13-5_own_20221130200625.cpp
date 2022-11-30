//
// Created by 慰 on 2018/12/13.
// 问题 E: 【数据结构10-5】快速排序
// ID: 1670
// 输入数据：
// 8
// 49 38 65 97 76 13 27 50

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
    int totalSwapCount = 0;

    for (int i = 0; i < length; i++) {
        // 本趟排序交换的次数，若某趟没交换过，则直接退出 for 循环
        int swapCount = 0;

        for (int j = 1; j <= length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                array[0] = array[j + 1];
                array[j + 1] = array[j];
                array[j] = array[0];
                swapCount++;
            }
        }
        totalSwapCount += swapCount;

        if (swapCount == 0) {
            break;
        }

        ShowArray(array, length);
    }
    // 为了通过 OJ  [1 2 3 4 5 6 7] 测试数据的补丁（至少输出一次）
    if (totalSwapCount == 0) {
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
