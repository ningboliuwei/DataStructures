//
// Created by Liu Wei on 2018/12/17.
// 问题 E:【数据结构10-5】快速排序
// 输入数据： 8 49 38 65 97 76 13 27 50
// 输入数据2： 9 49 38 65 97 76 65 13 27 50

#include <stdio.h>

// 显示数组中所有元素
void ShowArray(int array[], int count) {
    for (int k = 0; k < count; k++) {
        printf("%d ", array[k]);
    }
    printf("\n");
}

void QuickSort(int array[], int lower, int upper, int count) {
    int left = lower;
    int right = upper;
    int pivot = array[lower];

    while (left < right && array[left] != array[right]) {
        while (array[right] > pivot) {
            right--;
        }

        while (left < right && array[left] < pivot) {
            left++;
        }

        if (array[left] != array[right]) {
            printf("left: %d right: %d\n", left, right);
            printf("pivot = %d, swap %d & %d:\n", pivot, array[left], array[right]);

            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;

            printf("after swap:\n");
            ShowArray(array, count);
        }
    }

    if (lower < right - 1) {
        QuickSort(array, lower, right - 1, count);
    }

    if (right + 1 < upper) {
        QuickSort(array, right + 1, upper, count);
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
    QuickSort(array, lower, upper, count);
    printf("end");
}







