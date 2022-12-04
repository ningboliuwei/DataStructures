//
// Created by 慰 on 2018/12/13.
// 问题 F: 【数据结构10-7】堆排序
// ID: 1662
// 输入数据：
// 5
// 3 8 6 2 7
// 输出数据：
// 7 3 6 2 8
// 6 3 2 7 8
// 3 2 6 7 8
// 2 3 6 7 8
// HeapAdjust 测试数据
// 7
// 97 38 27 49 76 65 49
// 8
// 49 38 65 97 76 13 27 49

#include <stdio.h>
#include <math.h>
#define MAX_LENGTH 20

void ShowArray(int array[], int length) {
    // 注意这里下标从 1 开始
    for (int i = 1; i <= length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// 除了根结点，其他结点都符合《堆》的要求的前提
void HeapAdjust(int array[], int start, int end) {
    int p = start;

    while (p * 2 < end && (array[p] > array[p * 2] || array[p] > array[p * 2 + 1])) {
        int temp = 0;
        if (array[p * 2] < array[p * 2 + 1]) {
            // 若左孩子比较小，则当前 p
            // 指向的结点（就是不符合小根堆要求的结点）与左孩子进行交换，否则和有孩子进行交换
            temp = array[p * 2];
            array[p * 2] = array[p];
            array[p] = temp;
            p = p * 2;
        } else {
            temp = array[p * 2 + 1];
            array[p * 2 + 1] = array[p];
            array[p] = temp;
            p = p * 2 + 1;
        }
    }
}

void CreateHeap(int array[], int length) {
    int number;
    // 注意这里下标从 1 开始
    for (int i = 1; i <= length; i++) {
        scanf("%d", &number);
        array[i] = number;
        HeapSort(array, )
    }
}

void HeapSort(int array[], int length) {
    for (int i = 0; i < length; i++) {
        HeapAdjust(array, 1, length - i);
    }
}

int main() {
    int array[MAX_LENGTH];
    int targetArray[MAX_LENGTH];
    int count = 0;

    scanf("%d", &count);
    CreateHeap(array, count);

    getchar();
    getchar();
}
