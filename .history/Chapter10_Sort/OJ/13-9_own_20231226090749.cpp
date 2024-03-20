//
// Created by 慰 on 2023/12/26.
// 问题 I: 【C语言1】【实验】【数组】选择排序（二）
// ID: 1815
// 输入数据：
// 8 2
// 8 7 6 5 4 3 2 1
// 输出结果：
// 1 7 6 5 4 3 2 8
// 1 2 6 5 4 3 7 8

#include <stdio.h>
#include <math.h>
#define MAX_LENGTH 20

// 输入所有的数据并放置到数组中
void InputArray(int array[], int length) {
    int number;
    // 注意这里下标从 0 开始
    for (int i = 0; i < length; i++) {
        scanf("%d", &number);
        array[i] = number;
    }
}

// 输出数组中的所有数据
void ShowArray(int array[], int length) {
    // 注意这里下标从 0 开始
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// 简单选择排序
void SelectionSort(int array[], int length) {
    // 进行 N 趟排序，每趟排序都把第 i 小的元素放在第 i 个位置上（即该趟中第一个待排序元素所在的位置）
    for (int i = 0; i < length; i++) {
        // 声明一个名为 minPos 的变量，用来存储当前最小元素的位置（在遍历所有待排序元素，前假设的第一个元素最小）
        int minPos = i;
        // 遍历所有待排序元素，找到最小的那个，并将其位置存储到 minPos 中
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[minPos]) {
                minPos = j;
            }
        }
        // 如果 minPos 不等于 i，说明找到的最小元素的位置不是之前假设的那个，需要将其与整个序列中的第 i 个元素交换
        if (minPos != i) {
            int temp = array[minPos];
            array[minPos] = array[i];
            array[i] = temp;
            // 交换后输出当前数组
            ShowArray(array, length);
        }
    }
}

int main() {
    // 声明变量 count，用来存储元素个数
    int count = 0;
    // 声明数组 array，用来存储输入的元素
    int array[MAX_LENGTH];

    scanf("%d\n", &count);
    InputArray(array, count);

    SelectionSort(array, count);

    getchar();
    getchar();
}
