//
// Created by Liu Wei on 2018/12/17.
// 问题 E:【数据结构10-5】快速排序
// 输入数据： 8 49 38 65 97 76 13 27 50

#include <stdio.h>

// 显示数组中所有元素
void ShowArray(int array[], int count) {
    for (int k = 0; k < count; k++) {
        printf("%d ", array[k]);
    }
    printf("\n");
}

void QuickSort(int array[], int lower, int upper) {
    int i = lower;
    int j = upper;
    int pivot = array[lower];

    while (j > i) {
        while (j > i && array[j] > pivot) {
            j--;
        }

        while (i < j && array[i] < pivot) {
            i++;
        }

        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        ShowArray(array, 8);
    }

    if (lower < j - 1) {
        QuickSort(array, lower, j - 1);
    }

    if (j + 1 < upper) {
        QuickSort(array, j + 1, upper);
    }
}


int main() {
    int count = 0;

    scanf("%d", &count);
    int array[count];
    // 输入数组元素
    for (int i = 0; i < count; i++) {
        scanf("%d", &array[i]);
    }
    int lower = 0;
    int upper = count - 1;
    QuickSort(array, lower, upper);
}







