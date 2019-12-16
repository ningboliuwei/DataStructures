//
// Created by 慰 on 2018/12/13.
// 问题 B: 【数据结构10-2】二分插入排序
// 输入数据：8 30 13 70 85 39 42 6 20

#include <stdio.h>
int main() {
    int i, a[50];
    int n, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (i = 2; i <= n; i++) {
        if (a[i] < a[i - 1]) {
            a[0] = a[i];
            j = i - 1;
            while (a[0] < a[j]) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = a[0];
        }
        for (int h = 1; h <= n; h++)
            printf("%d ", a[h]);
        printf("\n");
    }
    getchar();
    getchar();
}
