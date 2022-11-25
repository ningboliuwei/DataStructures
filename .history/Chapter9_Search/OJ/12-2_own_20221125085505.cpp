#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void BiSearch(int array[], int key, int low, int high, int &count, int &pos) {
    int mid = floor((low + high) / 2);
    count++;

    if (array[mid] == key) {
        pos = mid;
    } else if (key < array[mid]) {
        BiSearch(array, key, low, mid - 1, count, pos);
    } else {
        BiSearch(array, key, mid + 1, high, count, pos);
    }
}

int main() {
    int array[MAX_COUNT];
    int key = 0;
    // 比较次数
    int count = 0;
    // 找到的位置
    int pos = 0;

    int length = InputArray(array);

    scanf("%d", &key);
    BiSearch(array, key, 0, length, count, pos);

    if (pos == -1) {
        printf("失败 %d", count);
    } else {
        printf("%d %d", pos + 1, count);
    }

    getchar();
    getchar();
}
