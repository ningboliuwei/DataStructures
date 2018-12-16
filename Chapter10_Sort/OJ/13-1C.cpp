//
// Created by 慰 on 2018/12/13.
// 问题 A: 【数据结构10-1】直接插入排序
// 输入数据：7 49 38 65 97 76 13 27
// 先一次性读入所有数据再排序
#include <stdio.h>

void ShowArray(int array[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int count = 0;

    scanf("%d", &count);
    int array[count];

    for (int i = 0; i < count; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = 1; i < count; i++) {
        int j;
        int number = array[i];
        for (j = i; j > 0; j--) {
            if (array[j - 1] > number) {
                array[j] = array[j - 1];
            } else {
                break;
            }
        }
        array[j] = number;
        printf("(%d) ", number);
        ShowArray(array, count);
    }
    printf("finally: ");
    ShowArray(array, count);
}



