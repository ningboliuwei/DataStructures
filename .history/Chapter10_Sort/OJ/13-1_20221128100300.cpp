//
// Created by 慰 on 2018/12/13.
// 问题 A: 【数据结构10-1】直接插入排序
// 输入数据：
// 7
// 49 38 65 97 76 13 27

#include <stdio.h>

#define MAX_LENGTH 20

void InputArray(int array[], int length) {
    int number;
    // 带监视哨，array[0] 空着，用于存放当前要插入的元素

    for (int i = 1; i <= length; i++) {
        scanf("%d", &number);
        array[i] = number;
    }
}

void ShowArray(int array[], int length) {
    for (int i = 1; i <= length; i++) {
        printf("%d ", array[i]);
    }
}

void InsertSort(int array[], int length) {
    // 第一个（array[1]）默认已经是属于有序序列了，从第2个（array[2]）开始排序）
    for (int i = 2; i <= length; i++) {
        // 若当前需要进行排序的这个元素比有序序列中最后一个元素（也就应该是最大的元素要小），说明有必要进行排序
        if (array[i] < array[i - 1]) {
            // 先把当前要排序的元素放入见监视哨中
            array[0] = array[i];
            // 有序序列中的最后一个元素（往前一个个看当前要排序的元素插入位置在哪里）
            int pos = i - 1;

            while (array[0] < array[pos]) {
                // 只要关键字比当前元素小，则把当前元素往后移动一个（直到找到插入位置，有点像当前元素去找应该《挤进去》的位置）
                array[pos + 1] = array[pos];
            }
            array[pos + 1] = array[0];
        }
        ShowArray(array, length);
    }
}

int main() {
    int count = 0;
    int array[MAX_LENGTH];

    scanf("%d\n", &count);
    InputArray(array, count);
    InsertSort(array, count);

    getchar();
    getchar();
}
