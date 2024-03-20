//
// Created by 慰 on 2018/12/13.
// 问题 G: 【数据结构10-8】归并排序
// ID: 1663
// 输入数据：
// 5 7 4 3 8 1 6 9 2 -1
// 输出数组
// 5
// 7
// 5 7
// 5 7
// 4
// 4 5 7
// 4 5 7
// 3
// 8
// 3 8
// 3 8
// 3 4 5 7 8
// 3 4 5 7 8
// 1
// 6
// 1 6
// 1 6
// 9
// 2
// 2 9
// 2 9
// 1 2 6 9
// 1 2 6 9
// 1 2 3 4 5 6 7 8 9

#include <stdio.h>
#include <math.h>
#define MAX_LENGTH 20

// 输入所有的数据并放置到数组中
int InputArray(int array[]) {
    int number = 0;
    int i = 0;
    while (number != -1) {
        scanf("%d ", &array[i]);
        i++;
    }
    return i;
}

// 输出数组中的所有数据
void pnt(int array[], int lowBound, int upperBound) {
    // 注意这里下标从 1 开始
    for (int i = lowBound; i <= upperBound; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void Merge(int SR[], int TR[], int i, int m, int n) { // 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]
    for (j = m + 1, k = i; i <= m && j <= n; ++k) {   // 将SR中记录由小到大地并入TR
        if (SR[i].key <= SR[j].key)
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }
    if (i <= m)
        TR[k..n] = SR[i..m];
    // 将剩余的SR[i..m]复制到TR
    if (j <= n)
        TR[k..n] = SR[j..n];
    // 将剩余的SR[j..n]复制到TR
} // Merge

void MSort(int SR[], int TR[], int s, int t) { // 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]
    if (s < t) {
        int mid = (s + t) / 2;
        MSort(SR, TR, s, mid);
        pnt(SR, s, mid);
        MSort(SR, TR, mid + 1, t);
        pnt(SR, mid + 1, t);
        Merge(SR, TR, s, mid, t);
        pnt(SR, s, t);
    }
}

int main() {
    int array[MAX_LENGTH];
    InputArray(array);
    // MSort(array1, array2, 6, 5);

    getchar();
    getchar();
}
