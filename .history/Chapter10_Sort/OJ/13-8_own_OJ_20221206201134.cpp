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

void MergeSort(int array1[], int array2[], int length1, int length2) {
    int pos1;
    int pos2;
    int pos3;

    int array3[MAX_LENGTH];

    while (pos1 < length1 || pos2 < length2) {
        if (array1[pos1] < array2[pos2]) {
            array3[pos3] = array1[pos1];
            pos1++;
        } else {
            array3[pos3] = array2[pos2];
            pos2++;
        }
        pos3++;
    }
}

int main() {
    int array[MAX_LENGTH];

    int array1[5] = {2, 9, 5, 6, 8};
    int array2[6] = {1, 3, 4, 7, 10, 11};

    MergeSort(array1, array2, 5, 6);

    getchar();
    getchar();
}
