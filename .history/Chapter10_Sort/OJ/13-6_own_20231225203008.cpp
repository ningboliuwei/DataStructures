//
// Created by 慰 on 2018/12/13.
// 问题 F: 【数据结构10-6】简单选择排序
// ID: 1661
// 输入数据：
// 7
// 49 38 65 97 76 13 27

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
    // 进行 N 趟排序，每趟排序都把第 i 小的元素放在第 i 个位置上（即本趟中第一个待排序元素所在的位置）
    for (int i = 0; i < length; i++) {
        // 声明一个名为 minPos 的变量，用来存储当前最小元素的位置（在遍历所有待排序元素，前假设的第一个元素最小）
        int minPos = i;
        // 遍历所有待排序元素，找到最小的那个，并将其位置存储到 minPos 中
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[minPos]) {
                minPos = j;
            }
        }
        // 如果 minPos 不等于 i，说明找到了比第 i 个元素更小的元素，将其与第 i 个元素交换
        if (minPos != i) {
            int temp = array[minPos];
            array[minPos] = array[i];
            array[i] = temp;

            ShowArray(array, length);
        }
    }
}

int main() {
    int count = 0;
    int array[MAX_LENGTH];
    int pivotPos = 0;

    scanf("%d\n", &count);
    InputArray(array, count);

    SelectionSort(array, count);

    getchar();
    getchar();
}
