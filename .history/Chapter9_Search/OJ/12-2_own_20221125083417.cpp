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
}

int main() {
    int array[MAX_COUNT];

    scanf("%d", &array[0]);

    int count = 0;

    // while (array[i] != key) {
    //     i--;
    //     count++;
    // }
    // 对于以上代码，如果不设置监视哨，那么在找一个不存在的元素的情况下，i 就会小于
    // 0，导致下标越界，除非每次都在循环中判断一下 i 是否已经 < 0 了

    // while (array[i] != key) {
    //     i--;
    //     count++;

    //     if (i == -1) {
    //         break;
    //     }
    // }
    // 对于以上代码，才能保证不越界，但是多了一个判断

    while (array[0] != array[i]) {
        i--;
        count++;
    }

    if (i == -1) {
        printf("失败 %d", count - 1);
    } else {
        printf("%d %d", i, count - 1);
    }

    getchar();
    getchar();
}
