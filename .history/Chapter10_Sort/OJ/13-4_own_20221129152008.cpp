//
// Created by 慰 on 2018/12/13.
// 问题 B: 【数据结构10-4】改进的冒泡排序
// ID: 1659
// 输入数据：
// 6
// 3 45 82 36 100 12

#include <stdio.h>
#include <math.h>
#define MAX_LENGTH 20

void InputArray(int array[], int length) {
    int number;
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

void BubbleSort(int array[], int length) {
    for (int i = 0; i < length - 1; i++) {
        // 本趟排序交换的次数，若某趟没交换过，则直接退出 for 循环
        int swapCount = 0;

        for (int j = length - i; j > 0; j--) {
            // 需要《交换》的元素从最后一个开始，倒数第2个，倒数第3个……直到第1个为止
            // 内层循环的作用是将当前参与排序的元素通过不断交换，放在该放的位置上
            if (array[j] < array[j - 1]) {
                array[0] = array[j];
                array[j] = array[j - 1];
                array[j - 1] = array[0];
                swapCount++;
            }
        }
        if (swapCount == 0) {
            break;
        }
        ShowArray(array, length);
    }
}

int main() {
    int count = 0;
    int array[MAX_LENGTH];

    scanf("%d\n", &count);
    InputArray(array, count);
    BubbleSort(array, count);

    getchar();
    getchar();
}
