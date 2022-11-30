//
// Created by 慰 on 2018/12/13.
// 问题 E: 【数据结构10-5】快速排序
// ID: 1670
// OJ PASSED
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

// low, high 不能用引用，否则会在本趟排序过程中被改变（除非用别的变量做备份）
void Partition(int array[], int low, int high, int &pivotPos) {
    int pivotValue = array[low];

    while (low < high) {
        while (array[high] > pivotValue) {
            high--;
        }
        int x = array[low];
        array[low] = array[high];
        array[high] = x;

        while (array[low] < pivotValue) {
            low++;
        }
        x = array[low];
        array[low] = array[high];
        array[high] = x;
    }

    pivotPos = low;
    array[pivotPos] = pivotValue;
}

void QuickSort(int array[], int low, int high, int &pivotPos) {
    if (low < high) {
        Partition(array, low, high, pivotPos);
        QuickSort(array, low, pivotPos - 1, pivotPos);
        QuickSort(array, pivotPos + 1, high, pivotPos);
    }
}

int main() {
    int count = 0;
    int array[MAX_LENGTH];
    int pivotPos = 0;

    scanf("%d\n", &count);
    InputArray(array, count);

    QuickSort(array, 0, count - 1, pivotPos);
    ShowArray(array, count);

    getchar();
    getchar();
}
