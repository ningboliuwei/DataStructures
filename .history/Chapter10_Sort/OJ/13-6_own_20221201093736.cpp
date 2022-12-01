//
// Created by 慰 on 2018/12/13.
// 问题 F: 【数据结构10-6】简单选择排序
// ID: 1661
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

void SelectionSort(int array[], int length) {
    for (int i = 0; i < length; i++) {
        int minPos = i;

        for (int j = i; j < length; j++) {
            if (array[j] < array[minPos]) {
                minPos = j;
            }
        }

        int temp = array[minPos];
        array[minPos] = array[i];
        array[i] = temp;

        ShowArray(array, length);
    }
}

int main() {
    int count = 0;
    int array[MAX_LENGTH];
    int pivotPos = 0;

    scanf("%d\n", &count);
    InputArray(array, count);

    SelectionSort(array, 0, count - 1, pivotPos);
    ShowArray(array, count);

    getchar();
    getchar();
}
