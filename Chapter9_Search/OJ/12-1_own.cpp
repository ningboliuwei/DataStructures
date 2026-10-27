#include <stdio.h>
#include <stdlib.h>

// 问题 A: 【数据结构9-1】顺序查找
// ID：1652
// OJ PASSED
// 输入：
// 11 12 13 14 15 16 17 -1
// 14
// 输出：
// 4 4
// 2025-12-11 修改代码顺序，使其更符合逻辑

#define MAX_COUNT 10

int main() {
    int array[MAX_COUNT];
    int number = 0;
    int i = 1;

    while (true) {
        scanf("%d", &number);

        if (number == -1) {
            break;
        }

        array[i] = number;
        i++;
    }

    scanf("%d", &array[0]);

    int count = 1;

    i--;
    while (array[0] != array[i]) {
        i--;
        count++;
    }

    if (i == 0) {
        printf("失败 %d", count);
    } else {
        printf("%d %d", i, count);
    }

    getchar();
    getchar();
}
