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

#include <stdio.h>
#include <math.h>
#define MAX_LENGTH 20

typedef struct HeapNodeType {
    int element;
    int leftChild;
    int rightChild;
} HeapNode;

typedef struct HeapType {
    HeapNode nodes[MAX_LENGTH];
} Heap;

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

void HeapAdjust(int array[], int start, int end) {
}

Heap GetInitialHeap() {
    Heap heap;
    heap.nodes[0].element = 97;
    heap.nodes[1].element = 38;
    heap.nodes[2].element = 27;
    heap.nodes[3].element = 49;
    heap.nodes[4].element = 76;
    heap.nodes[5].element = 65;
    heap.nodes[6].element = 49;
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
