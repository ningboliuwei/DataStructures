//
// Created by 慰 on 2018/12/13.
// 问题 G: 【数据结构10-8】堆排序
// ID: 1663
// 输入数据：
// 5 7 4 3 8 1 6 9 2 -1
// 5 7 3 4 1 8 6 9 2
// 3 4 5 7 1 6 8 9 2
// 1 3 4 5 6 7 8 9 2
// 1 2 3 4 5 6 7 8 9
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

void MergeSort(int array1[], int array2[], int pos1, int pos2) {
    pos1 = 0;
    pos2 = 0;
}

int main() {
    int array[MAX_LENGTH];
    int count = 0;

    scanf("%d", &count);
    InputArray(array, count);
    MergeSort(array, count);

    getchar();
    getchar();
}
