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

    return i - 1;
}

void BiSearch(int array[], int key, int low, int high, int &count, int &pos) {
    if (low > high) {
        pos = -1;
        return;
    }

    int mid = floor((low + high) / 2);
    count++;

    if (array[mid] == key) {
        pos = mid;
        return;
    } else if (key < array[mid]) {
        BiSearch(array, key, low, mid - 1, count, pos);
    } else {
        BiSearch(array, key, mid + 1, high, count, pos);
    }
}

int main() {
    // 存放数据的数组
    int array[MAX_COUNT];
    // 比较次数
    int count = 0;
    // 找到的位置
    int pos = 0;
    // 输入的数据长度
    int length = InputArray(array);
    // 要查找的关键字
    int key = 0;
    scanf("%d", &key);

    BiSearch(array, key, 0, length - 1, count, pos);

    if (pos == -1) {
        printf("失败 %d", count);
    } else {
        printf("%d %d", pos + 1, count);
    }

    getchar();
    getchar();
}
