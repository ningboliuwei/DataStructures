//
// Created by 慰 on 2018/12/13.
// 问题 B: 【数据结构10-2】二分插入排序
// ID: 1658
// 输入数据：
// 10
// 49 38 65 97 76 13 27 48 55 4

#include <stdio.h>
#include <math.h>
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
    printf("\n");
}

void ShellSort(int array[], int length) {
    // 第一个（array[1]）默认已经是属于有序序列了，从第2个（array[2]）开始排序）

    for (int i = 2; i <= length; i++) {
        int low = 1;
        int high = i - 1;

        array[0] = array[i];
        // 不断缩小 array[0] 应该插入的范围
        while (low <= high) {
            int mid = floor((low + high) / 2);

            if (array[0] < array[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // high 最终停留在刚刚好比 array[0] 小一个的位置上
        // 从这个位置的后一个位置开始到有序序列最后一个所有的元素往后移动一个（注意要倒着来）
        for (int j = i - 1; j >= high + 1; --j) {
            array[j + 1] = array[j];
        }
        // 空出来的位置放本次参与排序的元素
        array[high + 1] = array[0];

        ShowArray(array, length);
    }
}

int main() {
    int count = 0;
    int array[MAX_LENGTH];

    scanf("%d\n", &count);
    InputArray(array, count);
    BiInsertSort(array, count);

    getchar();
    getchar();
}
