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
    // 注意这里下标从 0 开始
    for (int i = 0; i < length; i++) {
        scanf("%d", &number);
        array[i] = number;
    }
}

void ShowArray(int array[], int length) {
    // 注意这里下标从 0 开始
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void QuickSort(int array[], int &low, int &high, int &pivotPos) {
    if (low < high) {
        // Partition(array, low, high, pivotPos);
        // QuickSort(array, low, pivotPos - 1, pivotPos);
        // QuickSort(array, pivotPos + 1, high, pivotPos);
    }
}

void Partition(int array[], int &low, int &high) {
    int pivotValue = array[pivotPos];

    if ()
}

int main() {
    int count = 0;
    int array[MAX_LENGTH];

    scanf("%d\n", &count);
    InputArray(array, count);
    QuickSort(array, count);

    getchar();
    getchar();
}