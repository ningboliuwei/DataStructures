//
// Created by 慰 on 2018/12/13.
// 问题 A: 【数据结构10-1】直接插入排序
// 输入数据：7 49 38 65 97 76 13 27
#include <stdio.h>

int main() {
    int count = 0;

    scanf("%d", &count);
    int array[count];

    for (int i = 0; i < count; i++) {
        int number;
        scanf("%d", &number);

        int j;

        for (j = i; j > 0; j--) {
            if (array[j - 1] > number) {
                array[j] = array[j - 1];
            } else {
                break;
            }
        }

        array[j] = number;

        // 显示当前趟排序所有元素
        for (int k = 0; k < i; k++) {
            printf("%d ", array[k]);
        }
        printf("\n");
    }
}


