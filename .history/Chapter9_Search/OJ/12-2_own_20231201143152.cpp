#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 问题 B: 【数据结构9-2】二分（折半）查找
// ID：1653
// OJ PASSED
// 输入：
// 11 12 13 14 15 16 17 -1
// 14
// 输出：
// 4 1

#define MAX_COUNT 100
// 声明 InputArray 函数，用于输入所有的元素并保存到通过参数传入的数组中
int InputArray(int array[]) {
    int number = 0;
    int i = 0;
    // 循环输入每个元素，直到输入 -1 为止，并返回元素的个数
    while (number != -1) {
        scanf("%d", &number);
        array[i] = number;
        i++;
    }

    return i - 1;
}
// 声明 BiSearch
// 函数，用于递归地进行二分查找，参数分别为：所有元素所在的数组、要查找的元素、查找范围下界、查找范围上界、比较次数（用于以传参的方式返回值）、元素所在的位置（用于以传参的方式返回值）
void BiSearch(int array[], int key, int low, int high, int &count, int &pos) {
    // low > high 作为递归的结束（当找不到要查找的元素（key）时会导致 low 最终 > high）
    if (low > high) {
        // 将 pos 设置为 -1，表示查找失败
        pos = -1;
        return;
    }
    // mid 的值为下界 low 和上界 high 的平均值取整数部分
    int mid = floor((low + high) / 2);
    // 比较次数加 1
    count++;
    // 如果 mid 指向的元素正好等于要查找的元素，那么直接通过参数 pos 范围该元素的位置（即 mid 指向的位置）
    if (array[mid] == key) {
        pos = mid;
        return;
    } // 如果关键字小于 mid 指向的元素
    else if (key < array[mid]) {
        // 递归查找左半部分，即下界 low 不变，上界 high 变为 mid - 1
        BiSearch(array, key, low, mid - 1, count, pos);
    } // 如果关键字大于 mid 指向的元素
    else {
        // 递归查找右半部分，即下界 low 变为 mid + 1，上界 high 不变
        BiSearch(array, key, mid + 1, high, count, pos);
    }
}

int main() {
    // 声明数组 array，用于保存所有的元素
    int array[MAX_COUNT];
    // 声明变量 count，用于保存查找过程中比较的次数
    int count = 0;
    // 声明变量 pos，用于保存查找到的元素所在的位置
    int pos = 0;
    // 调用 InputArray 函数，输入所有的元素，并返得到元素的个数，保存到 length 变量中
    int length = InputArray(array);
    // 声明变量 key，用于保存查找的值
    int key = 0;
    scanf("%d", &key);
    // 进行二分查找，下界 low 为 0，上界 high 为 length - 1
    BiSearch(array, key, 0, length - 1, count, pos);
    // 如果找不到元素，则输出失败信息，以及比较的次数；否则输出元素所在的位置，以及比较的次数
    if (pos == -1) {
        printf("失败 %d", count);
    } else {
        printf("%d %d", pos + 1, count);
    }

    getchar();
    getchar();
}
