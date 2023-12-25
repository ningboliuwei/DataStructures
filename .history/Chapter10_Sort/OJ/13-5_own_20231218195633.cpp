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
    // 和插入排序中的 InputArray() 函数一样
    int number;
    // 注意这里下标从 0 开始
    for (int i = 0; i < length; i++) {
        scanf("%d", &number);
        array[i] = number;
    }
}

void ShowArray(int array[], int length) {
    // 和插入排序中的 ShowArray() 函数一样
    // 注意这里下标从 0 开始
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// low, high 不能用引用，否则会在本趟排序过程中被改变（除非用别的变量做备份）
void Partition(int array[], int low, int high, int &pivotPos) {
    // 声明变量 pivotValue，用于存放支点的值（即序列中第一个元素的值）
    int pivotValue = array[low];
    // 只要 low < high， 没有相遇，就一直循环
    while (low < high) {
        // 从右向左扫描，找到第一个比支点小的元素
        while (array[high] > pivotValue) {
            high--;
        }
        // 将 low 指向的元素与 high 指向的元素交换
        int x = array[low];
        array[low] = array[high];
        array[high] = x;
        // 交换后，从左向右扫描，找到第一个比支点大的元素
        while (array[low] < pivotValue) {
            low++;
        }
        x = array[low];
        array[low] = array[high];
        array[high] = x;
    }
    // 将支点放到最终停止的位置上
    pivotPos = low;
    array[pivotPos] = pivotValue;
}

void QuickSort(int array[], int low, int high, int &pivotPos) {
    if (low < high) {
        ShowArray(array, 9);
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

    getchar();
    getchar();
}