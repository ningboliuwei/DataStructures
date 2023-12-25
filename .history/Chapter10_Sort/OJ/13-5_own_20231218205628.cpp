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
// low 为参与快速排序的序列的下界，high 为参与快速排序的序列的上界，pivotPos 为支点（基准值）的位置
// 声明 Partition() 函数，其作用是将序列中的元素分为两部分，左边的元素都比基准值小，右边的元素都比基准值大
void Partition(int array[], int low, int high, int &pivotPos) {
    // 声明变量 pivotValue，用于存放基准值（即序列中第一个元素的值）
    int pivotValue = array[low];
    // 只要 low < high， 没有相遇，就一直循环
    while (low < high) {
        // 将 high 从右向左扫描，找到第一个比基准值小的元素
        while (array[high] > pivotValue) {
            high--;
        }
        // 若在 low 仍然比 high 小的前提下，能够找到比基准值小的元素，则将 low 指向的元素与 high 指向的元素交换
        if (low < high) {
            int x = array[low];
            array[low] = array[high];
            array[high] = x;
        }
        // 交换后，改为将 low 从左向右扫描，找到第一个比基准值大的元素
        while (array[low] < pivotValue) {
            low++;
        }
        // 若在 low 仍然比 high 小的前提下，能够找到比基准值大的元素，则将 low 指向的元素与 high 指向的元素交换
        if (low < high) {
            int x = array[low];
            array[low] = array[high];
            array[high] = x;
        }
    }
    // 将基准值放到最终 low 与 high 相遇的位置上（
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
