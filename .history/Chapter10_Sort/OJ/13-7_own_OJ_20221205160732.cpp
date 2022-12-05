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
// 本版本适用于 PPT 上的小根堆
// OJ 上的测试数据
// 输入：
// 5
// 3 8 6 2 7
// 输出：
// 7 3 6 2 8
// 6 3 2 7 8
// 3 2 6 7 8
// 2 3 6 7 8

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

// 除了根结点，其他结点都符合《堆》的要求的前提
void HeapAdjust(int array[], int start, int end) {
    int p = start;

    while (p * 2 <= end && (array[p] < array[p * 2] || array[p] < array[p * 2 + 1])) {
        int temp = 0;
        // p*2+1>end 意为没有右孩子（但左孩子一定有）
        // 此处 <= 目的是：如果左右孩子相同（但比根节点小），则优先和左孩子交换，这样能和草稿纸上（包括 PPT
        // 上过程保持一致）
        // 此版本（FOR OJ）为大根堆
        if (array[p * 2] >= array[p * 2 + 1] || (p * 2 + 1 > end)) {
            // 若左孩子比较小，则当前 p
            // 指向的结点（就是不符合大根堆要求的结点）与左孩子进行交换，否则和右孩子进行交换
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
    for (int i = length / 2; i >= 1; i--) {
        HeapAdjust(array, i, length);
    }
}

void HeapSort(int array[], int length) {
    // 先根据无序的数据建堆
    CreateHeap(array, length);

    for (int i = 1; i < length; i++) {
        // 交换第一个与最后一个
        int temp = array[1];
        array[1] = array[length - i + 1];
        array[length - i + 1] = temp;
        // 因为每次只是输出第一个（其他的还是满足堆的要求），所以符合 HeapAdjust 的前提，不需要跟建堆一样从 n/2
        // 倒数到 1
        HeapAdjust(array, 1, length - i);
        ShowArray(array, length);
    }
}

int main() {
    int array[MAX_LENGTH];
    int count = 0;

    scanf("%d", &count);
    InputArray(array, count);
    HeapSort(array, count);

    getchar();
    getchar();
}
