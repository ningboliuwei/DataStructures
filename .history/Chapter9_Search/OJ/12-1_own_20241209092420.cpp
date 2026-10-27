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

#define MAX_COUNT 10

int main() {
    int array[MAX_COUNT];
    int number = 0;
    int i = 1;

    while (number != -1) {
        scanf("%d", &number);
        array[i] = number;
        i++;
    }

    i--;

    scanf("%d", &array[0]);

    while (array[i] != array[0]) {
        i--;
    }

    if (i != 0) {
        printf("%d %d", i, array[0]);
    } else {
        printf("失败 %d", i);
    }

    getchar();
    getchar();
}
