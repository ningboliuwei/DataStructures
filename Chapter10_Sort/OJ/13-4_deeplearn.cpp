//
// Created by 慰 on 2018/12/13.
// 问题 D: 【数据结构10-4】改进的冒泡排序
// 输入数据：6 3 45 82 36 100 12

#include <stdio.h>

int main() {
    int count = 0;

    scanf("%d", &count);
    int array[count];

    for (int i = 0; i < count; i++) {
        int number;
        scanf("%d", &number);

        array[i] = number;
    }

    int notSortedCount = count;
    int pos;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < notSortedCount - 1; j++) {
            if (array[j] > array[j + 1]) {
                printf("swap %d %d,", array[j], array[j+1]);
                // 显示当前趟排序所有元素
                ShowArray(array, count);

                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }

    }
}

void ShowArray(int array[], int length){
    // 显示当前趟排序所有元素
    for (int k = 0; k < length; k++) {
        printf("%d ", array[k]);
    }
    printf("\n");
}