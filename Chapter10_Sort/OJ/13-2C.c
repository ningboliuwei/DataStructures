//
// Created by 慰 on 2018/12/13.
// 问题 B: 【数据结构10-2】二分插入排序
// 输入数据：8 30 13 70 85 39 42 6 20

#include <stdio.h>

int main() {
  int count = 0;

  scanf("%d", &count);
  int array[count];

  for (int i = 0; i < count; i++) {
    scanf("%d", &array[i]);

    int j;

    int high = i;
    int low = 0;
    int mid = (high + low) / 2;

    while (low <= high) {
      // 每次都要修改 mid 的值
      mid = (high + low) / 2;
      if (array[i] < array[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    for (j = i; j > mid; j--) {
      array[j] = array[j - 1];
    }

    array[mid] = array[i];

    // 显示当前趟排序所有元素
    for (int k = 0; k < i; k++) {
      printf("%d ", array[k]);
    }
    printf("\n");
    getchar();
    getchar();
  }
}
