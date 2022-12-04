//
// Created by 慰 on 2018/12/13.
// 问题 F: 【数据结构10-7】堆排序
// ID: 1662
// 输入数据：
// 5
// 3 8 6 2 7
// 输出数据：
// 7 3 6 2 8
// 6 3 2 7 8
// 3 2 6 7 8
// 2 3 6 7 8
// HeapAdjust 测试数据
// 7
// 97 38 27 49 76 65 49

#include <stdio.h>
#include <math.h>
#define MAX_LENGTH 20

void InputArray(int array[], int length) {
    int number;
    // 注意这里下标从 1 开始
    for (int i = 1; i <= length; i++) {
        scanf("%d", &number);
        array[i] = number;
    }
}

void ShowArray(int array[], int length) {
    // 注意这里下标从 1 开始
    for (int i = 1; i <= length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void HeapAdjust(int array[], int start, int end) {
    int p = start;

    while (p * 2 < end && (array[p] > array[p * 2] || array[p] > array[p * 2 + 1])) {
        int temp = 0;
        if (array[p * 2] < array[p * 2 + 1]) {
            // 若左孩子比较小，则当前 p
            // 指向的结点（就是不符合小根堆要求的结点）与左孩子进行交换，否则和有孩子进行交换
            temp = array[p * 2];
            array[p * 2] = array[p];
            array[p] = temp;
            p = p * 2;
        } else {
            temp = array[p * 2 + 1];
            array[p * 2 + 1] = array[p];
            array[p] = temp;
            p = p * 2 + 1;
        }
    }
}

void HeapSort(int array[], int length, int targetArray[]) {
    for (int i = 0; i <= length; i++) {
        HeapAdjust(array, 1, length - i);
        // 把根放入目标数组（排好序的数组）第 i 个
        targetArray[i + 1] = array[1];
        // 注意，第一个元素下标为 1
        int temp = array[1];
        array[1] = array[length - i];
        array[length - i] = temp;
    }
}

int main() {
    int array[MAX_LENGTH];
    int targetArray[MAX_LENGTH];
    int count = 0;

    scanf("%d", &count);
    InputArray(array, count);
    HeapSort(array, count, targetArray);
    ShowArray(targetArray, count);

    getchar();
    getchar();
}
