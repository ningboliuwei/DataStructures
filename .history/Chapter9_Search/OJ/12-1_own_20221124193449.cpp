#include <stdio.h>
#include <stdlib.h>

// 问题 A: 【数据结构9-1】顺序查找
// ID：1652
// 输入：
// 11 12 13 14 15 16 17 -1
// 14
// 输出：
// 4 4

#define MAX_COUNT 100

int Input(int array[]) {
}

int Search(int array[], int start, int key) {
}

int main() {
    int array[MAX_COUNT];
    int number = 0;
    int i = 0;

    while (number != -1) {
        scanf("%d", &number);
        array[i] = number;
        i++;
    }

    int key;
    scanf("%d", &key);

    while (array[i] != key) {
        i--;
    }

    return i;

    getchar();
    getchar();
}
