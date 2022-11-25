#include <stdio.h>
#include <stdlib.h>

// 问题 B: 【数据结构9-2】二分查找
// ID：1653
// 输入：
// 11 12 13 14 15 16 17 -1
// 14
// 输出：
// 4 1

#define MAX_COUNT 100

int InputArray(int array[]) {
    int number = 0;
    int i = 0;

    while (number != -1) {
        scanf("%d", &number);
        array[i] = number;
        i++;
    }

    return i;
}

int BiSearch(int key, int low, int high) {
}

int main() {
    int array[MAX_COUNT];
    int key = 0;

    int length = InputArray(array);

    scanf("%d", &key);
    BiSearch(key, 0, length);

    if (i == -1) {
        printf("失败 %d", count - 1);
    } else {
        printf("%d %d", i, count - 1);
    }

    getchar();
    getchar();
}
