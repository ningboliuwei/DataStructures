//
// Created by 慰 on 2018/12/13.
// 问题 B: 【数据结构10-4】改进的冒泡排序
// ID: 1659
// OJ PASSED
// 输入数据：
// 6
// 3 45 82 36 100 12
// 11
// 40 24 30 13 39 19 15 34 27 28 1

#include <stdio.h>
#include <math.h>
#define MAX_LENGTH 20

void InputArray(int array[], int length) {
    // 和插入排序中的 InputArray() 函数一样
    int number;
    for (int i = 1; i <= length; i++) {
        scanf("%d", &number);
        array[i] = number;
    }
}

void ShowArray(int array[], int length) {
    // 和插入排序中的 ShowArray() 函数一样
    for (int i = 1; i <= length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void BubbleSort(int array[], int length) {
    // 声明变量 resultOutput，用于记录是否输出过结果（避免出现因为一次都没有交换导致没有任何输出的情况）
    bool resultOutput = false;
    // 循环 length 次（length 为元素个数）
    for (int i = 1; i < length; i++) {
        int swapCount = 0;

        for (int j = 1; j <= length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                array[0] = array[j + 1];
                array[j + 1] = array[j];
                array[j] = array[0];
                swapCount++;
            }
        }

        // 如果本趟排序没有任何交换操作，则说明已经完全排好序，不需要再进行接下来的比较
        if (swapCount == 0) {
            break;
        }

        ShowArray(array, length);
        resultOutput = true;
    }
    // 为了通过 OJ  [1 2 3 4 5 6 7] 测试数据的补丁（至少输出一次）
    if (resultOutput == false) {
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
